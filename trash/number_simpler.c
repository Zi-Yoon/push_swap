/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_simpler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 05:12:33 by byan              #+#    #+#             */
/*   Updated: 2022/06/20 10:31:20 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	*temp;

	temp = a;
	a = b;
	b = temp;
}

void	quick_sort(int *data, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = start;
	i = pivot + 1;
	j = end;
	if (start >= end)
		return ;
	while (i <= j)
	{
		while (i <= end && data[i] <= data[pivot])
			i++;
		while (j > start && data[j] >= data[pivot])
			j--;
		if (i > j)
			ft_swap(&data[j], &data[pivot]);
		else
			ft_swap(&data[i], &data[j]);
	}
	quick_sort(data, start, j - 1);
	quick_sort(data, j + 1, end);
}

void	number_simpler(t_info *info, int *array, int size)
{
	int	i;
	int	j;
	int	*sorted_arr;

	i = 0;
	sorted_arr = (int *)malloc(sizeof(int) * size);
	ft_memcpy(sorted_arr, array, sizeof(int) * size);
	quick_sort(sorted_arr, 0, size - 1);
	while (i < size)
	{
		j = 0;
		while (array[i] != sorted_arr[j])
			j++;
		array[i] = j + 1;
		i++;
	}
	info->max_a = sorted_arr[size - 1];
	free(sorted_arr);
	return ;
}
