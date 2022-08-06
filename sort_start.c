/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 02:36:59 by byan              #+#    #+#             */
/*   Updated: 2022/08/06 22:13:42 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_size_three(t_info *info)
{
	int	head;
	int	mid;
	int	tail;

	head = info->head_a->data;
	mid = info->head_a->next->data;
	tail = info->head_a->next->next->data;
	if (head > mid && mid > tail && head > tail)
	{
		sa(info);
		rra(info);
	}
	else if (head > mid && tail > mid && head > tail)
		ra(info);
	else if (mid > head && mid > tail && tail > head)
	{
		sa(info);
		ra(info);
	}
	else if (head > mid && tail > mid && tail > head)
		sa(info);
	else if (mid > head && mid > tail && head > tail)
		rra(info);
}

void	sort_finish(t_info *info)
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

void	sort_big(t_info *info)
{
	int	a;
	int	b;

	make_three_pivot(info);
	while (info->size_a > 3)
		pb(info);
	if (info->size_a == 2)
	{
		if (info->head_a->data > info->head_a->next->data)
			sa(info);
	}
	if (info->size_a == 3)
		sort_size_three(info);
	while (info->size_b)
	{
		a = 0;
		b = 0;
		find_least_rotate(info, &a, &b);
		rotate_together(info, &a, &b);
		ratate_a(info, a);
		rotate_b(info, b);
		pa(info);
	}
	sort_finish(info);
}

void	sort_start(t_info *info)
{
	if (info->size_a == 2)
	{
		if (info->head_a->data > info->head_a->next->data)
			sa(info);
	}
	else if (info->size_a == 3)
		sort_size_three(info);
	else
		sort_big(info);
}
