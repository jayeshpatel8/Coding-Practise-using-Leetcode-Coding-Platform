class Solution {
public:
    int countHomogenous(string s) {
                int N = s.size();
        
        //"abbcccaa"
        int prev=0,cnt=0,i=0;
        for (; i< N; ){
            while(i<N && s[prev] == s[i]) i++;
            if (prev < i-1){
                uint64_t n=i-prev;
                uint64_t c = (n * (n+1)/2 );
                cnt =  (cnt + c) % 1000000007;                                
            }
            else cnt++;
            prev=i;
        }
        return cnt;
    }
};