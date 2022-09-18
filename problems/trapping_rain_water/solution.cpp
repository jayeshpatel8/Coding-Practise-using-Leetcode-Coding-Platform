class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int ans =0;
        for(int i=0; i<height.size(); i++){
            auto h = height[i];
            while (!st.empty() && height[st.top()] < h){
                int mid = st.top(); st.pop();
                if (st.empty()) break;
                
                ans += (i - st.top()-1) * (min(h, height[st.top()]) - height[mid]) ;
            }
            st.push(i);
        }
        return ans;
    }
};