class Solution {
public:
    bool areNumbersAscending(string s) {
        int p=-1, n = 0;
        for (int i=0; i<s.size(); i++){
            if (isdigit(s[i])){
                int n= 0;
                while( i < s.size() && isdigit(s[i]) ){
                    n = n* 10 + s[i++]-'0';
                }
                if (p >= n) return false;
                p = n ;
            }
        }
        return true;
    }
};