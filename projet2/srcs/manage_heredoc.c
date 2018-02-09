#include "21sh.h"

static int		need_a_break(char *s1, char *s2)
{
	int		i;
	char	*tmp;

	i = ft_strlen(s1);
	while (i > 0 && s1[i - 1] != '\n')
		i--;
	if (!(ft_strcmp(&s1[i], s2)))
	{
		s1[i] = '\0';
		return(1);
	}
	return (0);
}

char			*manage_heredoc(t_shell *info, char *end)
{
	int		buf;
	char	*ret;

	ft_print("\nheredoc>");
	info->quote_len = 6;
	info->len++;
	info->x = 6;
	free(info->command);
	info->command = ft_strdup("\0");
	while (42)
	{
		buf = 0;
		if (read(0, &buf, sizeof(int)))
		{
			if (check_press_quote(buf, info))
			{
				if (need_a_break(info->command, end))
					break;
				ft_print("\nheredoc>");
				info->command = ft_strfreejoin(info->command, "\n", 1);
				info->len++;
				info->quote_len = 6;
				info->x = 6;
			}
		}
	}
	buf = open("/tmp/21sh_heredoc", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	ft_putstr_fd(info->command, buf);
	free(end);
	return (ft_strdup("/tmp/21sh_heredoc"));
}
