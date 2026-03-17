#include "3-calc.h"

/**
* main - Effectue l'opération demandée
* @argc: nombre d'arguments
* @argv: tableau des arguments
* Return: 0 en cas de succès, exit avec status sinon
*/
int main(int argc, char *argv[])
{
	int num1, num2, result;

	int (*operation)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);

	operation = get_op_func(argv[2]);

	if (operation == NULL || argv[2][1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}

	if ((argv[2][0] == '/' || argv[2][0] == '%') && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}

	result = operation(num1, num2);
	printf("%d\n", result);

	return (0);
}
