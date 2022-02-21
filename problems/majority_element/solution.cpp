class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=1, n=nums[0];
        for (int i=1; i<nums.size(); i++){
            if (nums[i] == n)
                cnt++;
            else
                cnt--;
            if (cnt == 0){
                n = nums[i], cnt = 1;
            }
        }
        return n ;
    }
};