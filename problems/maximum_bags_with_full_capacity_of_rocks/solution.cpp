class Solution {
public:
    int maximumBags(vector<int>& C, vector<int>& rocks, int addRocks) {        
        for (int i=0; i<C.size(); i++)
            C[i]-=rocks[i];
        int ans = 0;
        sort(begin(C),end(C));
        for (auto d : C){
            if (addRocks < d) return ans;
            ans++;
            addRocks -=d;
        }
        return ans;
    }
};