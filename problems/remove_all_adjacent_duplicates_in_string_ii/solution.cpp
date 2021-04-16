class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>   > st;
        st.push_back({'*',0});
        for(auto & c : s){
            if(c == st.back().first) ++st.back().second;
            else st.push_back({c,1});
            if (st.back().second == k) st.pop_back();
        }
        string ans="";
        
        for(auto & i : st){
            //auto i = st.top(); st.pop();
            ans.append( i.second, i.first);
        }
        return ans;
    }
};