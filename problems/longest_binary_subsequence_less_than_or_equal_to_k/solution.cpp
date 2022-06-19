class Solution {
public:
    int longestSubsequence2(string s, int k) {
        int ans =0 , N =s.size();
        reverse(begin(s),end(s));
        for (int i = 0, j = 0; i<N; i++ ){
            if (s[i] == '0') ans++;
            else if (i<30){
                j |= 1<<i;
                if (j <= k){
                    ans++;
                }
            }
        }
        
        return ans;
    }

    int longestSubsequence(string s, int k) {
        int ans =0 , N =s.size();

        for (int i = 0 , j = 0; i<N; i++ ){
            if (s[i] == '0') ans++;
            else if ((N-i-1)<31 ){
                if (((j + (1<< (N-i-1))) <= k)){
                    j += (1 <<  (N-i-1));
                    ans++;
                }
                else{
                    j>>=1;
                }
            }
        }
        
        return ans;
    }

};