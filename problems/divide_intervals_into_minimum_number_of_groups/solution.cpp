class Solution {
public:
    int minGroups(vector<vector<int>>& A) {
        sort(begin(A),end(A));
        priority_queue<int,vector<int>,greater<int>> pq;
        for (auto &i : A){
            if(!pq.empty() && pq.top()<i[0]) 
                pq.pop();
            pq.push(i[1]);
        }
        return pq.size();
    }
    int minGroups1(vector<vector<int>>& intervals) {
        vector<array<int,2>> A;
        for (auto i : intervals)
            A.push_back({i[0],1}),A.push_back({i[1]+1,-1});
        sort(begin(A),end(A));
        int ans = 0, cur =0;    
        for (auto i : A){
            ans = max(ans, cur +=i[1]);
        }
        return ans;
    }


    int minGroups2(vector<vector<int>>& intervals) {
        multiset<array<int,2>> st;
        for (auto i : intervals)
            st.insert({i[0],i[1]});
        int ans = 0;
        while (!st.empty()){
            auto it = (st.begin());
            ans++;
            while(it != st.end()){
                auto i = (*it)[1];
                st.erase(it);
                it = st.lower_bound({i+1,-1});
            }
            
        }
        return ans;
    }
};