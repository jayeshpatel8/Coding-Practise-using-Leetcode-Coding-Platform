class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<int> stack;
        vector<double> ans(cars.size(), -1);
        for (int i=cars.size()-1; i>=0; i--){
            int pos = cars[i][0],  s = cars[i][1];
            while (!stack.empty() ){
                int j = stack.back();
                if ( s <= cars[j][1] || ((double)cars[i][0] - cars[j][0]) / (cars[j][1] -cars[i][1]) > ans[j] && ans[j] > -1)
                    stack.pop_back();
                else                
                break;
            }
            if (!stack.empty()){
                int j = stack.back();
                ans[i] = ((double)cars[i][0] - cars[j][0]) / (cars[j][1] -cars[i][1]) ;
                
            }
            stack.push_back(i);
        }
        return ans;
    }
};