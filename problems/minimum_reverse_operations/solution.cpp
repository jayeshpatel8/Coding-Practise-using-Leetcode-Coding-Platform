class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<bool> allowed(n, true);
        vector<int> dist(n, -1);
        for (int i : banned) allowed[i] = false;  
        set<int> odds, evens;
        for (int i=0; i<n; i++) {
            if (allowed[i] && i != p) {
                if (i&1) odds.insert(i);
                else evens.insert(i);
            }
        }
        queue<int> q;
        q.push(p);
        dist[p] = 0;
        while (!q.empty()) {
            int c = q.front();
            q.pop();
            int low = abs(c-k+1), high = n-abs(n-c-k);
            auto& s = low&1 ? odds : evens;
            while (true) {
                auto x = s.lower_bound(low);
                if (x != s.end() && *x <= high) {
                    int v = *x;
                    s.erase(x);
                    dist[v] = dist[c] + 1;
                    q.push(v);
                } else break;
            }
        }
        return dist;
    }
};