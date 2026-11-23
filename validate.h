/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:08:02 by maratana          #+#    #+#             */
/*   Updated: 2026/11/04 17:28:11 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

# include "utils.h"

int	is_flag(char *s, t_bench *bench);
int	validate_input(char **argv, t_bench *bench);

#endif