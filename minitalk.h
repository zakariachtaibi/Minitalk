/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchtaibi <zchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:15:14 by zchtaibi          #+#    #+#             */
/*   Updated: 2024/04/27 17:06:11 by zchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_isdigit(int c);
int		ft_isAlldigit(char *str);
int		ft_atoi(const char *nptr);
void	ft_putchar(char c);
void	ft_putnbr(int nb);


#endif