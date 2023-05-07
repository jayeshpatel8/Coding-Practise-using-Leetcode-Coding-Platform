class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> ans ,  A(n);
        int p = 0;
        for (auto &q : queries){
            int i = q[0];
            if (i>0 && A[i] && A[i-1]==A[i]) p--;
            if (i+1<n && A[i] && A[i+1]==A[i]) p--;
            A[i]=q[1];
            if (i>0 && A[i-1]==A[i]) p++;
            if (i+1<n && A[i+1]==A[i]) p++;
            ans.push_back(p);            
        }
        return ans;
    }
};