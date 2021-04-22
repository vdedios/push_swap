#include "instructions.h"

int	lst_len(t_element *stack)
{
	int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack->next)
	{
		stack = stack->next;
		len++;
	}
	len++;
	return (len);
}

int	lst_len_end(t_element *stack, t_element *end)
{
	int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack && stack != end)
	{
		stack = stack->next;
		len++;
	}
	if (end)
		len++;
	return (len);
}
