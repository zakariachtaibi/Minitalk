/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchtaibi <zchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:59:35 by zchtaibi          #+#    #+#             */
/*   Updated: 2024/04/28 17:46:42 by zchtaibi         ###   ########.fr       */
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
			kill(info->si_pid, SIGUSR1);
		else
			write(1, &current_char, 1);
		current_char = 0;
		bit_index = 0;
	}
	else
		current_char <<= 1;
	//kill(info->si_pid, signum);
}

int	main(void)
{
	pid_t pid;
	struct sigaction sigl;

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
	return (0);
}