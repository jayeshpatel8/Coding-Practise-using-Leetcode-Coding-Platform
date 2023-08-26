class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs),end(pairs),[](auto &a, auto &b){
                return a[1] < b[1];
            });
        int ans = 1;
        for (int i=1,j=0; i<pairs.size(); i++)
            if (pairs[j][1] < pairs[i][0]) ans++, j=i;            
        
        return ans;
    }
};