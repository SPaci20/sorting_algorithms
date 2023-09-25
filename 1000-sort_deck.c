#include "deck.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int compare_cards(const void *a, const void *b);
/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to a pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	size_t len = 0;
	deck_node_t *current = *deck;
	deck_node_t **deck_array;
	size_t i;

	while (current)
	{
		len++;
		current = current->next;
	}

	if (len < 2)
		return;

	deck_array = (deck_node_t **)malloc(len * sizeof(deck_node_t *));
	if (deck_array == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	current = *deck;
	for (i = 0; i < len; i++)
	{
		deck_array[i] = current;
		current = current->next;
	}
	qsort(deck_array, len, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < len - 1; i++)
	{
		deck_array[i]->next = deck_array[i + 1];
		deck_array[i + 1]->prev = deck_array[i];
	}
	deck_array[0]->prev = NULL;
	deck_array[len - 1]->next = NULL;
	*deck = deck_array[0];

	free(deck_array);
}
/**
 * compare_cards - Comparison function for qsort
 * @a: Pointer to the first card node
 * @b: Pointer to the second card node
 *
 * Return: Negative if a < b, 0 if a == b, positive if a > b
 */
static int compare_cards(const void *a, const void *b)
{
	const deck_node_t *node_a = *((const deck_node_t **)a);
	const deck_node_t *node_b = *((const deck_node_t **)b);

	if (node_a->card->kind < node_b->card->kind)
		return (-1);
	if (node_a->card->kind > node_b->card->kind)
		return (1);

	return (strcmp(node_a->card->value, node_b->card->value));
}
