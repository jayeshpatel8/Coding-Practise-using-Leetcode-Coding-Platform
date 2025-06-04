class Solution {
public:
    string answerString(string word, int numFriends) {
         if (numFriends == 1) return word;
        int m = word.size() - numFriends + 1;
        string ans="a";
        for (auto i=0 ; i<word.size(); i++){
            if (ans[0] > word[i]) continue;
            ans = max(ans, word.substr(i,m));
        }
        return ans;
    }
};
