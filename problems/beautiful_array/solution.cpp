class Solution {
public:
    
    vector<int> beautifulArray(int n) {
        vector<int> ans = {1};
        while(ans.size() < n){
            vector<int> t( ans.size() * 2);
            int j =0;
            for (int i=0;  i<ans.size() ; i++) 
                if (ans[i] * 2 <= n) t[j++]=ans[i] * 2 ;
            
            for (int i=0;  i<ans.size(); i++) 
                if (ans[i] * 2 - 1<= n)  t[j++]=ans[i] * 2 -1;
            ans = t;
        }
        ans.resize(n) ;
        return ans;
        
    }
};