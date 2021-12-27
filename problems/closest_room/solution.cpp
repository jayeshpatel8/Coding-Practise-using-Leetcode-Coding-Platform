class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& q)     {
        for (int i=0; i<q.size(); i++) q[i].push_back(i);
        sort(begin(q),end(q),[](auto&a, auto&b){return a[1] > b[1];});
        sort(begin(rooms),end(rooms),[](auto&a, auto&b){return a[1] > b[1];});
        vector<int> ans(q.size());
        set<int> s;
        int j=0;
        for (auto & qu : q){
            for (; j<rooms.size() && rooms[j][1] >= qu[1]; j++)
                s.insert(rooms[j][0]);
            
            auto it = s.lower_bound(qu[0]);
            int lid = it == begin(s) ? -1 : *(prev(it)); 
            int hid = it == end(s) ? -1 : *(it); 
            ans[qu[2]] = min(lid, hid) == -1  ? max(lid, hid): abs(lid - qu[0]) <= abs(hid - qu[0]) ? lid : hid;
        }
        return ans;
    }
};

