class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
     //   0 5 2 3 2
        int k=0,n= nums.size()-1;
        for (int i=1; i< nums.size(); i++){
            if (nums[i-1] > nums[i] ){
                if ( k  )
                    return false;

                 if (i-2 >= 0 &&  nums[i] < nums[i-2]){
                     nums[i]=nums[i-1];
                }
                k++;
            }
        }
        return true;
    }
};