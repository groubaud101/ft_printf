/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroubau <guroubau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:13:02 by guroubau          #+#    #+#             */
/*   Updated: 2021/04/16 20:13:02 by guroubau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isinstr(char c, const char *str)
{
	int		index;

	if (c == '\0')
		return (-1);
	index = 0;
	while (str[index])
	{
		if (c == str[index])
			return (index);
		index++;
	}
	return (-1);
}
