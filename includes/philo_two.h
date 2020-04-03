#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>

# define THINKING 1
# define EATING 2
# define SLEEPING 4
# define DEAD 8
# define TIME 1000

typedef	struct s_data
{
	int n_p;
	int time_to_eat;
	int time_to_die;
	int time_to_sleep;
	int limit;
	int limit_check;
	int dead;
	sem_t	*lock;
	sem_t	*limit_sem;
	sem_t	*forks;
//	pthread_mutex_t lock;
//	pthread_mutex_t limit_mutex;
	int id_dead;
	struct timeval time;
}		t_data;


typedef struct s_ph
{
	int		activity;
	int		n;
	int		i;
	int		limit;
	pthread_t 	thread;
//	pthread_mutex_t fork;
	struct s_ph *prev;
	struct s_ph *next;
	struct s_data *data;
	struct timeval time;
}		t_ph;

void *philo(void *b);
double	get_time(struct timeval ini, struct timeval now);

#endif

