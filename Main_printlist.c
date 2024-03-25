#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "lists.h"

int main()
{
  listint_t *head;
  listint_t *new;
  listint_t hello = {8, NULL, NULL};
  size_t n;

  head = &hello;
  new = malloc(sizeof(listint_t));
  if (new == NULL)
  {
    dprintf(2, "Error: Can't malloc\n");
    return (EXIT_FAILURE);
  }
  new->n = 9;
  head->prev = new;
  new->next = head;
  new->prev = NULL;
  head = new;
  n = print_listint(head);
  printf("-> %lu elements\n", n);
  free(new);
  return (EXIT_SUCCESS);
}