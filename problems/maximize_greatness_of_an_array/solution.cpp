class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        //1,3,5,2,1,3,1]
        // 1 1 1 2 3 3 5
        // 2,3,3,5 1 1 1

        // 1 2 2 3
        // 2 2 3 1
        sort (begin (nums), end(nums));

        int i = 0;
        for (int j=1; j < nums.size(); ){
            if (nums[i]< nums[j]) {
                i++; //j++;
            }
            //else   j++;
            j++;
        }
        return i;
    }
};