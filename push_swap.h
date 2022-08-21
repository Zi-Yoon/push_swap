/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 23:30:14 by byan              #+#    #+#             */
/*   Updated: 2022/08/22 01:31:28 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node
{
	struct s_node		*prev;
	int					data;
	struct s_node		*next;
}	t_node;

typedef struct s_info
{
	int				*arr;
	int				size_a;
	struct s_node	*head_a;
	struct s_node	*tail_a;
	int				size_b;
	struct s_node	*head_b;
	struct s_node	*tail_b;
}	t_info;

int		main(int argc, char *argv[]);

/*
	make_node_utils.c
*/
int		cnt_str(char **str_arr);
void	free_arr(char **arr);
int		ft_atoll(const char *str);
void	str_to_array(int *array, int *arr_index, char **str);

/*
	make_node.c
*/
int		argv_size(int argc, char *argv[]);
int		*argv_to_arr(int argc, char *argv[], int size);
void	arr_to_stack(t_info *info, int *array, int size);
void	sort_and_check(int *array, int size, int index);

/*
	set_a_location.c
*/
int		get_stack_min(t_node *stack);
int		get_stack_max(t_node *stack);
int		set_a_location_min(t_info *info);
int		set_a_location_mid(int num, t_info *info);
int		set_a_location_max(t_info *info);

/*
	settings.c
*/
int		print_error(int type);
t_node	*new_node(void);
t_info	*new_info(void);
void	free_a(t_info **info);

/*
	sort_rotate.c
*/
void	devide_three_part(t_info *info, int pivot1, int pivot2);
void	make_three_pivot(t_info *info);
int		compare_least_rotate(int a, int b, int a_loc, int b_loc);
void	find_least_rotate(t_info *info, int *a, int *b);

/*
	sort_start.c
*/
void	sort_size_three(t_info *info);
void	sort_finish(t_info *info);
void	sort_big(t_info *info);
void	sort_start(t_info *info);

/*
	stack_rotate.c
*/
int		set_a_location(int num, t_info *info);
void	rotate_together(t_info *info, int *a, int *b);
void	ratate_a(t_info *info, int a);
void	rotate_b(t_info *info, int b);

/*
	basic_*.c
*/
void	ra(t_info *info);
void	rb(t_info *info);
void	rr(t_info *info);
void	rra(t_info *info);
void	rrb(t_info *info);
void	rrr(t_info *info);
void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);
void	pa(t_info *info);
void	pb(t_info *info);

#endif