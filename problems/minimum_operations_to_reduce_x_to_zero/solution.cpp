class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size(), sum=0, i=0, j= n-1, ans= INT_MAX;
        if (x < nums[0] && x < nums[n-1]) return -1;
        for ( ; i<n ; i++)    {
            sum +=nums[i];
            if (sum>x){
                sum -=nums[i]; break;
            }
        }
        if (i==n && sum != x) return -1;
        --i;
        if(sum ==x) ans= min(ans, i+1);
        while (  j>=0 ){
            sum += nums[j];
            
            {
                while (i>=0 && sum > x) sum-=nums[i--];
            }
            if (sum == x) ans = min(ans, i+1+n-j);
            j--;
        }
        return ans;
    }
};