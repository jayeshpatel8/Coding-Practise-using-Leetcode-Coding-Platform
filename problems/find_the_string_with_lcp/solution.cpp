class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int N = lcp.size(), ch = 'a';
        string ans;
        for (int i=0; i<N; i++){
            for (int j=0; j<=i && ans.size() == i;j++ )
                if (lcp[i][j])
                    ans.push_back(j<i? ans[j] : ch++);
            if (ans.back() >'z') return "";
        }
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++){
                int v = ans[i] == ans[j];
                if (v && i+1 <N && j+1<N)
                    v += lcp[i+1][j+1];
                if ( v!=  lcp[i][j]) return  "";
            }

        return ans;
    }
};