/*
** EPITECH PROJECT, 2021
** LINKED_LIST
** File description:
** free_list
*/

#include "list.h"
#include <stdlib.h>

int free_list(node *head)
{
    node* tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    return (0);
}
