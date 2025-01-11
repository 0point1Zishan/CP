int findKRotation(vector<int> &arr){
    // Write your code here.  
    int s = 0, e = arr.size()-1, idx = 0, mn = 1e9 + 10;
    while(s <= e){
        int mid = s + (e - s) / 2;
        if(arr[s] <= arr[e]){
            if(mn > arr[mid]) idx = s;
            break;
        }
        if(arr[s] <= arr[mid]){
            if(mn > arr[mid]){
                mn = arr[mid];
                idx = mid;
            }
            s = mid + 1;
        }
        else{
            if(mn > arr[mid]){
                mn = arr[mid];
                idx = mid;
            }
            e = mid - 1;
        }
    }
    return idx;
}