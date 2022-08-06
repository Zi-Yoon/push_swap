/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_r_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 03:31:14 by byan              #+#    #+#             */
/*   Updated: 2022/06/20 03:35:45 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_info *info)
{
	t_node	*temp;

	if (info->size_a < 2)
		return ;
	temp = info->tail_a;
	info->tail_a = info->tail_a->prev;
	info->tail_a->next = NULL;
	info->head_a->prev = temp;
	temp->next = info->head_a;
	info->head_a = temp;
	info->head_a->prev = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_info *info)
{
	t_node	*temp;

	if (info->size_b < 2)
		return ;
	temp = info->tail_b;
	info->tail_b = info->tail_b->prev;
	info->tail_b->next = NULL;
	info->head_b->prev = temp;
	temp->next = info->head_b;
	info->head_b = temp;
	info->head_b->prev = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_info *info)
{
	t_node	*temp;

	if (info->size_b < 2 || info->size_a < 2)
		return ;
	temp = info->tail_a;
	info->tail_a = info->tail_a->prev;
	info->tail_a->next = NULL;
	info->head_a->prev = temp;
	temp->next = info->head_a;
	info->head_a = temp;
	info->head_a->prev = NULL;
	temp = info->tail_b;
	info->tail_b = info->tail_b->prev;
	info->tail_b->next = NULL;
	info->head_b->prev = temp;
	temp->next = info->head_b;
	info->head_b = temp;
	info->head_b->prev = NULL;
	write(1, "rrr\n", 4);
}
