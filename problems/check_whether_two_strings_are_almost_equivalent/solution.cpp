class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
     int freq[2][128]={};
        for (auto i : word1) freq[1][i]++;
        for (auto i : word2) freq[0][i]++;
        
        for (int i='a'; i<='z'; i++){
            if (abs(freq[1][i]  - freq[0][i]) >3) return false;
        }
        return true;
    }
};