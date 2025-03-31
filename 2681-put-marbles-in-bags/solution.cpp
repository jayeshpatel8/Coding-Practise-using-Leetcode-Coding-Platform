class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        using ll =  long;
        int N = weights.size();
        vector<ll> pairsum(weights.size()-1);
        for (int i=0;i<weights.size()-1; i++)
            pairsum[i] = weights[i]  + weights[i+1];
        sort(begin(pairsum), end(pairsum));
        
        ll ans=0;
        for (int i=0; i<k-1; i++)
            ans += pairsum[N-2-i]- pairsum[i];
        return ans;
    }
};
