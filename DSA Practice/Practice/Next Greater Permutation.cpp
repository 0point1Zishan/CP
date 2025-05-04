vector<int> nextGreaterPermutation(vector<int> &A) {
    // Write your code here.
    int n = A.size(), idx = -1;
    for(int i = n-2; i >= 0; i--){
        if(A[i] < A[i+1]){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        reverse(A.begin(), A.end());
        return A;
    }
    for(int i = n-1; i >= idx; i--){
        if(A[idx] < A[i]){
            swap(A[idx], A[i]);
            break;
        }
    }
    reverse(A.begin()+idx+1, A.end());
    return A;
}