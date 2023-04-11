class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        vector<int> freq(k+1); int seq=0, cnt=0;
        for (auto r : rolls){
            if (freq[r] == seq){
                freq[r]++;
                if (++cnt % k == 0)
                    seq++;
            }
        }
        return  ++seq;
    }
};