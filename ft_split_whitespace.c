/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:01:30 by nlewicki          #+#    #+#             */
/*   Updated: 2025/05/16 12:01:49 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && !ft_isspace(s[i]))
			words++;
		else if (i > 0 && !ft_isspace(s[i]) && ft_isspace(s[i - 1]))
			words++;
		i++;
	}
	return (words);
}

static char	*ft_copywords(char const *s)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	j = 0;
	while (!ft_isspace(s[i]) && s[i] != '\0')
		i++;
	word = malloc((i + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	while (j < i)
	{
		word[j] = s[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

static void	ft_free(int j, char **result)
{
	if (result == NULL)
		return ;
	while (j >= 0)
	{
		free(result[j]);
		j--;
	}
	free(result);
}

static void	ft_processwords(char const *s, char **result)
{
	int	j;

	j = 0;
	while (*s != '\0')
	{
		if (!ft_isspace(*s))
		{
			result[j] = ft_copywords(s);
			if (result[j] == NULL)
			{
				ft_free(j, result);
				return ;
			}
			j++;
			while (!ft_isspace(*s) && *s != '\0')
				s++;
		}
		else
			s++;
	}
}

char	**ft_split_whitespace(char const *s)
{
	int		words;
	char	**result;

	words = ft_countwords(s);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (result == NULL)
		return (NULL);
	ft_processwords(s, result);
	result[words] = (NULL);
	return (result);
}
