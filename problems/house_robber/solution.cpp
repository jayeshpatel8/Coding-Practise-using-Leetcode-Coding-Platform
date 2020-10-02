class Solution {
public:
    int rob(vector<int>& nums) {
        int n1=0,n2=0;
     for (auto a : nums){
        int t = max(a + n1, n2);
         n1=n2;
         n2=t;
     }
    return n2;
    }
};