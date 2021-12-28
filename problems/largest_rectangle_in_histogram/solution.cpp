class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> s; s.push(-1);
        int ans = 0;
        for (int i=0; i<heights.size(); i++){
            while(s.size() > 1 && heights[i] < heights[s.top()]){
                int hi = heights[s.top()]; s.pop();
                int w = i - s.top() - 1;
                ans = max(ans, hi * w);
            }
            s.push(i);
        }
        return ans;
    }
};