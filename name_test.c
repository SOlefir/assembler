#include <stdio.h>

#include <string.h>
# define NAME_CMD_STRING		".name"

size_t	ft_strlen(const char *s)
{
	size_t ans;

	if (!s)
		return (0);
	ans = 0;
	while (s[ans])
		ans++;
	return (ans);
}

_Bool	is_name(char *str)
{
	int 	i;
	int		len_cmd;

	i = 0;
	i = ft_strlen(NAME_CMD_STRING);
	while (--i)
		if (str[i] != NAME_CMD_STRING[i])
			return (0);
	return (1);
}

int		main(void)
{
	char *str;

	str = ".na me   The spiderman";
	if (is_name(str))
		printf("true\n");
	else
		printf("f\n");
	return (0);
}
