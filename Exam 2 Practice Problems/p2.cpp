int doSomething(int* x, int* y)
{
int temp = *x;
 *x = *y * 10;
*y = temp * 10;
return *x + *y;
} 