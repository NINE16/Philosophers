/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:06:15 by nemethnikol       #+#    #+#             */
/*   Updated: 2022/09/09 18:45:06 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

# define MAX_INT 2147483647

# define GREEN "\033[0;32m"
# define YELLOW 
# define RED "\033[0;31m"

typedef struct s_table	t_table;

typedef struct s_philo
{
	t_table			*table;
	int				next;
	int				last_meal;
	int				wait;
	int				n_meals;
	int				id;
	size_t			now;
	long int		start_time;
	pthread_t		th;
	pthread_mutex_t	fork;
	// pthread_mutex_t	r_fork;
}	t_philo;

typedef struct s_table
{
	t_philo			*philos;
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				quant_food;
	pthread_mutex_t	write;
	pthread_mutex_t mutex_dead;
	pthread_t		death;
	bool			dead;
	int				max_eat;
}	t_table;

int			ft_atoi_check(char *str);
int			ft_isdigit(int c);
int		get_args(int argc, char **argv, t_table *table);
t_philo		*create_philos(t_table *table, t_philo *a);
int			philosophate(t_table *table);
void		*philo_life(void *data);
void		error(void);
int			ft_set_now();
int 		ft_set_time(t_philo *a);
int			take_fork(t_philo *philo, t_table *table);
void		write_status(char *str, t_philo *philo);
void		sleeping(t_philo *philo, t_table *table);
void		ft_usleep(long int time_ms, t_philo *a);
void		*dead_yet(void *data);
void		one_philo(t_philo *philo);
long int 	time_check(void);
int			ft_exit(void);

#endif