class Solution {
public:
    int minPartitions(string n) {
     int ans  =0;   
        for (auto c : n) ans = max<int>(ans,c);
        return ans -'0';
    }
};