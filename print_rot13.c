#include "main.h"
/**
 * print_R - convert string to rot13
 * @list: argument passed
 * @buffer: values stored
 * @indx: tracks indx position
 */
void print_R(va_list list, char *buffer, int *indx)
{
	char *s;
	int i, j;

	char *s1 = "abcdefghijklmABCDEFGHIJKLM ,?!;'@-=+\"\\$%^&*()`~<>/:[]{}_|.\n";
	char *s2 = "nopqrstuvwxyzNOPQRSTUVWXYZ ,?!;'@-=+\"\\$%^&*()`~<>/:[]{}_|.\n";

	s = va_arg(list, char *);
	for (i = 0; s[i] != '\0'; i++, *indx += 1)
	{
		for (j = 0; s1[j] != '\0'; j++)
		{
			if (s[i] == s1[j])
			{
				buffer[*indx] = s2[j];
			}
			else if (s[i] == s2[j])
			{
				buffer[*indx] = s1[j];
			}
		}
	}
}
