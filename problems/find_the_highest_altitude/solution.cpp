class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans= 0,s=0;
        for (auto i : gain) ans=max(ans, s+=i);
        return ans;
    }
};