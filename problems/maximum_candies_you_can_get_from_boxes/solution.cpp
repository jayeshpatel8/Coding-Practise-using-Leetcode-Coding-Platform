class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& cBoxes, vector<int>& ib) {
        int N = status.size();
        vector<bool> box(N);
        set<int> unopen;
        int ans = 0;
        for (auto i : ib) unopen.insert(i);
        bool f=true;
        while (f){
            set<int> n;
            f=false;
            for( auto i : unopen){                
                if (status[i]){
                    ans += candies[i];
                    f=1;
                    for (auto k : keys[i]) status[k]=1;
                    for (auto j : cBoxes[i]) n.insert(j);
                }
                else n.insert(i);
            }
            unopen = n;
        }
        return ans;
    }
};