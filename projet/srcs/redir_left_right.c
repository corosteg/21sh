#include "21sh.h"

t_parselex			*redir_left_and_right(t_shell *info, t_parselex *list,
					t_parselex *first)
{
	int		fd;
	char	*ta[3];


	if (list->next->next == NULL)
		return (NULL);
	ta[0] = ft_strdup("/bin/cat");
	ta[1] = ft_strdup(list->next->next->cutting[0]);
	ta[2] = NULL;
	exec_in_pipe(ta, info, first, 0);
	fd = open(list->next->next->next->next->cutting[0], O_CREAT | O_TRUNC
		| O_WRONLY, 0644);
	exec_redir(list->cutting, info, fd, first);
	while (list && !(end_token_tool(list->cutting[0])))
		list = list->next;
	reset_fd_tool(info);
	return (list);
}
