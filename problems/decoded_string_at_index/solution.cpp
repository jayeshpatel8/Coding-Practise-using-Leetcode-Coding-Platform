class Solution {
public:
    string decodeAtIndex(string s, int k) {
        string str;
        long long len=0,i=0;
        while (len < k){
            if (isdigit(s[i])) len *=s[i]-'0';
            else len++;
            i++;
        }

        for (--i; i>=0; i--){
            auto c = s[i];
            if (isdigit(c)){
                len /=c-'0';
                k%=len;
            }
            else{                
                if (len == k || k==0) return string(1,c);
                len--;
            }
        }

        return str;
    }
};