class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        
        int xory=0;
        for (auto i : nums) xory ^=i;
        
        int b=xory & -xory;
        int x=0;
        for (auto i : nums) 
            if (i & b) x ^=i;
            
        return  vector<int>{x,x^xory};
    }
};