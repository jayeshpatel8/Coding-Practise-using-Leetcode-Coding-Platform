class Solution {
public:
    int minBitFlips(int start, int goal) {
        goal ^=start;
        int cnt = 0;
        while (goal){
            cnt++;
            goal &= goal -1;
        }
        return cnt;
    }
};