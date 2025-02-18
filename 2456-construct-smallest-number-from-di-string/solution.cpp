class Solution {
public:
    string smallestNumber(string pat) {
        string ans;
        int d_cnt=0, j = '1';
        for (int i=0; i<=pat.size(); i++){
            if ( i< pat.size() && pat[i] == 'D'){
                d_cnt++; 
            }
            else{
                int t = d_cnt;
                while(d_cnt >  0) ans +=j+d_cnt, d_cnt--;
                ans +=j++;
                j+=t;
            }
        }
      
        
        
        return ans;
    }
};
