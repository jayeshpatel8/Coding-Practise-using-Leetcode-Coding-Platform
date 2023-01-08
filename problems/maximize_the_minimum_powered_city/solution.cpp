class Solution {
public:
    int N;
    using ll = long long;
    long long maxPower(vector<int>& stations, int r, int k) {
        N = stations.size();
        ll ans=0, L =  0, R = accumulate(begin (stations),end(stations),0L)
+k;
        auto minPow = [&](auto mp){
            vector<int> add(N);
            int avail=k;
            //return true;
            ll window=accumulate(begin (stations),begin(stations)+r,0L);
            for (int i=0; i<N; i++){
                if (i+r<N)
                    window +=stations[i+r];

                if (window < mp){
                    ll diff = mp - window;
                    if (diff > avail) return false;
                    window = mp;
                    avail -= diff;
                    add[min(N - 1, i + r)]+=diff;
                }
                if (i-r>=0)
                    window -=stations[i-r] + add[i-r];
            }
            return true;
        };
        while (L<=R){
            ll mid = (R+L)/2;
            if (minPow(mid))
                ans=mid, L=mid+1;
            else
                R=mid-1;
        }
        return ans;
    }
};