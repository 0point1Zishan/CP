void quickSort(vector<int>& arr, int low, int high) {
    // code here
    if(low < high){
        int idx = partition(arr, low, high);
        quickSort(arr, low, idx-1);
        quickSort(arr, idx+1, high);
    }
}

int partition(vector<int>& arr, int low, int high) {
    // code here
    int pivot = arr[low];
    int i = low, j = high;
    while(i < j){
        while(arr[i] <= pivot && i <= high - 1) i++;
        while(arr[j] > pivot && j >= low + 1)   j--;
        
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}