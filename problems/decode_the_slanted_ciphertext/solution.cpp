class Solution {
public:
    string decodeCiphertext(string e, int rows) {
        if (rows <=1 ) return e;
        int N = e.size(), dist = 1 + N / rows;
        string ans;
        for ( int i=0, j=0; i<dist-1; j++,i++){
            for (int k=i; k<N; k+=dist){
                ans += e[k];
            }
        }
        for (int i=ans.size()-1; i>=0 && ans[i]==' '; i--)
            ans.pop_back();
        return ans;
    }
};