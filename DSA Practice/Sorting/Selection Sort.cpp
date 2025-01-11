void selectionSort(vector<int> &arr) {
    // code here
    for(int i = 0; i < arr.size()-1; i++){
        int idx = i;
        for(int j = i+1; j < arr.size(); j++){
            if(arr[idx] > arr[j]){
                idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }
}