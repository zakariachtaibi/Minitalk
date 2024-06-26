/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchtaibi <zchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:59:35 by zchtaibi          #+#    #+#             */
/*   Updated: 2024/05/01 17:03:18 by zchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signum, siginfo_t *info, void *ptr)
{
	static unsigned char	current_char;
	static int				bit_index;

	(void)ptr;
	(void)info;
	current_char |= (signum == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == '\0')
		{
			kill(info->si_pid, SIGUSR1);
			write(1, "\n", 1);
		}
		else
			write(1, &current_char, 1);
		current_char = 0;
		bit_index = 0;
	}
	else
		current_char <<= 1;
}

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	sigl;

	(void)av;
	if (ac == 1)
	{
		pid = getpid();
		write(1, "Server PID: ", 13);
		ft_putnbr(pid);
		ft_putchar('\n');
		sigl.sa_flags = SA_SIGINFO;
		sigl.sa_sigaction = handle_signal;
		sigaction(SIGUSR1, &sigl, NULL);
		sigaction(SIGUSR2, &sigl, NULL);
		while (1)
			pause();
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
