class Solution {
    public:
        int maxActiveSectionsAfterTrade(string s) {
            int be_z = 0, af_z = 0, n = s.size(), cnt = 0, mx = 0;
    
            for(int i = 0; i < n; i++){
                if(s[i] == '1') cnt++;
            }
            
            int i = 0;
            while(i < n && s[i] == '0') be_z++, i++;
      
            while(i < n){
    
                while(i < n && s[i] == '0') af_z++, i++;
                
                if(be_z > 0 && af_z > 0){
                    mx = max(mx, be_z + af_z);
                } 
                
                if(af_z > 0 ) be_z = af_z, af_z = 0;
                i++;
            }
            return cnt + mx;
        }
    };