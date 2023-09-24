#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of
 *                       integers in ascending order using Insertion Sort
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		prev = current->prev;
		temp = current;

		while (prev != NULL && prev->n > temp->n)
		{
			/* Swap the nodes */
			if (temp->next != NULL)
				temp->next->prev = prev;

			prev->next = temp->next;
			temp->prev = prev->prev;

			if (prev->prev != NULL)
				prev->prev->next = temp;
			else
				*list = temp;

			prev->prev = temp;
			temp->next = prev;

			/* Print the list after each swap */
			print_list(*list);

			prev = temp->prev;
		}
		current = current->next;
	}
}
