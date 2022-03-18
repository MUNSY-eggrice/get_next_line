/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoon <ymoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:53:39 by ymoon             #+#    #+#             */
/*   Updated: 2022/03/18 21:27:41 by ymoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#inclde <stdlib.h>

char	*get_next_line(int fd);
{
	static char *read_line;

	return (read_line);
}
