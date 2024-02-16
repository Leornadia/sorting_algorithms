#include "sort.h"
/**
 * insertion_sort_list - Sorts a double linked lst of ints
 *                        in ascending order using the
 *                        Insertion sort algorithm
 *
 * @list: The list to sort
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *temp;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
current = (*list)->next;
while (current != NULL)
{
temp = current->prev;
while (temp != NULL && current->n < temp->n)
{
temp->next = current->next;
if (current->next != NULL)
current->next->prev = temp;
current->prev = temp->prev;
current->next = temp;
temp->prev = current;
if (current->prev != NULL)
current->prev->next = current;
else
*list = current;
print_list(*list);
temp = current->prev;
}
current = current->next;
}
}
