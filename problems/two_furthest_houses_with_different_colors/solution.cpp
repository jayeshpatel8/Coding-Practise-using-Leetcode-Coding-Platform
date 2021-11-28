class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size(),l =0 ,  r = n-1;
        
        while (l<n && colors[l] == colors[n-1]) l++;
        while (r >=0 && colors[r] == colors[0]) r--;
        return max(n-1-l,r);
    }
};