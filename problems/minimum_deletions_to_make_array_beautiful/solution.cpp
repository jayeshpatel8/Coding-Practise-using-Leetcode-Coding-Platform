class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int even=1,del=0,sz=0;
        for (int i=0; i<nums.size(); ){
            if (even){
                i++; even =0;
                sz++;
            }
            else{
                if (nums[i] == nums[i-1]){
                    i++;del++;
                    while (i < nums.size() && nums[i] == nums[i-1]){
                        del++; i++; 
                    }
                    even=0;
                }
                else
                    i++,even=1,sz++;;
                
            }
        }
        return sz & 1 ? del +1 : del;
    }
};