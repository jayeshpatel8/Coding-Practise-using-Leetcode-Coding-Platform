class Solution {
public:
    
    int minSwaps(string s) {
        stack<int> st;
        int ans=0, r;
        for (r = s.size()-1; r>=0; r--) 
            if (s[r]=='[')  
                break;
        for (int i=0; i< s.size(); i++){
            if (s[i] == '[')
                st.push(s[i]);
            else if (!st.empty()) st.pop();
            else {
                ans++;
                st.push('['),
                swap(s[i],s[r--]);;
            }
                
        }
        return ans;
    }
};