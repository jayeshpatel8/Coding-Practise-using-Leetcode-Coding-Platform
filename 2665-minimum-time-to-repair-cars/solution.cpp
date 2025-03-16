class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        using ll  =  long long;
        ll l=0,r=   100 * 1e6 * 1e6;

        while (l<r){
            ll m = (l + r)/2;
            ll c = 0;
            for (auto r : ranks)
                c += sqrt(m/r);
            if (c >= cars) r=m;
            else l=m+1;
        }          
        return r;
    }
};
