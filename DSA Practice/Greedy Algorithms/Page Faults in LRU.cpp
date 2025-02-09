class Solution{
    public:
        int pageFaults(int N, int C, int pages[]){
            // code here
            deque<int> dq;
            vector<int> fre(1001, 0);
            
            int i = 0, ans = 0, curr = 0;
            while(i < N){
                if(fre[pages[i]]) dq.push_front(pages[i]);
                else{
                    while(!dq.empty() && fre[dq.back()] > 1) fre[dq.back()]--, dq.pop_back();
                    if(!dq.empty() && curr == C)             fre[dq.back()]--, dq.pop_back();
                    
                    dq.push_front(pages[i]);
                    ans++;
                    if(curr < C) curr++;
                } 
                
                fre[pages[i]]++;
                i++;
            }
            return ans;
        }
    };