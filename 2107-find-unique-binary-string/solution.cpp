class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        for (auto s : nums){
            int num = 0;
            for (int i=0; i<n; i++)
                num |= s[i] == '1' ? (1 << n-i-1): 0;
            st.insert(num);
            
        }
        string ans(n,'0');
        for ( int i=0; i<n+1; i++){
            if (st.count(i)) continue;
            
            for (int j=0; i>0; j++, i/=2){    
                if (i&1) ans[j]='1';                
            }
            reverse(begin(ans), end(ans));
            return ans;
        }
        return ans;
    }
};
