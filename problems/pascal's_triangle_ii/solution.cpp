class Solution {
public:
    vector<int> getRow(int r) {
       vector<int> ans(r+1,1);
        
        for (int i = 2; i<=r; i++)
            for(int j=i-1; j>0; j--)
                ans[j] +=ans[j-1];
        
        return ans;
    }
};