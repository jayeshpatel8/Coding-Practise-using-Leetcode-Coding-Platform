class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        auto [it1, it2] = minmax_element(begin(nums), end(nums));
        int mini = it1 - begin(nums), maxi = it2 - begin(nums), n = size(nums);
        
        if (mini == maxi) return min<int>(mini+1,n-mini);
        else if (mini > maxi) 
            swap(mini,maxi);
        
        return min(maxi-mini + min(mini+1,n-maxi), mini+1 + n-maxi);
        
    }
};