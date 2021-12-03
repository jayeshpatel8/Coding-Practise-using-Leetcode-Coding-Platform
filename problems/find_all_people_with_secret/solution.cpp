class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> uf(n,-1);
        sort(begin(meetings), end(meetings),[](auto &a, auto &b){return a[2] < b[2];});
        uf[firstPerson]=0;
        for (int i =0; i<meetings.size(); ){
            unordered_map<int,int> M;
            int j=i;
            for (; j<meetings.size() && meetings[j][2] ==meetings[i][2]; j++){
                int u = find(uf,meetings[j][0]) , v =find(uf,meetings[j][1]);
                if (u!=v)
                    uf[max(u,v)]=min(u,v);                
            }
            for (;i<j;i++)
            {
                int u = find(uf,meetings[i][0]) , v =find(uf,meetings[i][1]);
                if (u != 0) uf[meetings[i][0]] = -1;
                if (v != 0) uf[meetings[i][1]] = -1;
            }
        }
        vector<int> ans;
        for (int i=0; i<n; i++)
            if (find(uf,i) == 0) ans.push_back(i);
        return ans;
    }
    int find (vector<int> &uf, int i){
        return uf[i] < 0 ? i : uf[i] = find(uf,uf[i]);
    }
};