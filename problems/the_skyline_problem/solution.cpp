class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& bui) {
        priority_queue<array<int,2>> pq;
        pq.push({0,INT_MAX});
        set<array<int,3>> ev;
        for (int i=0; i<bui.size(); i++){
            ev.insert({bui[i][0],0,i});
            ev.insert({bui[i][1],1,i});
        }
        vector<vector<int>> ans={{(*ev.begin())[0],(*ev.begin())[2]}};
        for (auto &e : ev){
            int i = e[2];
            if (e[1] == 0)
                pq.push({bui[i][2], bui[i][1]});
            else{
                while (!pq.empty() && pq.top()[1] <= e[0]) pq.pop();
            }

            if (ans.back()[1] != pq.top()[0]){
                if (ans.back()[0] == e[0])
                    ans.back()[1]  = pq.top()[0];
                else
                    ans.push_back({e[0],pq.top()[0]});
            }
        }
        return ans;
    }
};