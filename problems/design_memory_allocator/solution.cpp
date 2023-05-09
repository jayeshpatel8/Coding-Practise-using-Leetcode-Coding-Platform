class Allocator {
public:
unordered_map<int,vector<int>> mid;
int A[1001]={}, N;
    Allocator(int n) {
        N=n;
        A[N]=n;
    }
    
    int allocate(int size, int mID) {
        for(int i=0,p=-1; i<=N; i++){
            if (A[i]>0){
                if (i-p-1 >= size){
                    A[p+1]=size;
                     mid[mID].push_back(p+1);
                     return p+1;
                }
                i=i+A[i]-1;
                p=i;
            }            
        }
        return -1;
    }
    
    int free(int mID) {
        if (mid.count(mID)==0) return 0;
        int c=0;
        for (auto v : mid[mID])
            c+=A[v], A[v]=0;
        mid.erase(mID);
        return c;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */