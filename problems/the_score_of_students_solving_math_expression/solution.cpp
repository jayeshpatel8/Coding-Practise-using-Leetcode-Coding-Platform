class Solution {
public:
    int scoreOfStudents(string s, vector<int>& answers) {        
        int correctans = dfs(s,s[0]-'0',1);
        int N = s.size();
        unordered_set<size_t> ans[N+1][N+1];
        for ( int i=0; i<N; i+=2) {
                ans[i][i].insert(s[i]-'0' );
        }
        for( int  L  = 2; L<N; L+=2){
            for (int i=0; i<N-L; i+=2){
                int j = i+L;
                for (int k=i; k<=j-2; k+=2){
                    for ( auto n1 : ans[i][k])
                        for ( auto n2 : ans[k+2][j]){
                            int n;
                            if(s[k+1]=='+')
                                n  = n1+n2;
                            else
                                n  = n1*n2;
                            if (n <= 1000)
                                ans[i][j].insert(n);
                        }
                }
            }
        }
        int a[1001]={};
        for (auto i : answers) a[i]++;
        int points=5 * a[correctans];
        a[correctans]=0;
        int j=0;
        for (auto i : ans[0][N-1]){
                if (a[i]) points +=2*a[i];               
        }
        return points;
    }
    int dfs(string & s, size_t prev, int i){
        if (i >= s.size()) return prev;
        if (s[i]=='+')
            return prev + dfs(s, s[i+1]-'0',i+2);
        else
            return  dfs(s, prev * (s[i+1]-'0'),i+2);
    }
};