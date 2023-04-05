/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_overflow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:29:45 by fvan-wij          #+#    #+#             */
/*   Updated: 2023/04/05 15:37:46 by fvan-wij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	skip_whitespace(int i, char *int_str)
{
	while (int_str[i] == ' ' || int_str[i] == '\t'
		|| int_str[i] == '\r' || int_str[i] == '\n'
		|| int_str[i] == '\v' || int_str[i] == '\f')
	i++;
	return (i);
}

static long	convert_atoi(char *int_str, int i, t_meta *meta)
{
	long	atoi;

	atoi = 0;
	while ((int_str[i] >= 48 && int_str[i] <= 57) && int_str[i] != '\0')
	{
		atoi = atoi * 10 + (int_str[i] - '0');
		i++;
	}
	if (atoi > INT_MAX || atoi < INT_MIN)
		exit_with_error_code(meta, ALLOCATION_FAILURE);
	return ((int)atoi);
}

int	ft_atoi_overflow(t_meta *meta, const char *nptr)
{
	char	*int_str;
	int		atoi;
	int		i;
	int		j;
	int		neg_check;

	int_str = (char *) nptr;
	atoi = 0;
	i = 0;
	j = 0;
	neg_check = 1;
	i = skip_whitespace(i, int_str);
	if (int_str[i] == '-')
		neg_check = -neg_check;
	while (int_str[i] == '-' || int_str[i] == '+')
	{
		i++;
		j++;
		if (j > 1)
			return (0);
	}
	atoi = convert_atoi(int_str, i, meta);
	return (atoi * neg_check);
}
