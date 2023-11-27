#include <stdio.h>
char	*go_str(char *fff)
{
	char	*str;
	
	str = fff;
	return (str);
}


int	main()
{
	char	*str;
	char	*fff;

	fff = "hello";
	str = go_str(fff);

	printf("%s\n", str);
	return (0);	
}
