class Solution {
public:
    int largestVariance(string s) {
        int ans = 0, f[26]={};
        for (auto c : s) f[c-'a']++;

        for (int a='a'; a<='z'; a++){
            for (int b='a'; b<='z'; b++){
                if (a==b || f[b-'a']==0) continue;
                int c1=0,c2=0, prev_b=0;
                for(auto c : s){
                    if (c==a) c1++;
                    else if (c ==b) c2++;
                    if (c2) ans=max(ans, c1-c2);
                    else if (prev_b) ans=max(ans, c1-1);

                    if (c2 > c1) c1=c2=0,prev_b=1;
                }
            }
        }
        return ans;
    }
};