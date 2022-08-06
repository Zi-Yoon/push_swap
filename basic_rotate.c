/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 03:27:31 by byan              #+#    #+#             */
/*   Updated: 2022/06/20 03:35:48 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_info *info)
{
	t_node	*temp;

	if (info->size_a < 2)
		return ;
	temp = info->head_a;
	info->head_a = info->head_a->next;
	info->head_a->prev = NULL;
	info->tail_a->next = temp;
	temp->prev = info->tail_a;
	info->tail_a = temp;
	info->tail_a->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_info *info)
{
	t_node	*temp;

	if (info->size_b < 2)
		return ;
	temp = info->head_b;
	info->head_b = info->head_b->next;
	info->head_b->prev = NULL;
	info->tail_b->next = temp;
	temp->prev = info->tail_b;
	info->tail_b = temp;
	info->tail_a->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_info *info)
{
	t_node	*temp;

	if (info->size_b < 2 || info->size_a < 2)
		return ;
	temp = info->head_a;
	info->head_a = info->head_a->next;
	info->head_a->prev = NULL;
	info->tail_a->next = temp;
	temp->prev = info->tail_a;
	info->tail_a = temp;
	info->tail_a->next = NULL;
	temp = info->head_b;
	info->head_b = info->head_b->next;
	info->head_b->prev = NULL;
	info->tail_b->next = temp;
	temp->prev = info->tail_b;
	info->tail_b = temp;
	info->tail_a->next = NULL;
	write(1, "rr\n", 3);
}
