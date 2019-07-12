/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:29:25 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/12 11:14:00 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		ft_part(int arr[], int low, int high)
{
	int	pivot;
	int	i;
	int	count;

	pivot = arr[high];
	i = (low - 1);
	count = low;
	while (count <= high - 1)
	{
		if (arr[count] <= pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[count]);
		}
		count++;
	}
	ft_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	ft_qt(int arr[], int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = ft_part(arr, low, high);
		ft_qt(arr, low, pivot - 1);
		ft_qt(arr, pivot + 1, high);
	}
}

void	ft_sort_integer_table(int *tab, int size)
{
	ft_qt(tab, 0, size - 1);
}
