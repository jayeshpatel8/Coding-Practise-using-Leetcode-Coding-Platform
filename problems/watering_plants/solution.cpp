class Solution {
public:
    int wateringPlants(vector<int>& P, int C) {
        int c = C, ans = 0;
        for (int i=0; i<P.size(); i++){
            if (c >= P[i]) {
                c -=P[i]; ans++; continue;
            }
            else{
                ans += i + i + 1;
                    c = C - P[i];
            }
        }
        return ans;
    }
};