#include <stdio.h>


#include "random.h"

#define NUM_VALUES 250
float values[NUM_VALUES];

int main()
{
	// Note, again types have been updated to support float
	float sum = 0;
	float average;
	float min = 0;
	float max = 0;

	unsigned char i;

	init_random();

	for (i = 0; i < NUM_VALUES; i++) {
		// Ex 3.1 (3/3), The function call is updated to use our new random_float() function
		values[i] = random_float();

		sum += values[i];
		//printf("value = %f, sum = %f\n", values[i], sum);
	}

	average = sum / (float)NUM_VALUES;

	for (i = 0; i < NUM_VALUES; i++) {
		values[i] -= average;
		min = (values[i] < min) ? values[i] : min;
		max = (values[i] > max) ? values[i] : max;
	}

	printf("Sum is %.0f\n", sum);
	printf("Average is %.0f\n", average);
	printf("Min is %.0f\n", min);
	printf("Max is %.0f\n", max);

	return 0;
}
