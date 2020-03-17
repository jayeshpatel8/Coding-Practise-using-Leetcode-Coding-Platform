class Solution {
public:
    void sortColors(vector<int>& nums) {
     
        int red=0,blue=nums.size()-1;
        
        for (int i=0; i<=blue; ){
            if (nums[i]==0 ){
                if (i!=red) {nums[i]=nums[red];nums[red]=0;}
                red++;
            }
            else if (nums[i]==2)
            {
                if (i!=blue) {nums[i]=nums[blue];nums[blue]=2;}
                blue--; continue;
            }    
            i++;
        }
    }
};