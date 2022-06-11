class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        bool ch[256][256]={};
        for (auto &i : mappings)
            ch[i[0]][i[1]]=true;
        
        for (int i=0 ,N =s.size(),M = sub.size();  i<N; i++){
            int j =0, i1= i;

            for (; j<M && i1 <N; j++,i1++){
                if (s[i1] != sub[j])
                    if (!ch[sub[j]][s[i1]])  break;
            }
            if (j==M) return true;
        }
        return false;
    }
};