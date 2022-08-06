/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:15:13 by byan              #+#    #+#             */
/*   Updated: 2022/08/07 03:27:07 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int			size;
	int			*arr;
	t_info		*info;

	size = 0;
	if (argc < 2)
		print_error(-1);
	info = new_info();
	size = argv_size(argc, argv);
	arr = argv_to_arr(argc, argv, size);
	arr_to_stack(info, arr, size);
	sort_and_check(arr, size, 0);
	info->arr = (int *)arr;
	sort_start(info);
	return (0);
}
