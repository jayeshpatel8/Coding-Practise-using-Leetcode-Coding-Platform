class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<long> st(begin(nums),begin(nums)+k);
        auto mid = next(st.begin() ,  k/2);
        vector<double> ans;
        int i=k, j =0;

        ans.push_back( (*mid + *prev(mid, 1 - k%2))/ 2.0);
        for (; i<nums.size(); i++,j++){
            st.insert({nums[i]});
            
            if (nums[i] < *mid) mid--;
            
            if (nums[j] <= *mid) mid++;
            st.erase({st.find(nums[j])});
            
            ans.push_back( (*mid + *prev(mid, 1 - k%2))/ 2.0);
        }
        return ans;
    }
};