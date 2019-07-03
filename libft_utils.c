//
// Created by hstiv on 03.07.19.
//

#include "corvm.h"

int			ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int			ft_atoi_if(int sign)
{
	if (sign > 0)
		return (-1);
	return (0);
}

static int			ft_atoi_maker(int sign, const char *n)
{
	int				res;
	int				check;

	res = 0;
	check = 0;
	while (48 <= *n && *n <= 57)
	{
		check = res;
		res *= 10;
		if (check != res / 10)
			return (ft_atoi_if(sign));
		res += *n - '0';
		n++;
		if (res < 0)
			return (ft_atoi_if(sign));
	}
	return (res * sign);
}

int					ft_atoi(const char *n)
{
	int				sign;

	sign = 1;
	while ((9 <= *n && *n <= 13) || *n == 32)
		n++;
	if (*n == '-' || *n == '+')
	{
		if (*n == '-')
			sign = -1;
		n++;
	}
	return (ft_atoi_maker(sign, n));
}

int					ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
		return (ft_strcmp(s1, s2) == 0 ? 1 : 0);
	return (0);
}

int					ft_isdigit(char *s)
{
	int				i;

	i = (s[0] == '-') ? 1 : 0;
	while (s[i])
	{
		if (!(s[i] >= 48 && s[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}

int					ft_strcmp(const char *s1, const char *s2)
{
	while (*s1)
		if (*s1++ - *s2++ != 0)
			return ((unsigned char)*(s1 - 1) - (unsigned char)*(s2 - 1));
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
