class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int map[256]={};
        for (int i=0; i<s1.size(); i++) { map[s1[i]]++;map[s2[i]]--;
                                        }
        for (int i='a'; i<='z'; i++) if (map[i]!=0) return false;
        int change=0;
        for (int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i]){
                bool f=false;
                int idx=s1.find(s2[i],i+1);
                while(idx != string::npos){
                    if (s2[idx] == s1[i]) {
                        swap(s1[idx] ,s1[i]);
                        change++;
                        f=true; break;
                    }
                    idx=s1.find(s2[i],idx+1);
                }
                if (!f || change>1) return false;
            }
        }
        return true;
    }
};