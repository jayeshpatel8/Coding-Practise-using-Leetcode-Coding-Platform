class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        
        int N=S.size();
        vector<string> ans;
        for (char c : S){
            if (ans.size()){
                vector<string> res;
                for (auto i : ans){
                    string ns = i;
                    i.push_back(c);
                    res.push_back(i);
                    if (c>'9')
                    {
                        ns.push_back(((c>='a' && c<='z')? toupper(c):tolower(c)));    
                        res.push_back(ns);
                    }
                }          
                ans= res;
            }
            else{
                string ns;ns=c;
                ans.push_back(ns);
                ns = ((c>='a' && c<='z')? toupper(c):tolower(c));
                if (c>='9')  ans.push_back(ns);
            }
        }
            return ans;
    }
    vector<string> lcp(string& S, int i) {
        if (S.size()<=i) return vector<string>{};
        vector<string> ans,  t = lcp(S,i+1);
        for (auto s: t){
            string news; news = S[i];
            ans.push_back(news + s);
            if (S[i]>'9'){
                string news2; news2 = (S[i]>='a' && S[i]<='z')? toupper(S[i]):tolower(S[i]);
                ans.push_back(news2 + s);
            }
        }
        if (t.size()==0){
            string news; news = S[i];
            ans.push_back(news );
            if (S[i]>'9'){
                string news2; news2 = (S[i]>='a' && S[i]<='z')? toupper(S[i]):tolower(S[i]);
                ans.push_back(news2);
            }
        }
        return ans;
    }
};