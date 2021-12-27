class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        
        int n = nums.size();
        if (n==1) return  1;
        if (n==2) return (nums[0] ==0 + nums[1]==0);
        vector<int> prefix(n), suffix(n);
        prefix[0]=nums[0];
        prefix[1]= n > 1 ? nums[1]:0;
        for (int i=2; i<n; i++)
            prefix[i] = prefix[i-2] + nums[i];        
        for (int i=n-1; i>=0; i--){
            suffix[i]=nums[i];
            if (i<n-2)
                suffix[i]+=suffix[i+2];
        }
        
        int ans = suffix[1] == suffix[2];
        
        for (int i=1; i<n-1; i++){
            ans += prefix[i-1]+ suffix[i] == prefix[i]+suffix[i+1];
                
        }
            
        ans += prefix[n-2] == prefix[n-3];
        return ans;
    }
};
//   1,1,2