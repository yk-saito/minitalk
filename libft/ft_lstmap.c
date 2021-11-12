/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 23:53:54 by ysaito            #+#    #+#             */
/*   Updated: 2021/11/01 20:43:27 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copylst;
	t_list	*newlst;

	if (lst == NULL || f == NULL)
		return (NULL);
	copylst = lst;
	newlst = NULL;
	while (copylst != NULL)
	{
		ft_lstadd_back(&newlst, ft_lstnew(f(copylst->content)));
		if (newlst == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		copylst = copylst->next;
	}
	return (newlst);
}
