class Solution {
public:
    //int dp[]
    int ans = INT_MAX;
    int distributeCookies(vector<int>& ck, int k ) {
        vector<int> sum(k,0);
            dfs(ck,k,0,0,sum);
        return ans;
    }
    void dfs(vector<int>& ck, int k , int i, int s,vector<int> &sum){
        if (i ==ck.size()|| s >=ans){
            ans = min ({ans,s});
            return ;
        }
        for (int j =0; j<k; j++){
            sum[j]+=ck[i];
            dfs (ck,k,i+1, max(s,sum[j]),sum);
            sum[j]-=ck[i];
        }
        
    }
};