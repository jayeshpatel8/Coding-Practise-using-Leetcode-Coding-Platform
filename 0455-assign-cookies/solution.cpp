class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g),end(g));
        sort(begin(s),end(s));   
        int  ans = 0;
        for (int i =0, j =0; i<g.size() && j<s.size(); j++){
            if (s[j] >= g[i]) {ans++; i++;}
            
        }
        return ans;
    }
};
