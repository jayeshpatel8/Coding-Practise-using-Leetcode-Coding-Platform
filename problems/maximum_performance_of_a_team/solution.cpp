auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> eff(n);
        for (int i=0; i< n; i++)
            eff[i] = {efficiency[i],speed[i]};
        sort(rbegin(eff), rend(eff));
        
        size_t ans=0,sum=0;
        const int mod = 1e9 + 7;
        priority_queue<int,vector<int>,greater<int>> pq;
        for (auto & [ef,speed] : eff){
                sum+= speed;
                pq.push(speed);            
                if (pq.size() > k){
                    sum -=pq.top(); pq.pop();
                }

                ans = max(ans, (sum * ef)); 
        }
        return ans%mod;
    }
};