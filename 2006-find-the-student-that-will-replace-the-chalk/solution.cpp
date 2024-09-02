class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        using ll = long long;
        ll sum   = 0;
        for (auto c : chalk) sum+=c;

        k = k % sum;

        int cur = 0;
        for (int i=0; i<chalk.size(); i++){
            cur += chalk[i];
            if ( k < cur ) return i;
        }
        return 0;
    }
};
