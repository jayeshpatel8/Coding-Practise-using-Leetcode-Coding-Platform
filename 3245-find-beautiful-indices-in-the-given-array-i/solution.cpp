class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> ai,bj,ans;
        for (int i=0; i<s.size(); i++){
            if (s[i]==a[0]){
                int j=0,k=i;
                for (; k<s.size() && j<a.size(); j++,k++){
                    if (s[k] !=  a[j]) break;
                }
                if (j==a.size()) ai.push_back(i);
            }
        }
        for (int i=0; i<s.size(); i++){
            if (s[i]==b[0]){
                int j=0,k=i;
                for (; k<s.size() && j<b.size(); j++,k++){
                    if (s[k] !=  b[j]) break;
                }
                if (j==b.size()) bj.push_back(i);
            }
        }        
        if (bj.empty()) return ans;
        for (int i=0, j=0; i<ai.size() && j<bj.size(); i++){
            auto it = lower_bound(begin(bj),end(bj),max(0,ai[i]-k));
            
            if (it != end(bj) && (*it <= (ai[i]+k))) ans.push_back(ai[i]);
            //else if (*prev(it) <= i+k) ans.push_back(ai[i]);
        }
        return ans;
    }
};
