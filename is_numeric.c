/**
 * is_numeric - Checks if a string is a numeric value
 * @str: The string to check
 * Return: 1 if numeric, 0 otherwise
 */

int is_numeric(const char *str)
{
	int i = 0;    if (!str)
		return (0);    if (str[0] == '-')
		i++;    for (; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}    return (1);
}
