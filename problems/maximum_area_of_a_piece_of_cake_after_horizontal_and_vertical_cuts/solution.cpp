class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        
        int m = hc.size(), n = vc.size();
       
          int  hdiff=hc[0], vdiff=vc[0];
        
        for (int i=1; i< m; i++) hdiff = max(hdiff,( int)( hc[i]-hc[i-1])) ;
        for (int i=1; i< n; i++) vdiff = max(vdiff, ( int) (vc[i]-vc[i-1])) ;
        hdiff = max(hdiff, h-hc[m-1]);
        vdiff = max(vdiff, w-vc[n-1]);
               
        return ((uint64_t)hdiff * vdiff) % ( (int)  1e9 + 7);
    }
};