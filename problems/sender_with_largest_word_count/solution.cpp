class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,long> cnt;
        long ma=0;
        for (int i=0; i<senders.size(); i++){
            cnt [senders[i]] += count(begin(messages[i]), end(messages[i]), ' ') + 1;
            ma= max(ma,cnt [senders[i]]);
        }
        set<string> st;
        for ( auto [s,l] : cnt){
            if (ma==l)
                st.insert(s);
        }
        return *prev(st.end());
    }
};