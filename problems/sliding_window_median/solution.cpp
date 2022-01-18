class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> set(nums.begin(), nums.begin() + k);
        int n = nums.size(), m = k-k/2-1;
        auto mid = next(begin(set),m);

        vector<double> ans;
        ans.push_back(k%2 ? *mid : ((double)*mid + *next(mid))/ 2.0);
        for (int i=k; i<n; i++){
            //if (nums[i] != nums[i-k])
            {                
                set.insert(nums[i]);
                if (nums[i] < *mid) mid--;
                if (nums[i-k] <= *mid) mid++;
                set.erase(set.lower_bound(nums[i-k]) );                         
            }
            ans.push_back(k%2 ? *mid : ((double)*mid + *next(mid))/ 2.0);
        }
        return ans;
    }
    
};