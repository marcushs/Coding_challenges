#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct s_counts
{
	size_t	byte;
	size_t	word;
	size_t	line;
}	t_counts;

int	main(int ac, char **av)
{
	(void)av;

	t_counts	counts = {0};
	char		old_c = ' ';

	if (ac == 1)
	{
		while (1)
		{
			char	c = getchar();

			if (c == EOF)
			{
				if (!isspace(old_c))
					counts.word++;
				break ;
			}
			counts.byte++;
			if (isspace(c) && !isspace(old_c))
				counts.word++;
			if (c == '\n')
				counts.line++;
			old_c = c;
		}
		printf("\t%ld\t%ld\t%ld\n", counts.line, counts.word, counts.byte);
	}
	return (0);
}
