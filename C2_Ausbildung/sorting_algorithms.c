void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}




// Recursive function to sort an array using
// insertion sort 
void insertionSortRecursiveUp(char arr[], int n)
{
	// Base case 
	if (n <= 1)
		return;

	// Sort first n-1 elements 
	insertionSortRecursiveUp(arr, n - 1);

	// Insert last element at its correct position 
	// in sorted array. 
	int last = arr[n - 1];
	int j = n - 2;

	/* Move elements of arr[0..i-1], that are
	  greater than key, to one position ahead
	  of their current position */
	while (j >= 0 && arr[j] > last)
	{
		arr[j + 1] = arr[j];
		j--;
	}
	arr[j + 1] = last;
}

void insertionSortRecursiveDown(char arr[], int n)
{
	// Base case 
	if (n <= 1)
		return;

	// Sort first n-1 elements 
	insertionSortRecursiveDown(arr, n - 1);

	// Insert last element at its correct position 
	// in sorted array. 
	int last = arr[n - 1];
	int j = n - 2;

	/* Move elements of arr[0..i-1], that are
	  greater than key, to one position ahead
	  of their current position */
	while (j >= 0 && arr[j] < last)
	{
		arr[j + 1] = arr[j];
		j--;
	}
	arr[j + 1] = last;
}