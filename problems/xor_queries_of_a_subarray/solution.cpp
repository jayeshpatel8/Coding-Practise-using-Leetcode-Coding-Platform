class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int N= arr.size();
        vector<int> pxor(N+1), ans;
        for (int i = 0 ; i<N; i++)
            pxor[i+1]= pxor[i]^ arr[i];
        for (auto & q : queries){
            ans.push_back(pxor[q[1]+1] ^ pxor[q[0]] );
        }
        return ans;
    }
};