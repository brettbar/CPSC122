void NumberList::mergeArray(double a[], int size)
{
	for(int i = 0; i < size; i++)
	{
		appendNode(a[i]);
	}
}