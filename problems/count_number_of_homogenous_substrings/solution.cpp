class Solution {
public:
    int countHomogenous(string s) {
        
        int N = s.size();
        
        //"abbcccaa"
        int prev=0,cnt=0,i=0;
        for (; i< N; i++){

            if (s[prev]!=s[i]){
                uint64_t n=i-prev;
                uint64_t c = (n * (n+1)/2 );
                cnt =  (cnt + c) % 1000000007;
                prev=i;                
            }
        }
        unsigned long n=i-prev;

        cnt =  (cnt + (n * (n+1)/2)) % 1000000007;
        return cnt;
    }

};