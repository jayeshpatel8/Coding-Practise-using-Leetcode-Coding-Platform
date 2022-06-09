class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        int ans =0;
        unordered_map<int,int> bits;
        for (int i=0; i<rs.size(); i++){
            int r=rs[i][0], b=rs[i][1];
                bits[r] |= 1<<b;

        }
        
        for (auto &[r,b] : bits){            
            int cnt = 0;

            if ((b & 60U) == 0) cnt++;
            if ((b & 15U<<6) == 0)  cnt++;
            if (!cnt && (b & 15U<<4)==0) cnt=1;
            ans+=cnt;
        }
        return ans + 2 * (n - bits.size());
    }
};