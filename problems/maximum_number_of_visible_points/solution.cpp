class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double>  ang;
        int x = location[0], y = location[1], ans= 0,overlap=0;
        for (auto &i : points){
            if (i[1] == y && i[0] == x)
                ++overlap;
            else
                ang.push_back(atan2(y-i[1],x-i[0]) * 180  / M_PI);            
        }
        sort(begin(ang),end(ang));

        for (int i=0,j=0, N = ang.size(); i< 2*N; i++){
            while ((i>=N) * 360 + ang[i%N] -(j>=N) * 360 - ang[j%N] >angle){
                j++;
            }
            ans = max(ans,i-j +1);
        }
        return ans+overlap;
    }
};