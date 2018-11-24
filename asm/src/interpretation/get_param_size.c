/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:31:43 by achernys          #+#    #+#             */
/*   Updated: 2018/11/07 16:34:53 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	i_get_param_size(char param, char dir_size)
{
	if (param == 1)
		return (1);
	if (param == 2)
		return (dir_size);
	if (param == 3)
		return (2);
	return (0);
}

char	i_get_all_param_size(char *params, char dir_size)
{
	int		i;
	char	param_size_sum;

	param_size_sum = 0;
	i = 0;
	while (i < 3)
	{
		param_size_sum += i_get_param_size(params[i], dir_size);
		i++;
	}
	return (param_size_sum);
}
