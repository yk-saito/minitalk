/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 14:54:45 by ysaito            #+#    #+#             */
/*   Updated: 2021/11/01 20:43:06 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*stored_next;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		stored_next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = stored_next;
	}
}
