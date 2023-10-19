#include "main.h"

/**
 * add_rvar_node - adds a variable at the end
 * of a variables_lnklist list.
 * @head: head of the linked list.
 * @lvar: length of the variable.
 * @val: value of the variable.
 * @lval: length of the value.
 * Return: address of the head.
 */
variables_lnklist *add_rvar_node(variables_lnklist **head, int lvar, char *val, int lval)
{
	variables_lnklist *new, *temp;

	new = malloc(sizeof(variables_lnklist));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_rvar_list - frees a variables_lnklist list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_rvar_list(variables_lnklist **head)
{
	variables_lnklist *temp;
	variables_lnklist *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}

