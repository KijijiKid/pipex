/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 21:03:09 by mandre            #+#    #+#             */
/*   Updated: 2025/08/06 16:25:15 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	*get_error(void)
{
	static int	status = 0;

	return (&status);
}

/// @brief By passing a int value as
/// parameter to the fucntion 
/// you can set an error case -> see in throw_error.
///	One thing the function does automatically is to
/// check if the status is already set before.
/// If so set_error calss throw_error()
/// @param new_status Error Status
void	set_error(int new_status)
{
	int	*status;

	status = get_error();
	if (*status != 0)
		throw_error();
	*status = new_status;
}

/// @brief If status set via set_error()
/// is not 0 a error message gets displayed and
/// the program exits.  
void	throw_error(void)
{
	int	*status;

	status = get_error();
	if (*status == 1)
		perror("Syntax isn't correct.");
	else if (*status == 2)
		perror("Fork failed.");
	else if (*status == 3)
		perror("Pipe creation failed.");
	else if (*status == 4)
		perror("Execve failed.");
	else if (*status == 20)
		perror("An undefined Error occured.");
	if (*status != 0)
		exit(*status);
}
