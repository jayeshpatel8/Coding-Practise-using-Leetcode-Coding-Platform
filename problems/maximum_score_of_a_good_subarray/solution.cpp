class Solution {
public:

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int i=k,j=k; 
        int mi=nums[k],res=nums[k];
       do
        {

            if (i>0 && j<n-1){
                if(nums[i-1] <= nums[j+1]) j++;
                else i--;
            }
            else if( j<n-1) j++;
            else if(i>0) i--;
            mi=min({mi,nums[i],nums[j]});
            res = max(res,mi*(j-i+1));             

        } while(i>0 || j<n-1);
        return res;
    }

};