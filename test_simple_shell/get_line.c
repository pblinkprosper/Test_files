#include <stdio.h>


/**
 * main - this function gets the input on the shell
 *
 * Return: it returns the character
 */
int main(void)
{
	size_t n;
	char *buffer = NULL;

	printf("Enter name: ");
	getline(&buffer, &n, stdin);

	printf("Your name is %sThe Buffer is %ld\n", buffer, n);

	free(buffer);
	return (0);
}
