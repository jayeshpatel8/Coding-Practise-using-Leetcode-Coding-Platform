class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> f(128);
        int n = t.size(), st=-1,en=1e5;
        for (auto c : t)   f[c]++;

        for (int i=0,j=0;i< s.size(); i++){
            auto c = s[i];
           if(--f[c] >= 0) n-- ;
           while (j<=i && n==0){
               if (en-st > i-j) st=j,en=i;
               
               if (++f[s[j]]>0)n++;
               j++;
           }
        }
 
        return st == -1 ? "" : s.substr(st,en-st+1);
    }
};
