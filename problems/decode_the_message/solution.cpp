class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> m;
        char i='a';
        m[' ']=' ';
        for (auto c : key){
            if (m.count(c)) continue;
            m[c]=i++;
        }

        string ans;
        for( auto c : message){
            ans += m[c];
        }
        return ans;
    }
};