/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:54:32 by nakkim            #+#    #+#             */
/*   Updated: 2022/05/25 23:04:01 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_arr(int *arr, int index1, int index2)
{
	int	tmp;

	tmp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = tmp;
}

void	quick_sort(int *arr, int left, int right)
{
	int	left_i;
	int	right_i;

	left_i = left + 1;
	right_i = right;
	while (left_i < right_i)
	{
		while (left_i <= right_i && arr[left_i] <= arr[left])
			left_i++;
		while (right_i > left_i && arr[right_i] > arr[left])
			right_i--;
		if (left_i < right_i)
		{
			swap_arr(arr, left_i, right_i);
			left_i++;
			right_i--;
		}
	}
	if (arr[left] > arr[right_i])
		swap_arr(arr, left, right_i);
	if (left < right_i)
		quick_sort(arr, left, right_i - 1);
	if (right_i < right)
		quick_sort(arr, right_i, right);
}
