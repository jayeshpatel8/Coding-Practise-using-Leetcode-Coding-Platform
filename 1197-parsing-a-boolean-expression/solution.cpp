class Solution {
public:
    bool parseBoolExpr(string expression) {
        int ans = 0;
        vector<int> st;
        for (auto e : expression){
            if (e == ')'){
                bool t=false, f=false;
                while ( st.back() != '('){
                    if (st.back() == 't') t=true;
                    else 
                        f = true;
                    st.pop_back();
                }
                st.pop_back();
                if ( st.back() =='!'){
                    ans = !t ;
                }
                else if (st.back() =='|'){
                    ans = t;
                }
                else ans = (!f) & t;
                st.pop_back();
                ans = ans ? 't' : 'f';
                st.push_back(ans);                
            }
            else if (e != ','){ 
                st.push_back(e);
            }
        }
        return st.back()=='t';
    }
};
