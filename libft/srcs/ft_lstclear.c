/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:13:29 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/11 21:13:56 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*last;

	current = *lst;
	while (current != NULL)
	{
		last = current;
		current = current->next;
		ft_lstdelone(last, del);
	}
	*lst = NULL;
}
/*
void del(void *content) {
    free(content);
}

#include <stdio.h>
int main() {
    t_list *list = NULL;

    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Premier")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Deuxième")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Troisième")));

    printf("Liste avant la suppression:\n");
    t_list *current = list;
    while (current) {
        printf("%s -> ", (char *)current->content);
        current = current->next;
    }
    printf("NULL\n");

    if (list && list->next) {
        ft_lstclear(&list, &del);
    }

    printf("Liste après la suppression:\n");
    current = list;
    while (current) {
        printf("%s -> ", (char *)current->content);
        current = current->next;
    }
    printf("NULL\n");

    while (list) {
        t_list *next = list->next;
        ft_lstdelone(list, del);
        list = next;
    }

    return 0;
}
*/
