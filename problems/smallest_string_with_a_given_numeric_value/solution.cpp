class Solution {
public:
    string getSmallestString(int n, int k) {
        string s;
        for( int i=1; i<=n; i++){
            int rem = k - (n-i) * 26;
            if (rem <= 0)
                rem=1;
            
                s+=rem+'a'-1;
            k-=rem;
        }
        return s;
    }
};