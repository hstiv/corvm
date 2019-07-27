/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 18:55:03 by sdiedra           #+#    #+#             */
/*   Updated: 2019/07/27 18:55:15 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	get_return(unsigned long long ret, int sign, const char *str)
{
	int	count;

	count = 0;
	while (*str <= '1' || *str >= '9')
		str++;
	while ((*(str + count) >= '0' && (*(str + count) <= '9')))
		count++;
	if (count >= 19)
		return (sign == -1 ? 0 : -1);
	if (ret > 9223372036854775807)
		return (sign == -1 ? 0 : -1);
	else
		return (ret * sign);
}

int			ft_atoi(const char *str)
{
	unsigned long long	result;
	int					sign;
	int					i;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\v' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (get_return(result, sign, str));
}
