class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n= nums.size();
        vector<long long > right(n+1), left(n+1);
        long long  sum = 0;
        for (int i=0;i<nums.size(); i++){
            sum+=nums[i];
            left[i] = sum/(i+1);
        }
        sum=0;
        for (int i=n-1;i >=0;  i--){
            sum+=nums[i];
            right[i] = sum/(n-i);
        }
        long long ans = INT_MAX, idx=0;
        for (int i=0; i<n; i++){
            int a = left[i];
            int b = right[i+1];
            if (ans > abs(a-b) )
                idx=  i, ans= abs(a-b);
        }
        return idx;
    }
};