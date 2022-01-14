class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(begin(tasks),end(tasks),[](auto &a, auto &b){ return a[1]-a[0] > b[1]-b[0] ;});
        
        int e = 0, s=0;
        for (auto &t : tasks){
            if (s >= t[1])
                s -= t[1];
            else
                e += t[1]-s, s= 0;
            s += t[1] - t[0];
        }
        return e;
        
    }
};