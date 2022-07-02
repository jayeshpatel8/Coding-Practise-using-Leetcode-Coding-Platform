class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        
        sort(begin(hc),end(hc));
        sort(begin(vc),end(vc));
        hc.push_back(h),vc.push_back(w);
        int hmax = hc[0], wmax=vc[0] , mod = 1e9 + 7;
        for (int i=1; i< hc.size();i++)
            hmax = max( hmax, hc[i]-hc[i-1]);
        
        for (int i=1; i< vc.size();i++)
            wmax = max( wmax, vc[i]-vc[i-1]);
                
        return ((long) hmax * wmax)% mod;
    }
};