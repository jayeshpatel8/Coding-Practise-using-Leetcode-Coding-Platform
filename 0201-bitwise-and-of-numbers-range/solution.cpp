class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int i = right;
        for (; i>left; i&=i-1){
            
        }
        return i;
    }
};
