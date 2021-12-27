class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(begin(tasks), end(tasks),[](auto&a, auto &b){ return a[1]-a[0] > b[1]-b[0];});
        int ans = 0, bal=0;
        for (auto &i : tasks){
            if (bal < i[1])
                ans +=  i[1]-bal,bal=i[1];
            
                bal -= i[0];
        }
        return ans;
    }
};