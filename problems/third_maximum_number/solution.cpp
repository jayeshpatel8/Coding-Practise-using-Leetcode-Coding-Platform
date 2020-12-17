class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long   i1,i2,i3;        
        i1=i2=i3=LONG_MIN;
        
        for (auto i : nums){
            
            if (i > i1){
                i3=i2;i2=i1;i1=i;
            }
            else if (i > i2 && i!= i1){
                i3=i2;i2=i;
            }
            else if (i>i3 && i!= i2 && i!= i1)i3=i;            
        }
        return i3 != LONG_MIN ? i3:i1;
    }
};