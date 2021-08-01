class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int i=0, ans = 0;
        while(i<height.size()){
            while(!st.empty() && height[i] > height[st.top()]){
                int top = st.top(); st.pop();
                if (st.empty())break;
                int dist = i - st.top()-1;
                ans +=  dist * (min(height[st.top()], height[i]) - height[top]);
            }
            st.push(i++);
        }
        return ans;
    }
};