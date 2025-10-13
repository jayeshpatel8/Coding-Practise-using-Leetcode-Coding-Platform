class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        for (int i=0, n = words.size(); i<n; ){
            string s = words[i];
            sort(begin(s),end(s));
            int j=i+1;
            for (; j<n; j++){
                string s1 = words[j];
                sort(begin(s1),end(s1));
                if (s != s1) break;                
            }            
            ans.push_back(words[i]);
            i=j;
        }
        return ans;
    }
};
