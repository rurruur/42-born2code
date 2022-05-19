/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:54:32 by nakkim            #+#    #+#             */
/*   Updated: 2022/05/19 17:55:22 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *arr, int index1, int index2)
{
	int	tmp;

	tmp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = tmp;
}

void	quick_sort(int *arr, int left, int right)
{
	int	L;
	int	R;
	
	L = left + 1;
	R = right;
	while (L < R)
	{
		while (L <= R && arr[L] <= arr[left])
			L++;
		while (R > L && arr[R] > arr[left])
			R--;
		if (L < R)
		{
			swap(arr, L, R);
			L++;
			R--;
		}
	}
	if (arr[left] > arr[R])
		swap(arr, left, R);
	if (left < R)
		quick_sort(arr, left, R - 1);
	if (R < right)
		quick_sort(arr, R, right);
}
