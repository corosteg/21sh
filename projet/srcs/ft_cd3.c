/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:09:38 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/12 15:20:29 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			cd_error(int i, char *str, t_shell *info)
{
	if (i == 1)
	{
		ft_putstr_fd("cd: no such file or directory : ", info->fd_err);
		ft_putstr_fd(str, info->fd_err);
		ft_putstr_fd("\n", info->fd_err);
	}
	if (i == 2)
	{
		ft_putstr_fd(str, info->fd_err);
		ft_putstr_fd("\n", info->fd_err);
	}
	if (i == 3)
	{
		ft_putstr_fd("cd: string not in pwd: ", info->fd_err);
		ft_putstr_fd(str, info->fd_err);
		ft_putstr_fd("\n", info->fd_err);
	}
}

char		*path(char *dest, char *src)
{
	char		*new;

	new = ft_strdup(dest);
	new = ft_strfreejoin(new, &src[1], 1);
	free(dest);
	return (new);
}
