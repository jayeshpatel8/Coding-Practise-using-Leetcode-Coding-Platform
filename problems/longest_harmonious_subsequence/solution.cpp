class Solution {
public:
    int n;
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> M;
        for (auto i : nums) ++M[i];
        int m=0;
        for (auto  &[i,freq] : M)
            if (M.count(i+1)) m = max(m,freq+M[i+1]);
        
        return m;
    }

};