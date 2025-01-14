class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int cnt = A.size(), n=0;
        vector<int> ans(cnt), f(cnt+1);
        for (int i=0; i<cnt; i++){
            
            n +=f[A[i]]++==1;
            n +=f[B[i]]++==1;
            ans[i]=n;
        }
        return ans;
    }
};
