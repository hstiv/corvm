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


char				*ft_strnew(size_t size)
{
	char			*str;

	str = (char *)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	ft_memset(str, 0, size + 1);
	return (str);
}

void				*ft_memcpy(void *dest, const void *source, size_t n)
{
	size_t			i;

	i = -1;
	if (source == dest || n == 0)
		return (dest);
	while (++i < n)
		*((unsigned char *)dest + i) = *((unsigned char *)source + i);
	return (dest);
}

void				*ft_memmove(void *dest, const void *source, size_t len)
{
	size_t			i;

	if (source == dest)
		return (dest);
	if (source < dest)
	{
		i = len;
		while (i-- > 0)
			*(unsigned char *)(dest + i) = *(unsigned char *)(source + i);
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(source + i);
			i++;
		}
	}
	return (dest);
}

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (s[start] != '\0' && len)
	{
		str[i] = s[start];
		start++;
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}

void				*ft_memset(void *b, int c, size_t len)
{
	size_t			i;

	i = 0;
	if (len == 0)
		return (b);
	while (i < len)
		*((unsigned char *)b + i++) = c;
	return (b);
}
