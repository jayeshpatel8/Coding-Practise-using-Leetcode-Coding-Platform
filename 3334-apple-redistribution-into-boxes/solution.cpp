class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& cap) {
        int a = accumulate(begin(apple), end(apple), 0);
        sort(rbegin(cap), rend(cap));
        int ans = 0;
        for (auto i : cap){
            a -= i;
            ans++;
            if (a <=0) return ans;
        }
        return 0;
    }
};
