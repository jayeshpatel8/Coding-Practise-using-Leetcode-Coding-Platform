class Solution {
public:
    int ans_mask=0, ans_max=0;
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
         dfs(numArrows, aliceArrows);
        vector<int> A(12);
        for (int i=1; i<12; i++){
            if (ans_mask & (1<<i)){
                A[i]=aliceArrows[i]+1 ;
                numArrows -=A[i];
            }
        }
        if (numArrows) A[0] = numArrows;
        return A;
    }
    void dfs(int A,  vector<int>& aA, int i=0, int mask=0, int ans1=0){
        if (ans1>ans_max) ans_max=ans1, ans_mask=mask;
        if (A<=0 || i>= aA.size()) return ;
        dfs(A,aA,i+1,mask,ans1);
        if (A > aA[i]){
           dfs(A-aA[i]-1,aA,i+1,mask|(1<<i),ans1+i);
        }
    }
};