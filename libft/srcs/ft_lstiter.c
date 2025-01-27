/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:14:39 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/13 16:39:51 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	current = lst;
	while (current != NULL)
	{
		f(current->content);
		current = current->next;
	}
}
/*
#include <stdio.h>
#include <string.h>

void fun_ction(void *content) {
  char *ptr; 
  unsigned int i;
  ptr = (char *)content;
  i = 0;
  while (ptr[i])
    ptr[(i++)] += 2;
}

int main() {
    t_list *list = NULL;

    ft_lstadd_back(&list, ft_lstnew(ft_strdup("3")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("4")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("5")));

    printf("Liste avant la suppression:\n");
    t_list *current = list;
    while (current) {
        printf("%s -> ", (char *)current->content);
        current = current->next;
    }
    printf("NULL\n");

    if (list && list->next) {
        t_list *to_fun = list;
        ft_lstiter(to_fun, &fun_ction);
    }

    printf("Liste après la function:\n");
    current = list;
    while (current) {
        printf("%s -> ", (char *)current->content);
        current = current->next;
    }
    printf("NULL\n");

    return 0;
}
*/
