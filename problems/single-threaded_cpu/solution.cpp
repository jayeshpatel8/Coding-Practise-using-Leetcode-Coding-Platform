class Solution {
public:
using ll = long long;
    vector<int> getOrder(vector<vector<int>>& tasks) {    
        int  N =  tasks.size();
        vector<int> ans(N),idx(N);
        iota(begin(idx),end(idx),0);
        sort(begin(idx),end(idx)
        ,[&](auto & a, auto & b){
            return  tasks[a][0] < tasks[b][0];
        });

        set<pair<int,int>> st;
        int ansi=0;
        ll start = tasks[idx[0]][0];
        for (int j=0; j<N; ){
            while(j<N && tasks[idx[j]][0] <= start){
                st.insert({tasks[idx[j]][1],idx[j]});
                j++;
            }
            if (st.empty()){
                start = tasks[idx[j]][0];
            }
            else{           
                start += (*st.begin()).first;            
                ans[ansi++] = (*st.begin()).second;
                st.erase(begin(st));
            }
        }
        for (auto & a : st){
            ans[ansi++] = a.second ;
        }
        return ans;
    }
};