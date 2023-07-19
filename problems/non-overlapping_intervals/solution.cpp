class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inte) {
        sort(begin(inte),end(inte))        ;
/*
[1,30] delete y
    [1,30]
    [1,40]
[1,30] delete x
    [2,2]
    [2,30]
    [2,40]
    
*/
        int ans=  0;
        for (int i=1,end=inte[0][1]; i<inte.size(); i++){
            if (end <= inte[i][0]){
                end = inte[i][1];
            }
            else {
                ans++;
                end = min(end, inte[i][1]);
            }
        }
        return ans;
    }
};
