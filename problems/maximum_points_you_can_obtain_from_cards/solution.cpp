class Solution {
public:
    int maxScore(vector<int>& p, int k) {
        int i = 0 ,sum = 0 , ans = 0;
        for (; i<k; i++)
            sum+= p[i];
        ans = max(ans, sum);
        for (int j = p.size()-1; k>0;k-- )
        {
            sum += (p[j--] - p[--i]);
            ans = max(ans, sum);
        }
        return ans;
    }
};