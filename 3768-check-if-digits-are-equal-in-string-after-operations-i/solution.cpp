class Solution {
public:
    bool hasSameDigits(string s) {
        int N= s.size();

        while (N > 2){
            for (int i=1; i<N; i++){
                s[i-1] = (s[i-1]-'0' + s[i]-'0')%10+'0';
            }
            N--;
        }
        return s[0] == s[1];
    }
};
