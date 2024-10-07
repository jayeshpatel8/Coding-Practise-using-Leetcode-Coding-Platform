class Solution {
public:
    int minLength(string s) {
        vector<char> st;
        for (auto c : s){
            
            if (st.empty()){
                st.push_back(c);
            }
            else if ( c=='B' && st.back() == 'A'){
                st.pop_back();
            }
            else if ( c=='D' && st.back() == 'C'){
                st.pop_back();
            }            
            else
             st.push_back(c);
        }
        return st.size();
    }
};
