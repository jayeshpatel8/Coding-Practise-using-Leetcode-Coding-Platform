class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        stack<int> st;
        int s3=INT_MIN;
        for (int i=nums.size()-1; i>=0; i--){
            int n = nums[i];

            if ( n < s3) return true;
            while (!st.empty() && n > st.top() ) s3 = st.top(), st.pop();
            st.push(n);
        }
        return false;
    }
};