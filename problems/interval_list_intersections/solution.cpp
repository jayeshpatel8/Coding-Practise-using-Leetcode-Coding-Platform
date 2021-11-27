class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        int l1 = f.size(), l2 = s.size();
        if (l1==0 || l2==0) return {};
        vector<vector<int>> ans;
        int i=0, j=0, b = 0,e;
        while(i<l1 && j <l2){
            b = max(f[i][0] , s[j][0]);
            e = min(f[i][1] , s[j][1]);
            if ( b<= e) ans.push_back({b,e});
            if (f[i][1] > s[j][1]) j++;
            else i++;
        }
        return ans;
    }
};