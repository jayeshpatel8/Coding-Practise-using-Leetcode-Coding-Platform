class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int i  = s.size()-1, sum = 0;
        for ( ; i>=0; i--){
            sum = (sum + shifts[i])%26;
            s[i] = (s[i]-'a'+sum )%26 + 'a';
            
        }
        return s;
    }
};