#include "push_swap.h"

t_stack	*ft_lstnew_adapt(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!(new))
		return (NULL);
	new->content = content;
	new->index = -1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/*
** Adds a node at the back of a NON-circular list.
** ft_close_circle() must be called after the full list is built.
*/
void	ft_lstadd_back_adapt(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	temp = ft_lstlast_adapt(*lst);
	temp->next = new;
	new->prev = temp;
	new->next = NULL;
}

/*
** Counts nodes in a circular doubly-linked list.
** Returns 0 for NULL list.
*/
int	ft_lst_count(t_stack *stack)
{
	t_stack	*first;
	int		i;

	if (stack == NULL)
		return (0);
	i = 1;
	first = stack;
	while (stack->next != first)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack	*ft_lstlast_adapt(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
