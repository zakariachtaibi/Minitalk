/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchtaibi <zchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:59:38 by zchtaibi          #+#    #+#             */
/*   Updated: 2024/04/28 17:57:10 by zchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_byte(pid_t pid_server, unsigned char cr)
{
	int				i;
	unsigned char	temp;

	i = 8;
	temp = cr;
	while (i > 0)
	{
		i--;
		temp = cr >> i;
		if (temp % 2 == 0)
		{
			kill(pid_server, SIGUSR2);
		}
		else
			kill(pid_server, SIGUSR1);
		usleep(100);
	}
}

void	send_string(pid_t pid_server, char *str)
{
	while (*str)
	{
		send_byte(pid_server, *str);
		str++;
	}
	send_byte(pid_server, '\0');
}
void	recieve_handler(int signum)
{
	if(signum == SIGUSR1)
		write(1, "message recieved\n", 18);
}
int	main(int ac, char **av)
{
	pid_t pid_server;
	char *str;

	signal(SIGUSR1, recieve_handler);
	if (ac != 3)
	{
		write(2, "Error! 2 arguments are required! {pid} {string to send}\n",
			57);
		return (0);
	}
	if (!ft_isAlldigit(av[1]))
	{
		write(2, "not a valid number\n", 20);
		return (1);
	}
	pid_server = ft_atoi(av[1]);
	str = av[2];
	if (kill(pid_server, 0) == -1)
	{
		write(2, "not a valid pid server\n", 25);
		exit(1);
	}
	send_string(pid_server, str);
	return (0);
}