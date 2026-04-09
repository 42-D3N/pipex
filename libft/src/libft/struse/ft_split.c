/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:08:38 by tle-pape          #+#    #+#             */
/*   Updated: 2024/10/26 11:31:03 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			len++;
		while (s[i] != c && s[i])
			i++;
	}
	return (len);
}

static int	ft_strlen_c(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	**free_arr(int i, char **arr)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		nbword;
	int		len;
	char	**arr;

	i = 0;
	nbword = count_word(s, c);
	arr = malloc(sizeof(char *) * (nbword + 1));
	if (!arr)
		return (NULL);
	while (i < nbword)
	{
		while (*s == c && *s)
			s++;
		len = ft_strlen_c((char *) s, c);
		arr[i] = ft_substr(s, 0, len);
		if (!arr[i])
			return (free_arr(i, arr));
		s += len;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
/*
-----------------------------------COUNT_WORD-----------------------------------
This function allow you to count all words are in the original string.
Run through the original string.
- Until the function found the separator, increment.
- If the current character is not empty, that mean this is the start of a word
so increment len.
- Until the function don't find the separator, increment i as long as he found
the separator, or until the end of the string.
Return the len, so the number of word found.

----------------------------------FT_STRLEN_C-----------------------------------
This function is a slightly different version of strlen that stop when separator
is found in the string.

-----------------------------------FREE_ARR-------------------------------------
This function allow to delete the entire memory allocated to **arr if there is 
any malloc error in the main function.

-----------------------------------FT_SPLIT-------------------------------------
Start by calling "count_word" to get the number of string to allocate in arr.
Use malloc to allocate the number of strings + 1 to add NULL pointer at the end
of arr.
If malloc failed, return NULL.

While there is words to get,
- Go in the second while until all separator are passed.
-- Increment the pointer.
- Get the lengh of the word with "ft_strlen_c".
- Add to arr the new word by using "ft_substr".
- Check if the malloc fail, if yes, call "free_arr".
- Increment the pointer to go after the word that have been created.
Add the pointer to NULL at the end of arr and return arr.
*/
