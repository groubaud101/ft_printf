/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:04:15 by groubaud          #+#    #+#             */
/*   Updated: 2021/05/12 17:57:32 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_u_intlen_base(unsigned int n, int len_base)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / len_base;
		len++;
	}
	return (len);
}

int	ft_u_longlen_base(unsigned long n, int len_base)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / len_base;
		len++;
	}
	return (len);
}

int	ft_u_longlonglen_base(unsigned long long n, int len_base)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / len_base;
		len++;
	}
	return (len);
}

int	ft_nbrlen_base(int n, int len_base)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / len_base;
		len++;
	}
	return (len);
}
