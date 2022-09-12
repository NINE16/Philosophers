/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:20:14 by nemethnikol       #+#    #+#             */
/*   Updated: 2022/09/12 16:00:44 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*create_philos(t_table *table, t_philo *philos)
{
	int		i;

	//philos.l_fork = malloc(sizeof(pthread_mutex_t) * table->n_philos);
	philos = malloc(sizeof(t_philo) * table->n_philos);
	i = 0;
	philos->start_time = ft_set_now();
	while (i < table->n_philos)
	{
		philos[i].id = i + 1;
		if ( i == table->n_philos - 1)
			philos[i].next = 0;
		else
			philos[i].next = i + 1;
		philos[i].n_meals = 0;
		philos[i].last_meal = 0;
		philos[i].wait = 0;
		philos[i].table = table;
		pthread_mutex_init(&philos[i].fork, NULL);
		// pthread_mutex_init(&philos[i].r_fork, NULL);
		// if (i == table->n_philos - 1)
		// 	philos[i].r_fork = philos[0].l_fork;
		// else if (i != 0)
		// 	philos[i - 1].r_fork = philos[i].l_fork;
		i++;
	}
	pthread_mutex_init(&table->write, NULL);
	pthread_mutex_init(&table->mutex_dead, NULL);
	return (philos);
}

int	get_args(int argc, char **argv, t_table *table)
{
	table->n_philos = ft_atoi_check(argv[1]);
	table->time_to_die = ft_atoi_check(argv[2]);
	table->time_to_eat = ft_atoi_check(argv[3]);
	table->time_to_sleep = ft_atoi_check(argv[4]);
	if (argc == 6)
		table->quant_food = ft_atoi_check(argv[5]);
	else
		table->quant_food = -1;
	if ((table->quant_food < 1 && argc == 6) || table->n_philos < 1
		|| table->time_to_die < 0
		|| table->time_to_eat < 0 || table->time_to_sleep < 0)
	{
			// error();
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;
	t_philo	a;
	int		i;

	i = -1;
	if (argc == 5 || argc == 6)
	{
		if (!get_args(argc, argv, &table))
		{
			table.dead = 0;
			table.philos = create_philos(&table, &a);
			philosophate(&table);
		}
	}
	// pthread_mutex_lock(&table.mutex_dead);
	// pthread_create(&table.death, NULL, &dead_yet, (void *)&table);
	// pthread_mutex_unlock(&table.mutex_dead);
	// pthread_join(table.death, NULL);
	// while (++i < table.n_philos)
	// {
	// 	if (pthread_join(table.philos[i].th, NULL) != 0)
	// 		return (0);
	// }
	return (0);
}