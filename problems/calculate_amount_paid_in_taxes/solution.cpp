class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0, prev = 0;
        for (auto &i : brackets){
            if (i[0] >= income){
                i[0] = income;
                ans += ( i[0]-prev) * (i[1]) * (double)0.01;
                break;
            }
            ans += ( i[0]-prev) * (i[1]) * (double)0.01;
            prev = i[0];
            
        }
        return ans;
    }
};