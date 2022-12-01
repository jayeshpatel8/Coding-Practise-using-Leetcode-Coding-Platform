class Solution {
public:
    bool halvesAreAlike(string s) {
        int  cnt   = 0;
        vector<int> freq(128);
        for (int i=0 , j = s.size()-1; i<j; i++,j--){
            freq[s[i]]++, freq[s[j]]--;
        }
        string s1 = "aeiouAEIOU";
        for (auto c : s1)
            cnt +=  freq[c];
        return cnt == 0;
    }
};