class Solution {
public:
    int minPartitions(string n) {
     int res=1;
        for (auto c : n){
            res = max(res,c-'0');
            if (9 == res)break; 
        }
        return res;
    }
};