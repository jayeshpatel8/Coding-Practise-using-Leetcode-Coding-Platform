class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> map,map2;
        for (int i =0; i<words.size(); i++){
            ++map2[words[i]];
        }
        int  wlen = words[0].size(), N1 = words.size()* wlen;
      
        
        vector<int> ans;
        for (int i1=0, N = s.size(); i1<wlen; i1++ ){
            unordered_map<string,int> map (map2);
            for (int i=i1, j = i1; i<N && j<N-N1+1; ){
                auto s2 = s.substr(i,wlen);
                auto it = map.find(s2);
                if (it != map.end()){
                    while ( it->second <= 0){ // sliding window
                        map[s.substr(j,wlen)]++;
                        j+=wlen;
                    }

                    it->second--;
                    i += wlen;
                    if (i-j == N1) {
                        ans.push_back(j);
                        map[s.substr(j,wlen)]++;
                        j+=wlen;

                    }                
                }
                else{// not matching word found -> start fresh from next word width
                    while ( j < i){
                        map[s.substr(j,wlen)]++;
                        j+=wlen;
                    }
                    i+=wlen;
                    j=i;
                }

            }
        }
        return ans;
    }
};