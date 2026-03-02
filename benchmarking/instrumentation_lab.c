#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

static unsigned int next_value(unsigned int *state)
{
	*state = (*state * 1103515245u) + 12345u;
	return (*state);
}

static void build_dataset(void)
{
	unsigned int state;

	int i;

	state = SEED_VALUE;

	for (i = 0; i < DATASET_SIZE; i++)
		dataset[i] = (int)(next_value(&state) % 100000);
}

static void process_dataset(void)
{
	int i;

	int v;

	for (i = 0; i < DATASET_SIZE; i++)
	{
		v = dataset[i];
		v = (v * 3) + (v / 7) - (v % 11);
		if (v < 0)
			v = -v;
		dataset[i] = v;
	}
}

static unsigned long reduce_checksum(void)
{
	unsigned long sum;

	int i;

	sum = 0;
	for (i = 0; i < DATASET_SIZE; i++)
		sum = (sum * 131ul) + (unsigned long)dataset[i];

	return (sum);
}

int main(void)
{
	unsigned long checksum;

	clock_t t_start, t_end, p_start, p_end;
	double total_t, build_t, process_t, reduce_t;

	t_start = clock();

	/* Mesure BUILD_DATA */
	p_start = clock();
	build_dataset();
	p_end = clock();
	build_t = (double)(p_end - p_start) / CLOCKS_PER_SEC;

	/* Mesure PROCESS */
	p_start = clock();
	process_dataset();
	p_end = clock();
	process_t = (double)(p_end - p_start) / CLOCKS_PER_SEC;

	/* Mesure REDUCE */
	p_start = clock();
	checksum = reduce_checksum();
	p_end = clock();
	reduce_t = (double)(p_end - p_start) / CLOCKS_PER_SEC;

	t_end = clock();
	total_t = (double)(t_end - t_start) / CLOCKS_PER_SEC;

	if (checksum == 0ul)
		printf("impossible\n");

	printf("TOTAL seconds: %.6f\n", total_t);
	printf("BUILD_DATA seconds: %.6f\n", build_t);
	printf("PROCESS seconds: %.6f\n", process_t);
	printf("REDUCE seconds: %.6f\n", reduce_t);

	return (0);
}
