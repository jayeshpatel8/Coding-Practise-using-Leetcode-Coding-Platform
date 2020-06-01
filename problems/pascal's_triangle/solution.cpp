class Solution {
public:
    vector<vector<int>> generate(int n) {
        if (!n) return vector<vector<int>>();
        vector<vector<int>> res;
        if(n>0) res.push_back(vector<int>(1,1));
        if(n>1) res.push_back(vector<int>(2,1));
        
        for (int i=3; i<=n;i++){
            vector<int> o(i,1);
            for (int j = 1; j<i-1;j++)
                o[j] = res[i-2][j]+res[i-2][j-1];
            res.push_back(o);            
        }
        return res;
    }
};