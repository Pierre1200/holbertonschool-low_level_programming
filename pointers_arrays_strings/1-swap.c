#include "main.h"
/**
 * swap_int - swap
 * @a: number
 * @b: number
 */

void swap_int(int *a, int *b)
{
int temp;
temp = *a;
*a = *b;
*b = temp;
}
