class Solution {
public:
    vector<int> partitionLabels(string s) {
        int idx[26] = {};
        for (int i=0; i<s.size(); i++){
            idx[s[i]-'a']=i;
        }
        vector<int> ans;
        for (int i=0, j =0, m = 0 ; i<s.size(); i++){
             m = max(m,idx[s[i]-'a']);
            if (i== m ){
                ans.push_back(m+1-j);
                j=m+1;
            }
        }
        return ans;
    }
};