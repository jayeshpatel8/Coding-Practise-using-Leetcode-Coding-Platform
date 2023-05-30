class Solution {
public:
    long long minimumCost(string s) {
        long long ans = 0;
        for (int i=1 , N = s.size(); i<N; i++)
            if (s[i] != s[i-1])
                 ans += min(i,N-i);
        
        return ans;
    }
    long long minimumCost2(string s) {
        long long ans = 0;
        for (int i=0 , N = s.size(),j =N-1; i<j; ){
            int lcost = s[i] != s[i+1] ? i+1: 0;
            int rcost = s[j] != s[j-1] ? N-j: 0;
            if (lcost < rcost){
                ans +=lcost;
                i++;
            }
            else if (rcost <= lcost){
                ans += rcost; j--;
            }
        }
        return ans;
    }
};
/*
000111

*/