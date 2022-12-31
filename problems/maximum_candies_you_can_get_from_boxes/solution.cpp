class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& cBoxes, vector<int>& unopen) {
        int N = status.size();
        vector<bool> box(N);
        
        int ans = 0;
        //for (auto i : ib) unopen.insert(i);
        bool f=true;
        while (f){
            vector<int> n;
            f=false;
            for( auto i : unopen){                
                if (status[i]){
                    ans += candies[i];
                    f=1;
                    for (auto k : keys[i]) status[k]=1;
                    n.insert(end(n),begin(cBoxes[i]),end(cBoxes[i]));
                }
                else n.push_back(i);
            }
            unopen = n;
        }
        return ans;
    }
};