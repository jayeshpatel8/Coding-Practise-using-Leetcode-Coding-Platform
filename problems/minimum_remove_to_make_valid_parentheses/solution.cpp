class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int N=s.size();
        stack<int> st;
        int i=0;
        string res;
        while(i<N){
            if(s[i]==')'){
               if(!st.empty()){
                    st.pop();
               } 
                else s[i]='*';
            }
            else if(s[i]=='('){
                
                st.push(i);
            }
            i++;
        }
        
        while (!st.empty()){
             s[st.top()]='*';st.pop();
        }
        for (auto c : s) {
            if(c != '*') 
                res.push_back(c);
        }
       
        return res;
    }
};