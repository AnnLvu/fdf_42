#include "fdf.h"

void	insert_at_top(t_stack **stack, t_stack *new)
{
	if (stack && new)
	{
		if (!(*stack))
			*stack = new;
		else
		{
			new->next = *stack;
			*stack = new;
		}
	}
}

int	insert_stack_element(char **sec_split, t_stack **stack)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (1);
	new_stack->z = (t_point_param *)malloc(sizeof(t_point_param));
	if (!(new_stack->z))
		return (1);
	new_stack->z->altitude = ft_atoi(sec_split[0]);
	if (sec_split[1] != NULL)
		new_stack->z->color = ft_atoi_hex(sec_split[1]);
	else
		new_stack->z->color = -1;
	new_stack->next = NULL;
	stack_add_front(stack, new_stack);
	return (0);
}