class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans  = 0;
        string vow = "aeiou";
        unordered_set<int> st;
        for (auto c : vow) st.insert(c);
        for (int i=left; i<=min <int>(words.size()-1,right); i++){
            if (st.count(words[i][0]) && st.count(words[i].back())) ans++;
        }
        return ans;
    }
};