/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:05:27 by belinore          #+#    #+#             */
/*   Updated: 2025/12/02 16:05:28 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint64_t	get_time_in_ms(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

int	max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}

int	iabs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

//Linear interpolation: rangeNEW * (unscaled_num - old_min) / rangeOLD + new_min
double	scale_pixel(int unscaled_num, double new_min, double new_max,
		int old_max)
{
	return ((new_max - new_min) * unscaled_num / (double)old_max + new_min);
}
