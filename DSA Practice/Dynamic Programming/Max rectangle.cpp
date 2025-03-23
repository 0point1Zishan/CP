class Solution {
    private:
      int largestRectangleArea(vector<int>& heights){
          int n = heights.size();
          stack<int> st;
          vector<int> leftSmall(n), rightSmall(n);
          for(int i = 0; i < n; i++){
              while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
      
              if(st.empty()) leftSmall[i] = 0;
              else leftSmall[i] = st.top()+1;
              st.push(i);
          }
          while(!st.empty()) st.pop();
          
          for(int i = n-1; i >= 0; i--){
              while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
      
              if(st.empty()) rightSmall[i] = n-1;
              else rightSmall[i] = st.top()-1;
              st.push(i);
          }
          int mx = 0;
          for(int i = 0; i < n; i++){
              mx = max(mx, heights[i] * (rightSmall[i] - leftSmall[i] + 1));
          }
          return mx;
      }
    public:
      // Function to calculate the maximum area of a rectangle
      // in the given matrix.
      int maxArea(vector<vector<int>> &mat) {
          // Your code here
          int mx = 0, n = mat.size(), m = mat[0].size();
          vector<int> heights(m, 0);
          for(int i = 0; i < n; i++){
              for(int j = 0; j < m; j++){
                  if(mat[i][j] == 1) heights[j]++;
                  else heights[j] = 0;
              }
              mx = max(mx, largestRectangleArea(heights));
          }
          return mx;
      }
  };