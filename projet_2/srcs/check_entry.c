/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:08:34 by corosteg          #+#    #+#             */
/*   Updated: 2017/10/27 20:42:14 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

char			*ft_chardup(int c)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	str[1] = '\0';
	str[0] = c;
	return (str);
}

int				check_press(int buf, t_shell *info)
{
	char	str[2];

	str[0] = (char)buf;
	str[1] = '\0';
	if (buf == 2117294875)
		p_delete(info);
	else if (buf == 4479771 && (info->len > 0))
		return (p_left(info));
//	if (buf == 4283163)
//		list_up(list);
	else if (buf == 4414235 && ((info->len) < ft_strlen(info->command)))
		p_right(info);
//	if (buf == 4348699)
//		list_down(list);
	if (buf == 32)
		p_space(info);
//	if (buf == 27)
//		esc_press(list);
//	if (buf == 10)
//		final_print(list);
	else if  (buf == 127 && info->len > 0)
		p_backspace(info);
	else if ((buf > 32 && buf < 126) && (info->len == ft_strlen(info->command)))
		p_ascii(info, str, buf);
	else if ((buf > 32 && buf < 126) && (info->len < ft_strlen(info->command) - 1))
		return (insert_ascii(info, str));
	else if (buf == 10)
		return (1);
	//printf("buf == %i\n", buf);
	//printf("y == %i\n", info->y);
	return (0);
}

char			*check_entry(t_shell *info)
{
	//char	*entry;
	int		buf;

	//entry = NULL;
	//tgoto(tgetstr("cm", NULL), 0, 0);
	tputs(tgetstr("im", NULL), 1, ft_putchar);
	//printf("%i\n", info->x);
	while (42)
	{
		buf = 0;
		if (read(0, &buf, sizeof(int)))
		{
			if (check_press(buf, info))
				break ;
		}
	}
	tputs(tgetstr("ei", NULL), 1, ft_putchar);
	ft_print("\n    ");
	ft_print("%s\n", info->command);
	return (NULL);
}
