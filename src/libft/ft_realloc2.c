/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkikuchi <kkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:09:54 by kkikuchi          #+#    #+#             */
/*   Updated: 2021/09/01 12:26:59 by kkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_realloc2(char **old, char *add)
{
	char	**new;
	int		len;
	int		i;

	len = 0;
	while (old[len] != NULL)
		len++;
	new = (char **)malloc(sizeof(char *) * (len + 2));
	i = 0;
	while (i < len)
	{
		new[i] = old[i];
		i++;
	}
	new[i++] = add;
	new[i] = NULL;
	free(old);
	return (new);
}
