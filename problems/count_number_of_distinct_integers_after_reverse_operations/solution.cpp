class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> st(begin(nums),end(nums));
        for (auto i : nums){
            int n = 0;
            while (i>0){
                n =   n * 10 + i%10;
                i/=10;
            }
            st.insert(n);
        }
        return st.size();
    }
};