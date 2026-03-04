#include <stdio.h>

/**
 * PerformOperation - executes the selected arithmetic operation
 * @choice: the operation integer selected by the user
 *
 * Return: void
 */

void PerformOperation(int choice)
{
float A, B, result;
printf("A: ");
scanf("%f", &A);
printf("B: ");
scanf("%f", &B);
	if (choice == 1)
	{
		result = A + B;
		printf("Result: %.2f\n", result);
	}
	else if (choice == 2)
	{
		result = A - B;
		printf("Result: %.2f\n", result);
	}
	else if (choice == 3)
	{
		result = A * B;
		printf("Result: %.2f\n", result);
	}
	else if (choice == 4)
	{
		if (B == 0)
		{
			printf("Error: Division by zero\n");
		}
		else
		{
		result = A / B;
		printf("Result: %.2f\n", result);
		}
	}
}

/**
 * main - display menu and handle user input loop
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
int choice = -1;
printf("Simple Calculator\n");
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");
	while (choice != 0)
	{
		printf("Choice: ");
		scanf("%d", &choice);
		if (choice == 0)
		{
			printf("Bye!\n");
		}
			else if (choice >= 1 && choice <= 4)
			{
				PerformOperation(choice);
			}
				else
				{
					printf("Invalid choice\n");
				}
	}
return (0);
}
