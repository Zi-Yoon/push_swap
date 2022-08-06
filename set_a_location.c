/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_a_location.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:13:06 by byan              #+#    #+#             */
/*   Updated: 2022/08/06 20:51:50 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_min(t_node *stack)
{
	int	min;

	min = stack->data;
	while (stack)
	{
		if (min > stack->data)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

int	get_stack_max(t_node *stack)
{
	int	max;

	max = stack->data;
	while (stack)
	{
		if (max < stack->data)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

int	set_a_location_min(t_info *info)
{
	int			ret;
	int			min;
	int			temp;
	t_node		*stack_a;

	ret = 0;
	temp = 0;
	stack_a = info->head_a;
	min = get_stack_min(stack_a);
	while (stack_a)
	{
		temp = stack_a->data;
		if (temp == min)
			break ;
		ret++;
		stack_a = stack_a->next;
	}
	if (ret >= (info->size_a + 1) / 2)
		ret = (info->size_a - ret) * -1;
	return (ret);
}

int	set_a_location_mid(int num, t_info *info)
{
	t_node	*stack_a;
	int		ret;

	stack_a = info->head_a;
	ret = 1;
	while (stack_a->next)
	{
		if (num > stack_a->data && num < stack_a->next->data)
			break ;
		ret++;
		stack_a = stack_a->next;
	}
	if (ret >= (info->size_a + 1) / 2)
		ret = (info->size_a - ret) * -1;
	return (ret);
}

// ret++
int	set_a_location_max(t_info *info)
{
	int			ret;
	int			max;
	int			temp;
	t_node		*stack_a;

	ret = 0;
	temp = 0;
	stack_a = info->head_a;
	max = get_stack_max(stack_a);
	while (stack_a)
	{
		temp = stack_a->data;
		if (temp == max)
			break ;
		ret++;
		stack_a = stack_a->next;
	}
	ret++;
	if (ret >= (info->size_a + 1) / 2)
		ret = (info->size_a - ret) * -1;
	return (ret);
}

