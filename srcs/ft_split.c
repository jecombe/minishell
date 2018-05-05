#include <stdlib.h>
#include <stdio.h>

int ft_count_word(char *str)
{
	int len;
	len = 0;
	while (*str)
	{
		while (*str && *str == ':')
			str++;
		if (*str && *str != ':')
		{
			len++;
			while (*str && *str != ':')
				str++;
		}
	}
	return (len);
}

char  *ft_malloc(char *str)
{
	char *word;
	int i;
	i = 0;
	while (str[i] && str[i] != ':')
	{
		i++;
	}
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;

	while (str[i] && str[i] != ':')
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return(word);
		

}

char **ft_split(char *str)
{
	char **result;
	int len;
	int i;
	i = 0;

	len = ft_count_word(str);
	result = (char **)malloc(sizeof(char *) * (len + 1));
	while (*str)
	{
		while (*str && *str == ':')
			str++;
		if (*str && *str != ':')
		{
			result[i] = ft_malloc(str);
			i++;
			while (*str && *str != ':')
				str++;
			
		}

	}
	result[i] = NULL;
	return (result);
}
