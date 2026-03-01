#include <stdio.h>
/**
 * main - menu
 *
 * Return: 0 Succes
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

			}
				else
				{
					printf("Invalid choice\n");
				}
	}
return (0);
}
