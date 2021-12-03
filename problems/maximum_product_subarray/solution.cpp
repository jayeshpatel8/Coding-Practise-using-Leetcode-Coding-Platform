class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int left=0,right=0,ans = INT_MIN;
        for (int i=0,j=nums.size()-1; i<nums.size(); i++,j--){
            left = (left ? left : 1 ) * nums[i];
            right = (right ? right : 1 ) * nums[j];
            ans= max({ans, left, right});
        }
        return ans;
    }
};

//   3 2 -1  2 4 5 -1 6 7 -1 2 8 9 10