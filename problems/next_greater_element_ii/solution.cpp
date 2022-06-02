class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int N = nums.size();
        vector<int> st ,ans(N,-1);
        
        for (int i=0; i<2*N; i++){
            int num = nums[i% N];
            while (!st.empty() && nums[st.back()% N] < num){                
                ans[st.back() % N] = num;
                st.pop_back();
            }
            st.push_back(i);
        }
        return ans;
    }
};