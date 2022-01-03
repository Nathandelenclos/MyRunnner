/*
** EPITECH PROJECT, 2021
** LINKED LIST
** File description:
** swap element in linked list
*/

#include "list.h"
#include <stddef.h>

void swap_element(node **head_ref, int x, int y)
{
    int tmp;
    node *list = *head_ref;
    for (int i = 0;
        i < len_list(*head_ref) && list != NULL; ++i, list = list->next) {
        if (x == i)
            tmp = list->data;
    }
}