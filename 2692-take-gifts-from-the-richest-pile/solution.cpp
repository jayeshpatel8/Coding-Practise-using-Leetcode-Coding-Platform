class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q;
        for (auto i : gifts) q.push(i);
        while (k-- > 0){
            auto i = q.top(); q.pop();
            int left = floor(sqrt(i));
            q.push(left);
        }
        long long ans = 0;
        while (!q.empty()){
            ans += q.top(); q.pop();
        }
        return ans;
    }
};
