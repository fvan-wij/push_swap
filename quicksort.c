/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:14:00 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/03/21 18:09:23 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	partition(int array[], int low, int high)
{
	int	pivot = high - 1;
	int	temp;
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (j < pivot)
	{
		if (array[j] < array[pivot])
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[pivot];
	array[pivot] = temp;

	int k = 0;
	while (k < high)
	{
		printf("%d\n", array[k]);
		k++;
	}
	return (i + 1);
}

int	main(void)
{
	int	array[] = {20, 30, 10, 60, 0, 40, 90, 50};
	partition(array, 0, 8);
}