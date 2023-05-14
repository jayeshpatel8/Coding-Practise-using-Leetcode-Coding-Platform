class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        vector<int> l(nums.size()+2),r(nums.size()+2);
        for (int i=0; i<nums.size(); i++){
            l[i+1]=nums[i] | l[i];
            
        }

        for (int i=nums.size()-1;i>=0; i--){
            r[i]=nums[i] | r[i+1];
        }        

         long long ans = 0;


        for (auto i=0; i<nums.size(); i++){
            ans= max(ans, l[i] | (( long long)nums[i] << k) | r[i+1]);
        }
        return ans;
    }
    /*
        1100
        1001
       10010
      100100
      110000
    */
};