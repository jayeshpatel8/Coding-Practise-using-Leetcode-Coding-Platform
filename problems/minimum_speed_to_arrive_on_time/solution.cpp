class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1, r=1e7+1 , N  = dist.size();
        double last = dist[N-1];
        while (l<r){
            int m =(l+r)/2;
            double h =0;
            for (auto i=0 ; i<N-1; i++){
                auto &d  =  dist[i];
                h += (d/m) + (d%m != 0);                
            }
            h += last/m;
            if (h <= hour)
                r=m;
            else
                l=m+1;
        }
        return r>1e7? -1 : r;
    }
};