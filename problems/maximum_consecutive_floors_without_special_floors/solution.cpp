class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& sp) {
        sort(begin(sp), end(sp));
        int i=1,  ans = 0;
        
        if (sp[0] != bottom) ans = sp[0]-bottom;
        
        for ( ; i<sp.size(); i++){
            ans = max (ans, sp[i]-sp[i-1]-1);
        }
        
        ans = max(ans, top - sp[sp.size()-1]);
        return ans;
    }
    
};