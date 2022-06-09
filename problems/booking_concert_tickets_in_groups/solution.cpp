
const int N1 = 5e4+10;;
class BookMyShow{
public:
    struct seg{
        int row;
        int start;
        long long total;
    }t[N1<<2];

    int N,M;
    #define lc  (x<<1)
    #define rc  (x<<1|1)
    #define mid  ((l+r)/2)

    void pushup(int x){
        t[x].total = t[lc].total + t[rc].total;
        t[x].start= min(t[lc].start , t[rc].start);
    }
    void build(int x, int l, int r,int m){
        if (l==r){
            t[x].row=l;t[x].start=0,t[x].total=m;
            return;
        }
        build(lc,l,mid,m);
        build(rc,mid+1,r,m);
        pushup(x);
    }

    int qry1(int x, int l, int r, int p, int v){
        if (l==r ) return x;
        if (t[lc].start <= M-v) return qry1(lc,l,mid,p,v);
        else
            return qry1(rc,mid+1,r,p,v);
    }
    void upd1(int x, int l, int r, int p, int v){
        
        if (l==r ){           
            t[x].start =t[x].start+v; t[x].total = t[x].total -v; 
            return;
        }
        
        if (p <=mid )  upd1(lc,l,mid,p,v);
        else  upd1(rc,mid+1,r,p,v);        
        pushup(x);
    }
    long long qry(int x, int l, int r, int ql, int qr){
        if (l>=ql && r<=qr) return t[x].total;
        if (l>qr || r < ql) return 0;
        long long sum = 0;
        if (t[lc].total > 0)
            sum += qry(lc,l,mid,ql,qr);
        if (t[rc].total > 0)
            sum += qry(rc,mid+1,r,ql,qr);
        return sum;
    }
    void upd_scat(int x, int l, int r, int maxRow, int k){
        if (l>maxRow) return;
        if (l==r){t[x].total -=k,t[x].start +=k;  return;}
        
        if (maxRow <= mid || t[lc].total >= k){            
            upd_scat(lc,l,mid,maxRow,k);
        }
        else{
            k-=t[lc].total;
            upd_scat(lc,l,mid,maxRow,t[lc].total);
            upd_scat(rc,mid+1,r,maxRow,k);
        }
        pushup(x);
    }
    BookMyShow(int n, int m) {
        N=n;M=m;

        build(1,0,n-1,m);
    }
    
    vector<int> gather(int k, int maxRow) {
        if (M-t[1].start < k) {return {};}
        int x = qry1(1,0,N-1,maxRow,k);
       if ( t[x].row > maxRow) {return {};}        
        upd1(1,0,N-1,t[x].row,k);

        return {t[x].row,t[x].start-k};;        
    }
    
    bool scatter(int k, int maxRow) {

        if (k > qry(1,0,N-1,0,maxRow)) return false;
        
       upd_scat(1,0,N-1,maxRow,k);
        return true;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */