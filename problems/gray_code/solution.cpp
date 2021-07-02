class Solution {
public:
    vector<int> grayCode(int n) {
        int num = 1 << n;
        vector<int> ans(num);
        ans[0]=0;
        for (int i=1; i<num; i++){
            ans[i] = i ^ (i >> 1);
        }       
        return ans;
    }
};