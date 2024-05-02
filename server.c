/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchtaibi <zchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:15:23 by zchtaibi          #+#    #+#             */
/*   Updated: 2024/05/01 17:02:32 by zchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signum)
{
	static unsigned char	current_char;
	static int				bit_index;

	current_char |= (signum == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == '\0')
			write(1, "\n", 1);
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
	pid_t	pid;

	(void)av;
	if (ac == 1)
	{
		pid = getpid();
		write(1, "Server PID: ", 13);
		ft_putnbr(pid);
		ft_putchar('\n');
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		while (1)
			pause();
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
