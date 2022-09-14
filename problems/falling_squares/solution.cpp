class Solution {
public:
    int N = 1024*1024;
    vector<int> height,lazy, ans;
     void push_down(int i) {
        if (lazy[i]) {
            lazy[i*2] = lazy[i*2+1] = lazy[i];
            height[i*2] = height[i*2+1] = lazy[i];
            lazy[i] = 0;
        }
      }
    int query(int l, int r, int idx, int lx, int rx){
        if (l<=lx && rx<= r) return height[idx];
        int mid = lx +(rx-lx)/2, res = 0;
        push_down(idx);
        if (l <mid) res=query(l,r,idx*2 , lx,mid);
        if (r>mid) res=max(res, query(l,r,2*idx +1, mid,rx));
        return res;
    }
    void upd(int l, int r,int v, int idx, int lx, int rx){
      //  if (l>rx || r< lx) return ;
        if (l<=lx && rx<= r){
            height[idx] = v; 
            lazy[idx] = v;return;    
        }

        int mid = lx +(rx-lx)/2,res= 0 ;
        push_down(idx);
        if (l <mid) upd(l,r, v, idx*2 , lx,mid);
        if (r > mid) upd(l,r, v, idx*2 +1, mid,rx);
        height[idx]= max(height[idx*2], height[idx*2 + 1]);
    }
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> a;
        for (auto& p : positions) {
          a.push_back(p[0]);
          a.push_back(p[0]+p[1]);
        }
        sort(a.begin(), a.end());
        N = unique(a.begin(), a.end()) - a.begin();
        a.resize( N);
        //while (N <= 100000000) N *=2;
        height.resize(4 * N);
        lazy.resize(4 * N);
      
      
        for (auto &p : positions){
              int l = lower_bound(a.begin(), a.end(), p[0]) - a.begin();
              int r = lower_bound(a.begin(), a.end(), p[0]+p[1]) - a.begin();            
            int h = query(l, r,1,0,N);
            
            upd(l, r,h+p[1], 1,0,N);
            ans.push_back( query(0, N,1,0,N));
        }
        return ans;
    }
};