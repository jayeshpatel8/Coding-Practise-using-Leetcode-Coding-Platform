class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int N = words.size();
        vector<int> psum(1),ans;
        unordered_set<int> st;
        string vow = "aeiou";
        for (auto c : vow) st.insert(c);
        int sum = 0;
        for (auto &w : words){
            if (st.count(w[0]) && st.count (w[w.size()-1]))
                sum++;
            psum.push_back(sum);
        }
        for (auto &q : queries){
            ans.push_back(psum[q[1]+1]-psum[q[0]]);
        }
        return ans;
    }
};
