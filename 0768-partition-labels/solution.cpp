class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> idx(26), ans;
        for (int i=0; i<s.size(); i++) idx[s[i]-'a']=i;

        for (int i=0; i<s.size(); i++){
            int k=idx[s[i]-'a'];
            for (int j=i+1; j<s.size() && j<=k; j++){
                k  = max(k, idx[s[j]-'a']);
            }
            
            ans.push_back(k-i+1);
            i=k;
        }
        return ans;
    }
};
