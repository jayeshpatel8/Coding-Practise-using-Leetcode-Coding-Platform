class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int N = s.size();
        int l[N], r[N] , psum[N+1];
        psum[0]=0;
        for (int i=0,j = -1; i < N; i++)
        {
            if ( s[i] == '|' ) j = i;
            l[i] = j;
            psum[i+1] = psum[i] + ( s[i] == '*' );            
        }
        for (int i=N-1,j = N; i >=0; i--)
        {
            if ( s[i] == '|' ) j = i;
            r[i] = j;
        }        
        
        vector<int> ans ;
        
        for (auto q : queries){
            int left = l[q[1]], right = r[q[0]];

            if (left > right )
                ans.push_back(psum[left] - psum[right]);            
            else
                ans.push_back(0);
        }
        return ans;
    }
};