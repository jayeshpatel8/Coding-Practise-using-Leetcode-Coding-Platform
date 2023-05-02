class Solution {
public:
    int arraySign(vector<int>& nums) {
        auto p  =  accumulate(begin(nums), end(nums), 1,[](auto x,int a){return x * (a<0 ? -1 : a!=0); });
        return p<0 ? -1 : p!=0;   
    }
};