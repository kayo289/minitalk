/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkikuchi <kkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:09:56 by kkikuchi          #+#    #+#             */
/*   Updated: 2021/09/01 12:26:59 by kkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	***ft_realloc3(char ***old, char **add)
{
	char	***new;
	int		len;
	int		i;
	int		j;

	len = 0;
	while (old[len] != NULL)
		len++;
	new = (char ***)malloc(sizeof(char **) * (len + 2));
	new[0] = add;
	i = 0;
	j = 1;
	while (old[i] != NULL)
		new[j++] = old[i++];
	new[j] = NULL;
	return (new);
}
