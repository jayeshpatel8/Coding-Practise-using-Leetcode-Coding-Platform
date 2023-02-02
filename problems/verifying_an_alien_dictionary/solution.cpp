class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> idx(26);
        for (int i=0; i< order.size(); i++) idx[order[i]-'a']=i;
        string prev="";
        for (auto & s : words){
            auto i=0,j=0;
            for (; i<prev.size() && j < s.size(); i++, j++){              
                if (idx[prev[i]-'a']  == idx[s[j]-'a']) continue;
                else break;
            }
            if ((j==s.size() && i!=prev.size()) || (i<prev.size() && idx[prev[i]-'a'] > idx[s[j]-'a'])) return false;
            prev=s;
        }
        return true;
    }
};