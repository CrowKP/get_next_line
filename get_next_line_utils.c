/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:58:30 by aigarcia          #+#    #+#             */

/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	it;

	it = 0;
	if (!str)
		return (0);
	while (str[it] != '\0')
		it++;
	return (it);
}

char	*ft_joinit(char *str, char *left_str, char *buff)
{
	int	it;
	int	jt;

	it = 0;
	jt = 0;
	if (left_str[0] != '\0')
		while (left_str[it] != '\0')
			str[it++] = left_str[jt++];
	jt = 0;
	while (buff[jt] != '\0')
		str[it++] = buff[jt++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	return (str);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		if (!left_str)
			return (0);
		left_str[0] = '\0';
	}
	if (!buff)
	{
		free(left_str);
		return (0);
	}
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (!str)
	{
		free(left_str);
		return (0);
	}
	str = ft_joinit(str, left_str, buff);
	free(left_str);
	return (str);
}

char	*ft_get_line(char *left_str)
{
	int		it;
	char	*str;

	it = 0;
	if (!left_str)
		return (0);
	while (left_str[it] && left_str[it] != '\n')
		it++;
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) + 1));
	if (!str)
	{
		free(left_str);
		return (0);
	}
	it = 0;
	while (left_str[it] && left_str[it] != '\n')
	{
		str[it] = left_str[it];
		it++;
	}
	if (left_str[it] == '\n')
	{
		str[it] = left_str[it];
		it++;
	}
	str[it] = '\0';
	return (str);
}

char	*ft_new_left_str(char *left_str)
{
	int		it;
	int		jt;
	char	*str;

	it = 0;
	while (left_str[it] && left_str[it] != '\n')
		it++;
	if (!left_str[it])
	{
		free(left_str);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - it + 1));
	if (!str)
		return (0);
	it++;
	jt = 0;
	while (left_str[it])
		str[jt++] = left_str[it++];
	str[jt] = '\0';
	free(left_str);
	return (str);
}
