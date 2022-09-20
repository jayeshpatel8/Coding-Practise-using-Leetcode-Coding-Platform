class Solution {
public:
    bool checkDistances(string s, vector<int>& D) {
        int f[126]={};
        for (int i=0; i<s.size(); i++){
            if (f[s[i]]){
                if (i-f[s[i]] != D[s[i]-'a']) return false;
            }
            else
                f[s[i]]=i+1;
        }
        return true;
    }
};