class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1   + str2 != str2 + str1) return "";
        return str1.substr(0,gcd(str1.size(),str2.size()));
    }

    string gcdOfStrings2(string str1, string str2) {
        if (str1.size() > str2.size()) swap(str1, str2);
        auto gcd = [](string & s2, string & s, int i){
            
            int k = 0;
            
            for (int j=0; j <s2.size(); j++,k = (k+1)%i){
                if (s2[j] != s[k]) return false;
            }
            return k==0;
        };
        for ( int i=str1.size(); i>0; i--){
            if (gcd(str1,str1,i)){
                if (gcd(str2,str1,i)) return str1.substr(0,i);
            }
        }
        return "";
    }

};