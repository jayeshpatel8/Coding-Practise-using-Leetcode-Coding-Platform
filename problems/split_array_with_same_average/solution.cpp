class Solution {
public:
    typedef long long ll ;
    bool posssible(ll ind, ll sum, vector<int> &A,ll size,vector<vector<vector<bool>>> &dp)
    {
        if(size==0)return (sum==0);
        if(ind>=A.size())return 0;

        if(dp[ind][size][sum]==false)return false;
        if(A[ind]<=sum)
        {
            if(posssible(ind+1,sum-A[ind],A,size-1,dp))
            return dp[ind][size][sum]= true;
        }
        if(posssible(ind+1,sum,A,size,dp))return dp[ind][size][sum]= true;
        return dp[ind][size][sum]= false;
    }
    bool splitArraySameAverage(vector<int>& A) {
        ll sum=0;
        for(auto i:A)sum+=i;
        ll n=A.size();
        // sort(A.begin(),A.end());
        vector<vector<vector<bool>>> dp(n+1,vector<vector<bool>>(n+1,vector<bool>(sum+1,true)));
        for(int k=1;k<=(n-1);k++)
          if((sum*k)%n==0)
              if(posssible(0,(sum*k)/n,A,k,dp))
                  return true;
        return false;
    }
};