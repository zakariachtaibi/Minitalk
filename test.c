/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchtaibi <zchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:05:30 by zchtaibi          #+#    #+#             */
/*   Updated: 2024/05/01 20:09:22 by zchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void sig_handler(int signum)
{
    if (signum == SIGINT)
        write(1, "hello\n", 6);
}

int main()
{
    if (signal(SIGINT, sig_handler) == SIG_ERR)
        write(1, "error\n", 6);
    while (1)
        sleep(1);
    return (0);
}