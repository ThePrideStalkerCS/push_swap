/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:08:02 by maratana          #+#    #+#             */
/*   Updated: 2026/11/24 15:49:01 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

# include "utils.h"

int	is_flag(char *s, t_bench *bench);
int	validate_input(char **argv, t_bench *bench);
char	**normalize_args(char **argv, int start);
int	validate_normalized(char **args);
void	free_args(char **args);

#endif