class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
         long l = 1, r = 1e14;
        
        auto trip = [&]( long t){
             long ans = 0;
            for (auto i : time){
                ans += t/i;
                if (ans >= totalTrips) return true;
                
            }
            return false;
        };
        while ( l<r ){
             long m = ( l + r) / 2;
            if ( !trip(m))
                l = m + 1;
            else 
                r = m;
        }
        return l;
    }
};