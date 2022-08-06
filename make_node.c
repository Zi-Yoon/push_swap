/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:25:03 by byan              #+#    #+#             */
/*   Updated: 2022/08/07 03:41:53 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argv_size(int argc, char *argv[])
{
	int		cnt;
	int		size;
	int		index;
	char	**split_arr;

	cnt = 0;
	size = 0;
	while (cnt < argc)
	{
		index = 0;
		while (argv[cnt][index])
		{
			if (!ft_isspace(argv[cnt][index]))
				break ;
			index++;
		}
		if (argv[cnt][index] == '\0')
			print_error(1);
		split_arr = ft_split(argv[cnt], ' ');
		size += cnt_str(split_arr);
		free_arr(split_arr);
		cnt++;
	}
	return (size - 1);
}

int	*argv_to_arr(int argc, char *argv[], int size)
{
	int		argc_index;
	int		arr_index;
	int		*num_arr;
	char	**split_str;

	argc_index = 1;
	arr_index = 0;
	num_arr = (int *)malloc(sizeof(int) * size);
	if (!num_arr)
		print_error(1);
	while (argc_index < argc)
	{
		split_str = ft_split(argv[argc_index], ' ');
		str_to_array(num_arr, &arr_index, split_str);
		free_arr(split_str);
		argc_index++;
	}
	num_arr[arr_index] = '\0';
	return (num_arr);
}

void	arr_to_stack(t_info *info, int *array, int size)
{
	t_node	*node;
	int		index;

	index = 0;
	while (index < size)
	{
		node = new_node();
		info->size_a += 1;
		info->tail_a->data = (int)array[index];
		info->tail_a->next = node;
		node->prev = info->tail_a;
		info->tail_a = node;
		index++;
	}
	info->tail_a = info->tail_a->prev;
	free(node);
}

void	sort_and_check(int *array, int size, int index)
{
	int	i;
	int	temp;
	int	sorted;

	sorted = 0;
	while (index < size)
	{
		i = 0;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				sorted++;
			}
				i++;
		}
		if (array[index] == array[index + 1])
			print_error(1);
		index++;
	}
	if (sorted == 0)
		print_error(-1);
}
