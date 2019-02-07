int binarySearch(int array[],int first, int last, int key)
{
	if (first <= last) 
	{
		int mid = (first + last) / 2;
		if (key == array[mid])
			return mid;
		else if (key > arr[mid])
			return binarySearch(arr, mid + 1, last, key);
		else 
			return binarySearch(arr, first, mid - 1, key)
	}
		

		return  - 1;
}