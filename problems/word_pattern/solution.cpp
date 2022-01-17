class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> map;
        int map2[26]={};
        int i=0, n = s.size();;
        for (auto c : pattern){
            string s1;
            while (i<n && s[i] != ' ')
                s1 +=s[i++];
            if (map.count(s1)){
                if (map[s1] != c) return false;                
            }
            else {
                if (map2[c-'a'] || s1 == "") return false;
                map[s1]=c;
                map2[c-'a']=1;
            }            
            i++;
        }
        return  i>n;
    }
};