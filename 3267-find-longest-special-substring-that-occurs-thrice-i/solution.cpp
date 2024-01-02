class Solution {
public:
    int maximumLength(string s) {
        int ans = -1;
        for (int c='a'; c<='z'; c++){
            for (int l=s.size()-2; l>0 && l>ans; l--){
                bool found =true;
                int cnt=0;
                for (int i=0; i<s.size(); i++){
                    if (s[i]==c){
                        int ct=l;
                        for (int j=i; j<s.size() && ct >0; j++ ,ct--){
                            if (s[j] != c) break;
                        }
                        if (ct == 0) {
                            cnt++;
                        }                        
                    }
                }
               
                if (cnt >=3) ans=max(ans, l);
            }
        }
        return ans;
    }
};
