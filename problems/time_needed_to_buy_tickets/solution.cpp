class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        int c = 0;
        for (int i=0; i< t.size(); i++){            
            c += min(t[i],t[k] - (i>k));
        }
        return c;
    }
};