class Solution {
public:
    int minimumTime(string s) {
        int N = s.size();
        vector<int> L(N+1);
        for (int i=0; i<N; i++){
            if (s[i] == '1')
                L[i+1] = min(i+1, L[i] +  2 );
            else
                L[i+1] = L[i];
        }

        int ans = N, r=N;
        for (int i=N-1; i>=0; i--){
            if (s[i] == '1')
                r = min({r+2, N-i});
             ans = min (ans, L[i]+r);
        }   
        ans = min (ans,L[N]);

       return ans;
    }

};