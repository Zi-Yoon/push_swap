/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 03:31:17 by byan              #+#    #+#             */
/*   Updated: 2022/06/20 03:35:46 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_info *info)
{
	t_node	*temp;

	if (info->size_b < 1)
		return ;
	temp = info->head_b;
	if (info->size_b > 1)
	{
		info->head_b = info->head_b->next;
		info->head_b->prev = NULL;
	}
	if (info->size_a == 0)
	{
		temp->next = NULL;
		info->head_a = temp;
		info->tail_a = temp;
	}
	else
	{
		temp->next = info->head_a;
		info->head_a->prev = temp;
		info->head_a = temp;
	}
	info->size_a += 1;
	info->size_b -= 1;
	write(1, "pa\n", 3);
}

void	pb(t_info *info)
{
	t_node	*temp;

	if (info->size_a < 1)
		return ;
	temp = info->head_a;
	if (info->size_a > 1)
	{
		info->head_a = info->head_a->next;
		info->head_a->prev = NULL;
	}
	if (info->size_b == 0)
	{
		temp->next = NULL;
		info->head_b = temp;
		info->tail_b = temp;
	}
	else
	{
		temp->next = info->head_b;
		info->head_b->prev = temp;
		info->head_b = temp;
	}
	info->size_a -= 1;
	info->size_b += 1;
	write(1, "pb\n", 3);
}
