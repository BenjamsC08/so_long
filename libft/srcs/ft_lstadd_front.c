/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:12:08 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/13 18:39:59 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (! new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main() {
    t_list *head = NULL;

    // Crée et ajoute des éléments à la liste
    ft_lstadd_front(&head, ft_lstnew("Premier"));
    ft_lstadd_front(&head, ft_lstnew("Deuxième"));
    ft_lstadd_front(&head, ft_lstnew("Troisième"));
    //ft_lstadd_front(&head, ft_lstnew("un"));

    // Affichage des éléments de la liste
    t_list *current = head;
    while (current) {
        printf("%s -> ", (char *)current->content);
        current = current->next;
    }
    printf("NULL\n");

    // Libération de la mémoire
    current = head;
    t_list *temp;
    while (current) {
        temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
*/
