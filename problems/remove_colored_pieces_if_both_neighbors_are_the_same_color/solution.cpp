class Solution {
public:
    bool winnerOfGame(string colors) {
        int cnt[2]={},c[2]={};
        for (auto ch : colors){
            if (c[ch-'A']++ > 1) cnt[ch-'A']++;
            c[!(ch-'A')]=0;
        }   
        return cnt[0] > cnt[1];
    }
};