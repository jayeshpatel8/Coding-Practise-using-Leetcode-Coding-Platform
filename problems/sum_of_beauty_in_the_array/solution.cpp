class Solution {
public:
    //int lbiggest[100001], rsmallest[100001];
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        int lbiggest, rsmallest[n];
        lbiggest=nums[0];
        rsmallest[n-1]= nums[n-1]; 


        for (int j=n-2; j>=0; j--) rsmallest[j] = min(rsmallest[j+1], nums[j]);
        int ans=0;
        for ( int i=1; i<nums.size()-1; i++){
            if (lbiggest < nums[i] && nums[i] < rsmallest[i+1])
                ans +=2;
            else if (nums[i-1] < nums[i] && nums[i] < nums[i+1])
                ans++;
            lbiggest = max(lbiggest, nums[i]);
        }
        return ans;
    }
};