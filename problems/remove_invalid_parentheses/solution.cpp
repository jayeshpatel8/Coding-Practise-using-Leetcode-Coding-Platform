class Solution {
public:
    set<string> ans;
    int N ;
    vector<string> removeInvalidParentheses(string s) {
        int l =0, r= 0;
        N = s.size();
        for (auto c : s){
            if (c == '(') l++;
            else if (c == ')'){
                if(l==0) r++;
                else l--;
            }
        }

        string s1;
        dfs(s,s1,0,0,0,l,r);
        return vector<string>(ans.begin(), ans.end());
    }
    //())
    void dfs(string &s, string& s1, int i, int l, int r, int rem_l, int rem_r ){
        
        if (i == N){
            if ( l!=r  ) return;
            ans.insert(s1);
            return;
        }
        else{
            if (s[i] == '('){                
                if (rem_l)                    
                    dfs(s,s1,i+1,l,r,rem_l-1,rem_r);
                l++;
            }
            else if (s[i] == ')'){                
                if (rem_r)
                    dfs(s,s1,i+1,l,r,rem_l,rem_r-1);
                r++;    
            }
            if (r > l) return;
            s1.push_back(s[i]);
            dfs(s,s1,i+1,l, r, rem_l,rem_r);
            s1.pop_back();
        }
    }
};