class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int can) {
        using ar = array<int,2>;
        priority_queue<ar, vector<ar>,greater<>> pq;
        int i=0, j=costs.size()-1;
        long long ans = 0;
            for (int i1=i+can; i<i1 ; i++){
                pq.push({costs[i],i});
            }
            for (int j1=j-can; j>j1 && i<=j; j--){
                pq.push({costs[j],j});
            }        
        while (k-- > 0){
            auto c = pq.top();
            ans += c[0]; pq.pop();
            if (i>j) continue;
            if (c[1] < i)
                pq.push({costs[i],i++});
            else if (c[1] > j)
                pq.push({costs[j],j--});
        }
        return ans;
    }
};