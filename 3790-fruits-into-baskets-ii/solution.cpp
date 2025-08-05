class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans=0;
        for (auto i : fruits){
            bool found=false;
            for (auto &j : baskets){
                if ( i <= j){
                     j=-1;
                     found=true;
                     break;
                }
            }
            ans+= !found;
        }
        return ans;
    }
};
