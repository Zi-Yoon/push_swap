/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 03:25:10 by byan              #+#    #+#             */
/*   Updated: 2022/06/20 08:11:28 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_info *info)
{
	int	temp;

	if (info->size_a < 2)
	{
		return ;
	}
	temp = info->head_a->data;
	info->head_a->data = info->head_a->next->data;
	info->head_a->next->data = temp;
	write(1, "sa\n", 3);
}

void	sb(t_info *info)
{
	int	temp;

	if (info->size_b < 2)
	{
		return ;
	}
	temp = info->head_b->data;
	info->head_b->data = info->head_b->next->data;
	info->head_b->next->data = temp;
	write(1, "sb\n", 3);
}

void	ss(t_info *info)
{
	int	temp;

	if (info->size_a < 2)
		return ;
	if (info->size_b < 2)
		return ;
	temp = info->head_a->data;
	info->head_a->data = info->head_a->next->data;
	info->head_a->next->data = temp;
	temp = info->head_b->data;
	info->head_b->data = info->head_b->next->data;
	info->head_b->next->data = temp;
	write(1, "ss\n", 3);
}
