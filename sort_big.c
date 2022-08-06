/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:53:19 by byan              #+#    #+#             */
/*   Updated: 2022/08/06 18:58:01 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_big_last(t_info *info)
{
	int	min;
	int	min_location;

	min = get_stack_min(info->head_a);
	min_location = set_a_location_min(info);
	while (min_location)
	{
		if (min_location > 0)
		{
			ra(info);
			min_location--;
		}
		else
		{
			rra(info);
			min_location++;
		}
	}
}

void	ft_sort_3div_insruct(t_info *info, int pivot1, int pivot2)
{
	if (info->head_a->data < pivot1)
	{
		pb(info);
		rb(info);
	}
	else if (info->head_a->data < pivot2)
		pb(info);
	else
		ra(info);
}

void	ft_sort_three_division(t_info *info)
{
	int	index;
	int	pivot1;
	int	pivot2;

	index = info->size_a / 3;
	pivot1 = info->arr[index];
	index = info->size_a * 2 / 3;
	pivot2 = info->arr[index];
	index = info->size_a;
	while (index)
	{
		ft_sort_3div_insruct(info, pivot1, pivot2);
		index--;
	}
}

int	ft_get_bigger(int a, int b, int a_loc, int b_loc)
{
	if (a < 0)
		a = a * -1;
	if (b < 0)
		b = b * -1;
	if (a_loc < 0)
		a_loc = a_loc * -1;
	if (b_loc < 0)
		b_loc = b_loc * -1;
	if (a + b > a_loc + b_loc)
		return (1);
	else
		return (0);
}

void	get_min_rotate(t_info *info, int *a, int *b)
{
	int			a_location;
	int			b_location;
	int			index;
	t_node		*stack_b;
	int			num;

	index = 0;
	stack_b = info->head_b;
	while (index < info->size_b)
	{
		num = stack_b->data;
		a_location = set_a_location(num, info);
		if (index >= (info->size_b + 1) / 2)
			b_location = (info->size_b - index) * -1;
		else
			b_location = index;
		if (index == 0 || ft_get_bigger(*a, *b, a_location, b_location))
		{
			*a = a_location;
			*b = b_location;
		}
		stack_b = stack_b->next;
		index++;
	}
}
