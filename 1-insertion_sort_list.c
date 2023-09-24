#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list integers in ascending order
 *                       using Insertion Sort.
 * @list: Pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		sorted = current;
		current = current->next;

		while (sorted->prev != NULL && sorted->n < sorted->prev->n)
		{
			temp = sorted->prev;
			sorted->prev = temp->prev;
			temp->next = sorted->next;

			if (temp->prev != NULL)
				temp->prev->next = sorted;

			sorted->next = temp;
			temp->prev = sorted;

			if (sorted->prev == NULL)
				*list = sorted;

			print_list(*list);  /* Print list after each swap */
		}
	}
}
