class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // -1 -1  -0 1 2 4
        int n = nums.size();
        if (n<3) return {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<n-2 ; i++){            
            if (i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1, k=n-1;
            while(j<k){
                long sum3 = nums[i] + nums[j] + nums[k];
                if ( sum3 < 0 )  j++;
                else if( sum3 > 0 )  k--;
                else{
                    int n1=nums[i],n2=nums[j],n3=nums[k];;
                    while(j<=k && n2 == nums[j])
                        j++;
                    
                    while(j<=k && n3 == nums[k])
                        k--;
                    ans.push_back({n1,n2,n3});
                }
            }            
        }
        return ans;
    }
};