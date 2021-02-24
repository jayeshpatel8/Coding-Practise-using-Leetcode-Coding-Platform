class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res="";
        sort(d.begin(),d.end(),[](auto& a, auto & b){if( a.size()==b.size())return a<b;
                                                     else return a.size() > b.size();});

        for (auto c : d){
            int i=0,j=0;
            while(i<s.size() && j<c.size()){
                if (s[i++]==c[j]){
                    j++;
                }
            }
            
            if (j == c.size()){
                 res = c;break;
            }
        }
        return res;
    }
};