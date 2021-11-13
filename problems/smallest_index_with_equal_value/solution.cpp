class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int j=0;
        for (int i=0; i<nums.size(); i++){
            if (j++== nums[i]) return i;
            j %=10;
        }
        return -1;
    }
};