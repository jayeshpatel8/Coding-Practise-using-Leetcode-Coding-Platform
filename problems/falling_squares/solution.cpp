class Solution {
public:
    int N = 1024*1024;
    vector<int> height,lazy, ans;    
    #define lc  (i<<1 |1)
    #define rc  ((i<<1) + 2)
    #define mid  (lo+((hi-lo)>>1))    
     void push_down(int i, int lo, int hi) {
         
        if (lazy[i]) {  
            height[i] =  lazy[i];
            if (hi !=lo)
                lazy[lc] = lazy[rc] = lazy[i];
            lazy[i] = 0;
        }
      }   

    int query( int l, int r, int i, int lo, int hi){
        
        if (hi < l || lo > r || lo > hi) return 0;
        push_down(i,lo,hi);
        if (l<= lo && hi<=r) return height[i];
         return max(query(l,r,lc,lo,mid),query(l,r,rc,mid+1,hi)); 
    }
    void upd( int l, int r,int val, int i, int lo, int hi){

       
        if (hi < l || lo > r || lo > hi) return ;
        
        if (l<= lo && hi<=r) {
            lazy[i] = val;
            push_down(i,lo,hi);
            return ;
        }
        push_down(i,lo,hi);
        upd(l,r,val,lc,lo,mid); 
        upd(l,r,val,rc,mid+1,hi);
        height[i] = max(height[lc],height[rc]);
        return;
    }    
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> a;
        for (auto& p : positions) {
          a.push_back(p[0]);
          a.push_back(p[0]+p[1]-1);
        }
        sort(a.begin(), a.end());
        N = unique(a.begin(), a.end()) - a.begin();
        a.resize( N);
        //while (N <= 100000000) N *=2;
        height.resize(4 * N);
        lazy.resize(4 * N);

      int m=0;
        for (auto &p : positions){
            int l = lower_bound(a.begin(), a.end(), p[0]) - a.begin();
            int r = lower_bound(a.begin(), a.end(), p[0]+p[1]-1) - a.begin();            
            int h = query(l, r,0,0,N-1);
            upd(l, r,h+p[1], 0,0,N-1);
            m=max(m,h + p[1]);
            ans.push_back( m);
        }

        return ans;        
    }
};