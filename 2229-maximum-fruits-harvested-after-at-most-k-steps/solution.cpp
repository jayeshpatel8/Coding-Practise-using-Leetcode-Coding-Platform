class Solution {
public:
int maxTotalFruits(vector<vector<int>>& fruits, int pos, int k) {
        auto left = upper_bound(begin(fruits), end(fruits), vector<int>{pos-k});
        int ans=0, sum=0;
        for (auto right = left; right != end(fruits) && (*right)[0]-pos <=k; right++){            
            sum += (*right)[1];
            
            while(min(pos-(*left)[0]+(*right)[0]-(*left)[0], (*right)[0]-pos+(*right)[0]-(*left)[0]) > k)
                sum -= (*left++)[1];
            ans = max(ans, sum);
        }
        return ans;
    }
};
