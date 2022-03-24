#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 2

/*
	현재 문제점들 :
		아마 메모리 릭이 발생중 leak
		어떤 파일이나 어떤 입력을 받아도 무조건 첫번째 개행문자까지만 불러들인다.
		재 호출시 다음 줄을 호출하는 기능은 아직 미 구현.(필요한지도 아직 확인 못 함)
*/

char	*remain_line_save(char *s, int count)
{
	
}

int	check_newline(char *s)
{
	int	count;

	count = 0;
	s[BUFF_SIZE] = '\0';
	while(count < BUFF_SIZE)
	{
		if (s[count] == '\n')
 		{
			return (count);
		}
		count++;
	}
	return (0);
}

int	ft_strlen(const char *s)
{
	int count;

	while (s[count])
	{
		count++;
	}
	return (count);
}

char	*ft_strdup(char *s, int	size)
{
	char *dest;
	int	count;

	count = 0;
	dest = (char *)malloc((size+1)*sizeof(char));
	if (!dest)
		return NULL;
	while (s[count] && count < size)
	{
		dest[count] = s[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int 	s1_len;
	int		s2_len;
	int		count;
	char	*new_str;

	count = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc((s1_len + s2_len + 1)*sizeof(char));
	if (!new_str)
		return NULL;
	while (*s1)
	{
		*new_str++ = *s1++;
		count++;
	}
	while (*s2)
	{
		*new_str++ = *s2++;
		count++;
	}
	return (new_str-count);
}

char	*get_next_line(int fd)
{
	int		read_size;
	char	*buf;
	char	*line_save;
	int		trigger;

	printf("\n\n::::::::::content:::::::::\n\n");
	trigger = 0;
	buf = (char *)malloc((BUFF_SIZE+1)*sizeof(char));
	if (!buf)
		return NULL;
	line_save = NULL;
	while (read_size = read(fd, buf, BUFF_SIZE) > 0)
	{
		printf("SircleStart------------\n\n");
		trigger = check_newline(buf);
		printf("[buf->%s]\n\n", buf);
		if (line_save == NULL)
			line_save = ft_strdup(buf, BUFF_SIZE);
		else
			line_save = ft_strjoin(line_save, buf);
		printf("[line_save->%s]\n\n", line_save);
		printf("--------------SircleEnd\n\n");
		if (trigger > 0)
			break;
	}
	printf("::::::::::contentEND:::::::::\n\n");
	printf("<<RESULT>>\n\n");
	return (line_save);
}

int	main(void)
{
	int 	file_d;

	file_d = open("./test.txt", O_RDONLY | O_CREAT, 0644);
	printf("file_descripter number : %d \n", file_d);
	printf("BUFF_SIZE : %d", BUFF_SIZE);
	printf("first:%s$", get_next_line(file_d));
	printf("second:%s$", get_next_line(file_d));
	printf("third:%s$", get_next_line(file_d));
	close(file_d);
}
