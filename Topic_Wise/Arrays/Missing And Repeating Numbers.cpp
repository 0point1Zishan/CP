vector<int> findMissingRepeatingNumbers(vector < int > arr) {
    // Write your code here
    long long sum = 0;
    int n = arr.size();
    vector<int> hash(n,0);
    for(int i = 0; i < n; i++){
        hash[arr[i]-1]++;
        sum += arr[i];
    }
    int q = 0;
    for(int i = 0; i < n; i++){
        if(hash[i] == 0){
            q = i+1;
            break;
        }
    }
    int p = sum + q - ((n * (n+1)) / 2);
    return {p, q};
}