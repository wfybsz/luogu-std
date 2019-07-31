void Qsort(int arr[],int low,int high){
	if(high <= low)
		return;
	int i = low,j = high + 1;
	int key = arr[low];
	while(true){
		while(arr[++i] < key)
			if(i == high)
				break;
		while(arr[--j] > key)
			if(j == low)
				break;
		if(i >= j)
			break;
		swap(arr[i],arr[j]);
	}
	int tmp = arr[low];
	arr[low] = arr[j];
	arr[j] = tmp;
	Qsort(arr,low,j - 1);
	Qsort(arr,j + 1,high);
}
