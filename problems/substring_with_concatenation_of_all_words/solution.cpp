class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> r;
        if (words.empty() || !s.length()) return r;
        int w=words.size();
        int w_len=words.front().length();
        int w_t_len=words.front().length()*w;
        
        unordered_map<string,int> w_map;
        for (auto i : words)
            w_map[i]++;
        for (int i=0; (s.length()-i) >= (w_t_len) ; i++){
             unordered_map<string,int> local_map;
            int j;
            for (j=0; j < w_t_len; j+=w_len)
            {                
                string ts = s.substr(i+j,w_len);
                if (w_map.find(ts) == w_map.end()){                    
                    break;
                }
                else {                    
                   local_map[ts]++; 
                    if (local_map[ts] > w_map[ts]) break;
                }
            }
            if(j == w_t_len){
                r.push_back(i);
            }
        }
        return r;
    }
};