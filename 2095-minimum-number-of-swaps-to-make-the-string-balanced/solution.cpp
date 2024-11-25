class Solution {
public:
    
    int minSwaps(string s) {
        stack<int> st;
        int ans=0;
        for (int i=0; i< s.size(); i++){
            if (s[i] == '[')
                st.push(s[i]);
            else if (!st.empty()) st.pop();
            else {
                ans++;
            }
                
        }
        return (ans+1)/2;
    }
};
