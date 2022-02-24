class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int N = friends.size();
        vector<int> vis(N);
        queue<int> q;
        vis[id]=1;
        q.push(id);
        int lvl=level;
        while(!q.empty() && level > 0){
            int sz = q.size();
            while (sz--){
                int u = q.front(); q.pop();
                for (auto i : friends[u]){
                    if (vis[i]) continue;
                    q.push(i);
                    vis[i]=1;
                }
            }
            level--;
        }
        unordered_map<string,int> map;
        while (!q.empty()){
            int u = q.front(); q.pop();
            for (auto &s : watchedVideos[u]){
                //for (auto &s : str)
                    map[s]++;
            }            
        }
        vector<pair<int,string>> p;
        for (auto & [k,v] : map){
            p.push_back({v,k});
        }
        sort(begin(p),end(p));//sort(begin(p),end(p),[](auto  & a, auto &b){return a.first == b.first ? a.second < b.second : a.first > b.first;});
        vector<string> ans;
        for (auto & i : p){
            ans.push_back(i.second);
        }
        return ans;
    }
};