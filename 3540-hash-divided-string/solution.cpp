class Solution {
public:
    string stringHash(string s, int k) {
        string ans;
        for (int i=0; i<s.size(); i++){
            int sum = 0;
            for (int j=0; j<k; j++){
                sum +=s[i+j]-'a';
            }
            i+=k-1;
            ans+= (sum % 26) + 'a';
        }
        return ans;
    }
};
