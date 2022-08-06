/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:45:01 by byan              #+#    #+#             */
/*   Updated: 2022/08/06 22:06:07 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cnt_str(char **str_arr)
{
	int	index;

	index = 0;
	while (str_arr[index])
		index++;
	return (index);
}

void	free_arr(char **arr)
{
	int	index;

	index = 0;
	while (arr[index])
	{
		free(arr[index]);
		index++;
	}
	free(arr);
}

int	ft_atoll(const char *str)
{
	long long	result;
	int			minus;
	int			digit;

	result = 0;
	minus = 1;
	digit = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
		digit++;
	}
	result = result * minus;
	if (*str != '\0' || digit > 10
		|| result > 2147483647 || result < -2147483648)
		print_error(1);
	return ((int)result);
}

void	str_to_array(int *array, int *arr_index, char **str)
{
	int	num;
	int	index;

	index = 0;
	while (str[index])
	{
		num = ft_atoll(str[index]);
		array[*arr_index] = num;
		(*arr_index)++;
		index++;
	}
}
