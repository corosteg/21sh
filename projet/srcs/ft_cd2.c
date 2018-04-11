/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 20:20:38 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/11 15:41:26 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int			ft_get_cd(char **command2)
{
	int		cd;

	cd = 0;
	if (command2[1])
	{
		if ((ft_strcmp(command2[1], "~")) == 0)
			cd = 1;
		else if ((ft_strcmp(command2[1], "~/")) == 0)
			cd = 3;
		else if ((ft_strcmp(command2[1], "-")) == 0)
			cd = 2;
		else if ((ft_strcmp(command2[1], "--")) == 0)
			cd = 1;
	}
	return (cd);
}

t_env		*ft_cd_home(char **command2, t_env *env, t_shell *info)
{
	char	*oldpwd;
	char	*path;
	char	*tmp;
	char	cwd[1024];

	oldpwd = NULL;
	path = NULL;
	oldpwd = getcwd(cwd, sizeof(cwd));
	env = set_env(oldpwd, env, "OLDPWD", 2);
	if ((path = findhome(env)) != NULL)
	{
		tmp = ft_strdup(&path[5]);
		if (chdir(tmp) != 0 && command2[1])
			cd_error(1, command2[1], info);
		free(path);
		free(tmp);
		getcwd(cwd, sizeof(cwd));
		env = set_env(cwd, env, "PWD", 1);
	}
	else
		cd_error(2, "HOME not set\n", info);
	return (env);
}

t_env		*ft_cd_oldpwd(char **command2, t_env *env, t_shell *info)
{
	char	*oldpwd;
	char	*path;
	char	*tmp;
	char	cwd[1024];

	oldpwd = NULL;
	path = NULL;
	if ((path = findoldpwd(env)) != NULL)
	{
		oldpwd = getcwd(cwd, sizeof(cwd));
		env = set_env(oldpwd, env, "OLDPWD", 2);
		tmp = path;
		path = ft_strdup(&path[7]);
		free(tmp);
		ft_print("%s\n", path);
		if (chdir(path) != 0)
			cd_error(1, command2[1], info);
		free(path);
		getcwd(cwd, sizeof(cwd));
		env = set_env(cwd, env, "PWD", 1);
	}
	else
		cd_error(2, "OLDPWD not set\n", info);
	return (env);
}

t_env		*ft_cd(char *command2, t_env *env, t_shell *info)
{
	char	*oldpwd;
	char	*path;
	char	cwd[1024];

	oldpwd = NULL;
	path = NULL;
	oldpwd = getcwd(cwd, sizeof(cwd));
	env = set_env(oldpwd, env, "OLDPWD", 2);
	path = ft_strdup(command2);
	if (chdir(path) != 0)
		cd_error(3, command2, info);
	getcwd(cwd, sizeof(cwd));
	free(path);
	env = set_env(cwd, env, "PWD", 1);
	return (env);
}

t_env		*ft_cd_pars(char **command2, t_env *env, int i, t_shell *info)
{
	int		arg;
	int		cd;
	char	*home;

	home = NULL;
	arg = ft_get_arg(command2);
	cd = ft_get_cd(command2);
	if (arg > 3)
		cd_error(2, "cd: too many arguments\n", info);
	else if (arg == 3)
		cd_error(3, command2[1], info);
	else
	{
		if (cd == 1 || arg < 2)
			env = ft_cd_home(command2, env, info);
		else if (cd == 2)
			env = ft_cd_oldpwd(command2, env, info);
		else if ((cd == 3) && (!(home = findhome(env))))
			cd_error(2, "HOME not set\n", info);
		else if ((command2[1] != NULL && cd != 1 && cd != 2 && cd == 3))
			env = ft_cd(home_path(home, command2[1]), env, info);
		else if ((command2[1] != NULL && cd != 1 && cd != 2) || i != 0)
			env = ft_cd(command2[1], env, info);
	}
	return (env);
}
