class Solution {
public:
    string shortestPalindrome(string s)
    {
        int n = s.size();
        string r(s);
        reverse(begin(r),end(r));
        string new_s = s + "#" + r;
        int n_size = new_s.size();
        vector<int> kmp(n_size);
        for( int i=1 , j ; i<n_size; i++){
            
            j = kmp[i-1];
            while(j > 0 && new_s[j] != new_s[i] )
                j = kmp[j-1];
            if (new_s[j] == new_s[i] ) j++;
            kmp[i] = j;
        }
        return r.substr(0, n - kmp[n_size - 1]) + s;
    }
};