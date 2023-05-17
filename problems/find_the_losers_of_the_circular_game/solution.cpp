class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> vis(n,1),ret;
        int i=0,c=1;
        while (vis[i])
            vis[i]=0, i= (i+ c++ * k) %n;
        
        for (auto i =0 ; i< vis.size(); i++)
            if (vis[i]) ret.push_back(i+1);
        return ret;
    }
};