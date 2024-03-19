class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int f[26]={};
        for (auto i : tasks) f[i-'A']++;
        sort(begin(f),end(f));
        int t = (f[25]-1) * (n+1);
        for (auto i : f) if (i==f[25]) t++;
        return max<int>(t, tasks.size());
    }
};
