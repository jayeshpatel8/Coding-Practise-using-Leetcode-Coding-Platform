class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size(), ans=  0;
        vector<int> odd(n+2), even(n+2);   
        for (int i=0, o=0,e=0; i<n;i++){
            odd[i+1] = odd[i];
            even[i+1] = even[i];            
            if (i%2)
                odd[i+1] += nums[i];
            else
                even[i+1]  += nums[i];

        }
        
        for (int i=0; i<n;i++){
                ans += (odd[i] + even[n]-even[i+1] == even[i]+  odd[n]-odd[i+1]);
        }
        return ans;
    }
};