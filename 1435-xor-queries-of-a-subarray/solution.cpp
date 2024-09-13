class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& qu) {
        int N = arr.size();
        vector<int> ans ,  pXor(N+1);

        for (int i=0; i<N; i++) pXor[i+1] =pXor[i] ^arr[i];

        for (auto &q : qu){
            ans.push_back( pXor[q[1]+1] ^ pXor[q[0]]);
        }
        return ans;
    }
};
