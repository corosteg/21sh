
#include "sh.h"

static void		parse_dquote2(t_shell *info, int c, int d)
{
	info->command[c] = ' ';
	info->command[d] = ' ';
}

void			parse_dquote(t_shell *info, int i, int b, int c)
{
	int			d;

	while (info->command[i + 1] && info->command[i] != '\"')
		i++;
	while (b > 1 && b > i && info->command[b] != '\"')
		b--;
	c = i;
	d = b;
	i++;
	b--;
	while (info->command[i] && b > 0 && b > i)
	{
		if (info->command[i] == '\"' && info->command[b] == '\"')
		{
			parse_dquote2(info, c, d);
			c = i;
			d = b;
			b--;
			i++;
		}
		if (info->command[b] != '\"')
			b--;
		if (info->command[i] != '\"')
			i++;
	}
}

void			parse_squote(t_shell *info, int i, int b, int c)
{
	int			d;

	while (info->command[i + 1] && info->command[i] != '\'')
		i++;
	while (b > 1 && b > i && info->command[b] != '\'')
		b--;
	c = i;
	d = b;
	i++;
	b--;
	while (info->command[i] && b > 0 && b > i)
	{
		if (info->command[i] == '\'' && info->command[b] == '\'')
		{
			parse_dquote2(info, c, d);
			c = i;
			d = b;
			b--;
			i++;
		}
		if (info->command[b] != '\'')
			b--;
		if (info->command[i] != '\'')
			i++;
	}
}

int				parse3(t_shell *info)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (info->command[i])
	{
		if (info->command[i] == ';')
		{
			a = i;
			a++;
			while (info->command[a] == ' ')
				a++;
			if (info->command[a] == ';')
				return (ft_print
				("\n21sh: syntax error near unexpected token ';'\n"));
		}
		i++;
	}
	return (0);
}
