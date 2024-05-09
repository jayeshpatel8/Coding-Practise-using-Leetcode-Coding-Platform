class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(rbegin(h),rend(h));
        long long ans = 0;
        for (int i=0; i<k; i++){
            ans += max(0,h[i]-i);
        }
        return ans;

    }
};
