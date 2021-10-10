class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        int ans=0;
        for (int i  =30; i>=0; i--){
            int mask = 1 <<i;
            if( (left & mask) != (right & mask)) break;
            if (left & mask)
                ans |= mask; 
        }
        return ans;
    }
};
// 11101
// 101 1100