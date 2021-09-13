/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkikuchi <kkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:08:07 by kkikuchi          #+#    #+#             */
/*   Updated: 2021/09/01 12:26:59 by kkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new)
{
	if (*lst != NULL)
	{
		while ((*lst)->prev != NULL)
			*lst = (*lst)->prev;
		(*lst)->prev = new;
		new->next = *lst;
	}
	*lst = new;
}
