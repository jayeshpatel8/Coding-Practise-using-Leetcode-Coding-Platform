class Solution {
public:
    long long maxRunTime(int n, vector<int>& bat) {
     long long l=0, r= accumulate(begin(bat),end(bat),0LL) /n;
        while (l<r){
            long long m  =  l+(r-l+1)/2 , t=0;
            for (auto i : bat)
                t += min<long long>(i,m);
            if (t <n*m )
                r = m-1;
            else l=m; 
        }   
        return l;
    }
};
