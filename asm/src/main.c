/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:56:59 by dlewando          #+#    #+#             */
/*   Updated: 2018/11/23 14:32:58 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"
#include "../inc/interpretation.h"
#include "../inc/collect_info.h"
#include "../inc/validation.h"

void	cut_comment(char **s)
{
	int		i;
	char	*str;

	i = 0;
	str = *s;
	while (str[i] != '\0')
	{
		if (str[i] == COMMENT_CHAR
			|| str[i] == ';')
		{
			str[i] = '\0';
			return ;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_public_struct		*public_struct;
	t_i_collect_info	*collect_info;
	int					i;

	i = 1;
	while (i < argc)
	{
		public_struct = init_public_struct(argv[i]);
		v_validation(public_struct);
		c_collect_info(public_struct, &collect_info);
		free_collect_info(collect_info);
		interpretation(public_struct);
		free_public_struct(public_struct);
		i++;
	}
	return (0);
}
