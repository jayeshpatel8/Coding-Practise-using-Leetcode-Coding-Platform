class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

    vector<vector<string>> v;
    unordered_map<string,int> map;
    int idx=0;     
        
        for (auto s : strs)
        {            
            string os=s;
            sort(s.begin(),s.end());
            
            if (map[s]==0)
            {
                map[s]=++idx;
                vector<string> vs(1,os);                    
                v.push_back(vs);
            }
            else
                v[map[s]-1].push_back(os);
        }
        return v;
    }
};