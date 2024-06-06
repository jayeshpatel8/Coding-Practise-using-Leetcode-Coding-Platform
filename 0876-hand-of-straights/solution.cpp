class Solution {
public:
    bool isNStraightHand(vector<int> hand, int W) {
                int n = hand.size();
        if (n % W != 0) {
            return false;
        }

        map<int, int> c;
        for (int i : hand) c[i]++;
        for (auto it : c)
            if (c[it.first] > 0)
                for (int i = W - 1; i >= 0; --i)
                    if ((c[it.first + i] -= c[it.first]) < 0)
                        return false;
        return true;
    }
};

// 1 2 3 4  6 7 8
// 0 1 0 0 1 1 1 
