class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        int n = nums.size();
        int imin = *min_element(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            int diff = nums[i] - imin;
            if((diff & 1) || diff == 0)
                continue;
            multiset<int> st(nums.begin(), nums.end());
            vector<int> arr;
            while(!st.empty()) {
                int curr = *st.begin();
                st.erase(st.begin());
                if(st.find(curr + diff) == st.end())
                    break;
                arr.push_back(curr + diff/2);
                st.erase(st.find(curr + diff));
            }
            if(st.empty())
                return arr;
        }
        return {};
    }
};