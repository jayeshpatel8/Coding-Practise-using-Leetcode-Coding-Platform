class Solution {
public:
    int minimumLines(vector<vector<int>>& p) {
        sort(begin(p),end(p));
        int ans = 0;
        vector<long double > slop(p.size());
        slop[0]= -100000000.99;
        for (int i=1; i<p.size(); i++){
            //ans++;
            auto & p1= p[i-1], &p2 = p[i];
            slop[i] = ((long double)(p2[1]-p1[1])/ (p2[0]-p1[0]));
            ans += slop[i] != slop[i-1];
            
        }
        
        return ans;
    }
};