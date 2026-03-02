#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

/**
 * next_value - generates the next pseudo-random value
 * @state: pointer to the current state
 * Return: next value
 */
static unsigned int next_value(unsigned int *state)
{
	*state = (*state * 1103515245u) + 12345u;
	return *state;
}

/**
 * build_dataset - fills the array
 */
static void build_dataset(void)
{
	unsigned int state;
	int i;

	state = SEED_VALUE;
	for (i = 0; i < DATASET_SIZE; i++)
		dataset[i] = (int)(next_value(&state) % 100000);
}

/**
 * process_dataset - processes the array
 */
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

/**
 * reduce_checksum - calculates checksum
 * Return: the checksum
 */
static unsigned long reduce_checksum(void)
{
	unsigned long sum;
	int i;

	sum = 0;
	for (i = 0; i < DATASET_SIZE; i++)
		sum = (sum * 131ul) + (unsigned long)dataset[i];
	return sum;
}

/**
 * main - entry point
 * Return: Always 0
 */
int main(void)
{
	unsigned long checksum;
	clock_t t_total_start, t_total_end;
	clock_t t_phase_start, t_phase_end;
	double d_total, d_build, d_process, d_reduce;

	t_total_start = clock();

	t_phase_start = clock();
	build_dataset();
	t_phase_end = clock();
	d_build = (double)(t_phase_end - t_phase_start) / CLOCKS_PER_SEC;

	t_phase_start = clock();
	process_dataset();
	t_phase_end = clock();
	d_process = (double)(t_phase_end - t_phase_start) / CLOCKS_PER_SEC;

	t_phase_start = clock();
	checksum = reduce_checksum();
	t_phase_end = clock();
	d_reduce = (double)(t_phase_end - t_phase_start) / CLOCKS_PER_SEC;

	t_total_end = clock();
	d_total = (double)(t_total_end - t_total_start) / CLOCKS_PER_SEC;

	if (checksum == 0ul)
		printf("impossible\n");

	printf("TOTAL seconds: %.6f\n", d_total);
	printf("BUILD_DATA seconds: %.6f\n", d_build);
	printf("PROCESS seconds: %.6f\n", d_process);
	printf("REDUCE seconds: %.6f\n", d_reduce);

	return 0;
}