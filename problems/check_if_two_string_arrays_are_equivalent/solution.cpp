class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
         string w1 ,w2;
        for (auto c : word1) w1+=c;
        for (auto c : word2) w2+=c;
        return w1==w2;
    }
};