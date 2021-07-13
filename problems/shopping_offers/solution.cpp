class Solution {
public:
    int N ;
    string ns;
    unordered_map<string,int> M;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        N= needs.size();
        ns= string(N,'0');
        return dfs(price, special, needs);
    }
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs){
        string need; 
        for_each(begin(needs), end(needs),[&need](int x){need.push_back(x);});
        if (need == ns) return  0;
        if (M.count(need))return M[need];
        int cost = 0;
        for (int i=0; i<N; i++) cost += price[i]*needs[i];
        for (int si=0; si<special.size(); si++)
        {
            // take one special
            int i=0;
            for (; i< N ; i++){
                if (needs[i] < special[si][i] ) break; 
                needs[i] -= special[si][i];                 
            }
            if (i==N)
                cost = min(cost, special[si].back() +dfs(price, special, needs));
            
            for (--i; i>=0 ; i--) needs[i] += special[si][i];
                  
        }
        return M[need]=cost;
    }
};