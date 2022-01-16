class Solution {
public:
    long long maxRunTime(int n, vector<int>& bat) {
        int bt = bat.size();
        if (n == bt){
            return *min_element(begin(bat),end(bat));
        }
        long long l =1, r = accumulate(begin(bat), end(bat), 0LL) / n +1;
        while(l<r){
            long long m = (l + r )/2;
            long long run=0;
            for (auto i : bat) 
                run += min<long long>(i,m);
            if (run < n * m)
                r=m;
            else
                l=m+1;
            
        }        
        return l-1;
    }
};