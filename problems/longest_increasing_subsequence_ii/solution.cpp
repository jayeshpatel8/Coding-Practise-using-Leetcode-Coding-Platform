class Solution {
public:
    vector<int> seg;
    int query(int l, int r, int x, int lx, int rx){
        if (r<lx || l > rx) return 0;
        if (lx >=l && rx<=r) return seg[x];
        int mid = lx+(rx-lx)/2;
        return max(query(l,r,2*x+1,lx,mid), query(l,r,2*x + 2,mid+1,rx));        
    }
    void update1(int idx,int val, int x, int lx, int rx){
        if (lx==rx) {seg[x]=val; return;}
        int mid = lx + (rx-lx)/2;
        if (idx <=mid)
            update1(idx,val,x*2+1,lx,mid);
        else
            update1(idx,val,x*2+2,mid+1,rx);
        seg[x] = max(seg[x*2+1],seg[x*2+2]);
    }
    
    int lengthOfLIS(vector<int>& nums, int k) {
        int N = 1,ans= 0 ;
        while(N <= 200000) N*=2;
        
        seg.resize(2*N,0);
        
        for (auto i : nums){
            int l = max(1,i-k), r= i-1;
            int q = query(l,r,0,0,N-1);
            ans= max(ans, q+1);
            update1(i,q+1,0,0,N-1);
        }
        return ans;
    }
};