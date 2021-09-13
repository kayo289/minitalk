/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstinsert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkikuchi <kkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:08:15 by kkikuchi          #+#    #+#             */
/*   Updated: 2021/09/01 12:26:59 by kkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstinsert(t_dlist **lst, t_dlist *new)
{
	if (*lst == NULL)
		*lst = new;
	else if ((*lst)->next == NULL)
	{
		(*lst)->next = new;
		new->prev = (*lst);
	}
	else
	{
		new->next = (*lst)->next;
		new->prev = (*lst);
		(*lst)->next->prev = new;
		(*lst)->next = new;
	}
}
