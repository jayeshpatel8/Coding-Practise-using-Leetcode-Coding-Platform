class Solution {
public:
    int specialArray(vector<int>& nums) {
        int x = nums.size();
        int counts [101]= {0};
        
        for(int elem : nums)
            if(elem >= x)
                counts[x]++;
            else
                counts[elem]++;
        
        int res = 0;
        for(int i = 100; i > 0; i--) {
            res += counts[i];
            if(res == i)
                return i;
        }
        
        return -1;
    }
};
