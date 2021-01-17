class Solution {
public:
    int countVowelStrings(int n) {
        if (n==1) return 5;
        return count(n,5);
    }
    map<pair<int,int>, int> M;
    int count(int n, int i){
        if (n==1) {
            return i;
        }
        if (M.count({n,i})) return M[{n,i}];
        int c =0;
        for (int j=i; j>=1; j--)
            c+= count (n-1,j);
        return M[{n,i}]=c;
    }
};