class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& tar) {
       int a =0,b=0,c=0;
        int t1 = tar[0],t2=tar[1],t3 = tar[2];
        for (auto & t : triplets){
            if (t[0] <= t1 && t[1] <= t2 && t[2] <= t3){
                a |= (t[0] == t1);
                b |=(t[1] == t2);
                c |=(t[2] == t3);
            }
        }
        return a && b && c;
    }
};