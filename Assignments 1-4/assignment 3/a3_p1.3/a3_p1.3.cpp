// We can't just equate array1 and array2 like that, since it only references memory location. To equalize the
// indeces of the arrays we have to use a loop
int array1[4], array2[4] = { 3, 6, 9, 12 };
for (int i = 0; i <= size; i++)
{
	array1[i] = array2[i];
}