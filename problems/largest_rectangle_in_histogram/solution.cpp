class Solution {
public:
    int largestRectangleArea(vector<int>& H) {
        H.push_back(0);
        vector<int> stack;
        int ans = 0;
        for (int i=0; i<H.size(); i++){
            while (!stack.empty() && H[stack.back()] >=H[i]){
                int hi = stack.back(); stack.pop_back();
                int w = stack.empty()? i : i - stack.back() -1;
                ans = max(ans, H[hi] * w);
            }
            stack.push_back(i);
        }
        return ans;
    }
};