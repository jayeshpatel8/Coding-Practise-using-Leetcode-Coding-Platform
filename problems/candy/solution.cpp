class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 0;
        vector<int> can(ratings.size() , 1);
        for (int i=1; i<ratings.size(); i++){
            if (ratings[i-1]< ratings[i]){
                can[i] = can[i-1] + 1;
            }
        }
        for (int i=ratings.size()-2; i>=0; i--){
            if (ratings[i+1] < ratings[i]){
                can[i] =max(can[i+1]+1,can[i]);
            }
            ans +=can[i];
        }
        return ans + can[ratings.size()-1];
    }
};
/*
1,2,87,87,87,2,1
1 2 3  1  3 2  1
*/