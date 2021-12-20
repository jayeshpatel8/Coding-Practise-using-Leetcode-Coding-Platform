class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = s.substr(0,spaces[0]);
        int j =spaces[0];
        for (int i =1; i< spaces.size(); i++ ){
            ans += " " + s.substr( j, spaces[i]-j );
            j=spaces[i];
        }
        if (j < s.size())
            ans += " " + s.substr(j);
        return ans;
    }
};