long dp[31][17] = {};
class Solution {
public:

    int nCr(int i, int j) {
        if (i == 0) return 0;
        if ( j == 1)
            return dp[i][j] = 1;
        return dp[i][j] ? dp[i][j] : dp[i][j] = (long)nCr(i - 1, j) + nCr(i-1, j - 1);
    }
int comb(int n, int r) {
        long ans = 1;
        for (int i = 1, j = n - r + 1; i <= r; ++i, ++j) ans = ans * j / i;
        return ans;
    }    
    string kthSmallestPath(vector<int>& d, int k) {
        int h = d[1] , v = d[0];
        string s;

        for ( int i=h+v; i>0; i--){
            if (h){
                long c =  nCr(h+v,v+1);
                //int c =  comb(h-1+v,v);
                
                if (k <= c)
                    s +='H', h--;
                else
                    s+='V',v--, k-=c;
            }
            else{
                s+=string(v,'V'); break;
            }
        }
        return s;
    }
};