#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	char *ptr;
	size_t i;

	ptr = malloc(SIZE_MAX);
	if (ptr == NULL)
		dprintf(2, "WARNING NULL\n");
	for (i = 0; i < SIZE_MAX; i++)
	{
		ptr[i] = 'a';
	}
	free(ptr);
	return (0);
}
