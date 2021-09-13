/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkikuchi <kkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:10:02 by kkikuchi          #+#    #+#             */
/*   Updated: 2021/09/01 12:27:02 by kkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*t;

	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	t = (char *)s;
	while (*t != '\0')
	{
		if (*t == (char)c)
			return (t);
		t++;
	}
	return (NULL);
}
