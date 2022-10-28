class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<pair<string,int>> st;
       for (int i=0; i < strs.size(); i++){
           auto s = strs[i];
           sort(begin(s), end(s));
           st.push_back({s,i});
       }
       sort(begin(st),end(st));
       vector<vector<string> > ans;
       for (int i=0; i<st.size(); i++){
           vector<string>  s;
           int j=i;
           for (; j<st.size(); j++){
               if (st[i].first ==st[j].first)
                s.push_back(strs[st[j].second]);      
                else
                break;         
           }
           i  = j-1;
           ans.push_back(s);
       }
       return ans;
    }
};