class Solution {
public:
    bool checkIfPangram(string sentence) {
        int ans = (1<<26)-1, bits=0;
        for (auto &c : sentence){
            bits |= 1 << (c-'a');
            if (ans ==  bits) return true;
        }
        return false;
    }
};