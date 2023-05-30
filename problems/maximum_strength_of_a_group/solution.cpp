class Solution {
public:

long long maxStrength(vector<int>& nums) {
        //int dp[nums.size()][2];
        long mx,mn,mx1,mn1;
        mx=mn=nums[0];
        for (int i=1; i<nums.size(); i++){
            auto n =  nums[i];
            mx1 = max<long>({mx,n,mx*n, mn*n});
            mn1 = min<long>({mn,n,mx*n, mn*n});
            mx=mx1,mn=mn1;
        }
        return mx;
    }
    long long maxStrength2(vector<int>& nums) {
        
        int N = nums.size();
        long pos=1,neg=1,neg_cnt=0,neg_small=-10,zero=0,p_cnt=0;

        for (auto i : nums){
            if (i==0) zero++;            
            else if (i < 0){
                neg_cnt++;
                neg *= i;
                neg_small = max<long>(neg_small, i);
            }
            else
                p_cnt++,pos*= i;        
        }
        if ((p_cnt==0 && zero==0)){
            return max(neg, neg_cnt > 1 ? (neg/neg_small): neg);
        }
        long long ans = 0;
        if (p_cnt) ans = max<long long>(ans , pos);

        if (neg_cnt > 1){
            
            neg = max(neg, neg/neg_small);
            if (neg > 0)
                ans=max<long long>(neg, ans * neg);
        }
        return ans;
    }
};