class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int N = A.size(), c=0;
        vector<int> f1(N+1);
        vector<int> ans;
        for (int i=0; i<N; i++){
            c += (f1[A[i]]++==1);
            c += (f1[B[i]]++==1);

            ans.push_back(c);
        }
        return ans;
    }
};