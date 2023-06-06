class Solution {
public:
    double getMinDistSum(vector<vector<int>>& pos) {
        double ans = DBL_MAX;
        vector<double> p(2, 0);
        double step=100, eps = 1e-6;
        const int dirs[] = {-1,0,1,0,-1};
        
        while (step > eps){
            bool found =false;
            for (int d=0; d<4; d++){
                vector<double> next = {p[0] + step * dirs[d], p[1] + step * dirs[d+1]};
                
                double d1 =  dist(pos, next);
                if (d1 < ans){
                    ans=d1;
                    p=next;
                    found=true;
                    break;
                }
            }
            if (!found) step/=10;
        }
        return ans;
    }
    double dist(vector<vector<int>>& pos , vector<double> &a){
        double ans  = 0;
        for (auto & p : pos){
            ans += sqrt(pow(a[0]-p[0],2)+pow(a[1]-p[1],2));
        }
        return ans;
    }
};