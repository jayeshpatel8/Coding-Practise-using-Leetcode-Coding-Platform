class Solution {
public:
    int minimumDeletions(string s) {
        int cnt1=0;
        vector<char> st;
        for (auto c : s){
            if(!st.empty() && c=='a' &&st.back() == 'b'){
                cnt1++;
                st.pop_back();
            }
            else
            st.push_back(c);
        } 
    
        return cnt1;
    }
};

//  aab
//  aaba - 1
//  aabaa - 1
// aababb
