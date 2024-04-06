class Solution {
public:
    string minRemoveToMakeValid(string s) {
     int n= s.size();
        vector<int> st;
        
        for (int i=0; i<n; i++){
            auto c  = s[i];
            if (c ==')'){
                if ( st.empty()) s[i]='*';
                else st.pop_back();
            }
            else if (c =='('){
                st.push_back(i);
            }
        }
        
        for (auto &i : st){
            s[i]='*';
        }
        string ans;
        for (int i=0; i<n; i++){
            if (s[i]!='*')
                ans.push_back(s[i]);
        }
        return ans;
    }
};
