/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:29:54 by byan              #+#    #+#             */
/*   Updated: 2022/08/06 22:34:29 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(int type)
{
	if (type >= 1)
		write(2, "Error\n", 6);
	exit(1);
	return (-1);
}

t_node	*new_node(void)
{
	t_node	*node;

	node = NULL;
	node = (t_node *)malloc(sizeof(t_node));
	node->prev = NULL;
	node->data = 0;
	node->next = NULL;
	return (node);
}

t_info	*new_info(void)
{
	t_node		*a;
	t_info		*info;

	info = NULL;
	info = (t_info *)malloc(sizeof(t_info));
	a = new_node();
	info->arr = NULL;
	info->size_a = 0;
	info->head_a = a;
	info->tail_a = a;
	info->size_b = 0;
	return (info);
}
