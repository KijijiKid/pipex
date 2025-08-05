/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:59:08 by mandre            #+#    #+#             */
/*   Updated: 2025/08/05 21:16:47 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//Includes -- BEGIN
# include <stdio.h>
# include <unistd.h>
# include "../modules/my_libft/libft.h"
//Includes -- END




//Input parsing
void	inpt_parsing(int argc, char **argv);

//Error Funcions
void	set_error(int new_status);
void	throw_error(void);

#endif