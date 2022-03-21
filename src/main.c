/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 16:02:24 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/21 19:51:12 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bingo.h"

int32_t random_int(int32_t min, int32_t max)
{
   return min + rand() % (max + 1 - min);
}

int32_t	main(void)
{
	int32_t DrawCount = 0;
	int32_t Numbers[NUM_COUNT];

	srand(time(NULL));
	memset(Numbers, -1, NUM_COUNT * sizeof(int32_t));
	while (DrawCount < 99)
	{
		system("clear");
		int32_t Draw = random_int(1, 99);

		if (Numbers[Draw - 1] != -1)
			continue;
		Numbers[Draw - 1] = Draw;
		DrawCount++;

		printf("Number: %d\n", Draw);
		char key = getchar();

		if (key == 'b') // Quit
			break;
		else if (key == 'd')
		{
			printf("CHECK: ");
			for (int32_t i = 0; i < NUM_COUNT; i++)
				if (Numbers[i] != -1)
					printf("%d  ", Numbers[i]);

			// W t f
			getchar();
			getchar();
			fflush(stdout);
		}
	}
	puts("Bingo OVER\n");
}
