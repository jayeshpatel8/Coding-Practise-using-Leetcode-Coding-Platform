class Solution {
public:
    int wordCount(vector<string>& sWords, vector<string>& tWords) {
        int sn = sWords.size(), tn = tWords.size();
       
        unordered_set<int> set;
        for (int i=0; i<sn; i++) {
            int s = 0;
            for (auto c  : sWords[i])
                s|= (1U << ( c - 'a' ));
            set.insert(s);
        }
        
              
        int ans=0;
        for (auto s : tWords){
            int i=0;
            for (auto c  : s)
                i |= (1 << (c-'a'));
            for (auto j : s){
                if (set.count(i & ~(1  << (j-'a')))){
                    ans++;
                    break;
                }            
            }
        }
        return ans;
    }
};