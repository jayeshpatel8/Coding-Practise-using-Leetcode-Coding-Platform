class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        set<int> st(begin(nums),end(nums));
        int n =1;
        while (1){
            if (!st.count(n)) return n;
            n*=2;
        }
        return n;
    }
};