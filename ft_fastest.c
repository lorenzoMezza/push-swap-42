#include "push_swap.h"

/*
** Iterates over all elements in stack_a and returns the one
** whose combined rotation cost (position in a + landing spot in b)
** is minimal.
*/
t_stack	*ft_fastest(t_stack *stack_a, t_stack *stack_b, int size)
{
	int		i;
	int		best_pos;
	int		best_spot;
	t_stack	*current;
	t_stack	*iter;

	i = 0;
	current = stack_a;
	iter = stack_a;
	best_pos = ft_position(current, stack_a, size);
	best_spot = ft_find_spot(current, stack_b, ft_lst_count(stack_b));
	while (i < size)
	{
		iter = iter->next;
		if (ft_compare(best_pos, best_spot,
				ft_position(iter, stack_a, size),
				ft_find_spot(iter, stack_b, ft_lst_count(stack_b))) == 1)
		{
			best_pos = ft_position(iter, stack_a, size);
			best_spot = ft_find_spot(iter, stack_b, ft_lst_count(stack_b));
			current = iter;
		}
		i++;
	}
	return (current);
}
