class Solution {
public:
    int maxVowels(string s, int k) {
        int cnt=0, ans = 0;
        unordered_set<char> st = {'a','e','i','o','u'};
        for (int i=0,j=0; i<s.size(); i++){
            cnt += st.count(s[i]);
            if (i>=k-1){
                ans = max(ans,cnt);
                cnt -= st.count(s[j++]);
            }
        }
        return ans;
    }
};