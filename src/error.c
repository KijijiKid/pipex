/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 21:03:09 by mandre            #+#    #+#             */
/*   Updated: 2025/08/05 21:17:33 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	*get_error(void)
{
	static int	status = 0;

	return (&status);
}

void	set_error(int new_status)
{
	int	*status;

	status = get_error();
	*status = new_status;
}

void	throw_error(void)
{
	int	*status;

	status = get_error();
	if (*status == 1)
		perror("Syntax isn't correct.");
	
	if (*status != 0)
		exit(*status);
}
