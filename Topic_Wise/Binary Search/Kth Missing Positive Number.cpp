int missingK(vector < int > vec, int n, int k) {
    // Write your code here.
    int s = 0, e = n-1;
    while(s <= e){
        int mid = s + (e - s) / 2;
        int missing = vec[mid] - mid - 1;
        if(missing < k) s = mid + 1;
        else            e = mid - 1;
    }
    return s + k;
}