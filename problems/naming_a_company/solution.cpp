class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int freq[26][26]={};
        unordered_set<string> st(begin(ideas),end(ideas));

        for (auto s : ideas) {
            for (int c= 'a',oc=s[0]-'a'; c<='z'; c++){
                s[0]=c;
                if (st.count(s)==0) freq[oc][c-'a']++; 
            }
        }
        long long ans = 0;
        for (int i=0; i<26; i++){
            for (int j=i+1; j<26;  j++){
                if (freq[i][j] && freq[j][i])
                    ans += freq[i][j] * freq[j][i];
            }
        }
        return ans*2;
    }
};