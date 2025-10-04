class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        for ( int i=0, j=height.size()-1; i<j; ){
            auto hi = height[i], hj = height[j];
            ans = max(ans,min(hi,hj) * (j-i));
            if (hi <= hj)
                i++;
            else 
                j--;
        }   
        return ans;
    }
};
