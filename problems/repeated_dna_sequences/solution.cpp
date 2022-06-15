class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int,int> map;
        int ch[26]={}, mask = (1<<20)-1;
        vector<string> ans;
        ch['C'-'A']=1;ch['G'-'A']=2;ch['T'-'A']=3;
        for (int i=0, j=0;i<s.size(); i++){
             j<<=2;
            j|=ch[s[i]-'A'];
            j &=mask;
            if (i>=9){
                auto it = map.find(j);
                if (it == map.end())
                    map[j]=1;
                else if(it->second == 1)
                    ans.push_back(s.substr(i-9,10)), it->second++;
            }
        }
        return ans;
    }
};