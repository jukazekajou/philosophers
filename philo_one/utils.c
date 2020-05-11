/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeromedu <jeromedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 18:52:01 by jeromedu          #+#    #+#             */
/*   Updated: 2020/05/11 13:54:31 by jeromedurand     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo_one.h"

void	ft_print(t_ph *ph)
{
	char			*b;

	if (ph->data->over == 1)
		return ;
	pthread_mutex_lock(&ph->data->output);
	b = ft_itoa(get_time(ph->data->time, ph->end));
	ft_putstr(b);
	free(b);
	ft_putstr(" ms: ");
	b = ft_itoa(ph->n + 1);
	ft_putstr(b);
	free(b);
	if (ph->activity == THINKING && ph->has_a_fork == 0)
		ft_putstr(" is THINKING\n");
	else if (ph->activity == EATING)
		ft_putstr(" is EATING\n");
	else if (ph->activity == SLEEPING)
		ft_putstr(" is SLEEPING\n");
	else if (ph->activity == DEAD)
		ft_putstr(" has died\n");
	else if (ph->activity == THINKING && ph->has_a_fork == 1)
		ft_putstr(" has taken a fork\n");
	pthread_mutex_unlock(&ph->data->output);
}

long	get_time(struct timeval ini, struct timeval now)
{
	long seconds;
	long micros;

	seconds = (now.tv_sec - ini.tv_sec) * 1000;
	micros = (now.tv_usec - (ini.tv_usec)) / 1000;
	return (micros + seconds);
}

int		fork_priority_1(int n, int n_max)
{
	if (n_max % 2)
		return (n);
	else
	{
		if (!(n % 2))
		{
			if (n < n_max - 1)
				return (n + 1);
			else
				return (0);
		}
		else
		{
			return (n);
		}
	}
}

int		fork_priority_2(int n, int n_max)
{
	if (n_max % 2)
	{
		if (n < n_max - 1)
			return (n + 1);
		else
			return (0);
	}
	else
	{
		if (!(n % 2))
			return (n);
		else
		{
			if (n < n_max - 1)
				return (n + 1);
			else
				return (0);
		}
	}
}
