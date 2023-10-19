#include "main.h"

/**
 * add_sep_node_end - adds a separator found at the end
 * of a separators_list.
 * @head: head of the linked list.
 * @sep: separator found (; | &).
 * Return: address of the head.
 */
separators_list *add_sep_node_end(separators_list **head, char sep)
{
	separators_list *new, *temp;

	new = malloc(sizeof(separators_list));
	if (new == NULL)
		return (NULL);

	new->separator = sep;
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
 * free_separators_list - frees a separators_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_separators_list(separators_list **head)
{
	separators_list *temp;
	separators_list *curr;

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

/**
 * add_line_node_end - adds a command line at the end
 * of a cmd_lines_lnklist.
 * @head: head of the linked list.
 * @line: command line.
 * Return: address of the head.
 */
cmd_lines_lnklist *add_line_node_end(cmd_lines_lnklist **head, char *line)
{
	cmd_lines_lnklist *new, *temp;

	new = malloc(sizeof(cmd_lines_lnklist));
	if (new == NULL)
		return (NULL);

	new->line = line;
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
 * free_cmd_lines_lnklist - frees a cmd_lines_lnklist
 * @head: head of the linked list.
 * Return: no return.
 */
void free_cmd_lines_lnklist(cmd_lines_lnklist **head)
{
	cmd_lines_lnklist *temp;
	cmd_lines_lnklist *curr;

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

