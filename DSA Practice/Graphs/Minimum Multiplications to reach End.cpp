class Solution {
    public:
      int minimumMultiplications(vector<int>& arr, int start, int end) {
          // code here
          queue<pair<int, int> > q;
          vector<int> steps(100000, 1e9);
          steps[start] = 0;
          q.push({0, start});
          
          while(!q.empty()){
              int cur = q.front().second;
              int s = q.front().first;
              q.pop();
              
              for(auto it: arr){
                  int num = (it * cur) % 100000;
                  if(s + 1 < steps[num]){
                      if(num == end) return s + 1;
                      
                      steps[num] = s + 1;
                      q.push({s+1, num});
                  }
              }
          }
          return (start == end) ? 0 : -1;
      }
  };