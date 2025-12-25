class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(begin(h),end(h), greater());
        long long ans = 0;
        for (int i=0; i<k ; i++){
            auto a = h[i]-i;
            if (a < 0) break;
            ans +=a;
        }
        return ans;

    }
};
