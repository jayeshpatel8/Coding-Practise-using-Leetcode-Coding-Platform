class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(begin(nums),end(nums));
        set<int> st;
        for (int i =0 , j = nums.size()-1; i<j; i++,j--){
            st.insert((nums[i] + nums[j]));
        }
        return st.size();
    }
};