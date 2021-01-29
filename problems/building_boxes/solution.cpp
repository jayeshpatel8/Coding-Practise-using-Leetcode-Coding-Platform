class Solution {
public:
    int minimumBoxes(int n) {
        if (n<=3) return n;
        
        auto total = [] (uint64_t n) { return n * (n+1) * (n+2) / 6; };
        
            uint64_t lo=1, hi=min((n),10000);
            while (lo < hi){
                uint64_t mid = lo + (hi-lo)/2;
                uint64_t t = total(mid);
                
                if (t>n) hi=mid;
                else if (t<n)lo=mid+1;
                else {lo=mid;break;}
            }
            lo--;
        
        auto onFloor = [] (uint64_t n) { return n * (n+1)  / 2; };
        
        uint64_t r = n - total(lo);
        
        uint64_t onfloor = onFloor(lo);
        if (r>0){
            
            lo=1,hi=r;
            while(lo<hi){
                uint64_t mid = lo+(hi-lo)/2;
                if (onFloor(mid)<r) lo=mid+1;
                else  hi=mid;                
            }
            onfloor +=hi;
        }
        return onfloor;
        
    }
};