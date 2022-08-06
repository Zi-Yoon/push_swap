/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:05:47 by byan              #+#    #+#             */
/*   Updated: 2022/08/06 22:13:42 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_a_location(int num, t_info *info)
{
	int	ret;

	if (num < get_stack_min(info->head_a))
		ret = set_a_location_min(info);
	else if (num > get_stack_max(info->head_a))
		ret = set_a_location_max(info);
	else
		ret = set_a_location_mid(num, info);
	return (ret);
}

void	rotate_together(t_info *info, int *a, int *b)
{
	while (*a && *b && (*a > 0 && *b > 0))
	{
		rr(info);
		*a = *a - 1;
		*b = *b - 1;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		rrr(info);
		*a = *a + 1;
		*b = *b + 1;
	}
}

void	ratate_a(t_info *info, int a)
{
	while (a)
	{
		if (a > 0)
		{
			ra(info);
			a--;
		}
		else
		{
			rra(info);
			a++;
		}
	}
}

void	rotate_b(t_info *info, int b)
{
	while (b)
	{
		if (b > 0)
		{
			rb(info);
			b--;
		}
		else
		{
			rrb(info);
			b++;
		}
	}
}

