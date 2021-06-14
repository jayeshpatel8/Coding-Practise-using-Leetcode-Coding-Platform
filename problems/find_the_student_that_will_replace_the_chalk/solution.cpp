class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
     uint64_t sum = 0;
        vector<long> csum(chalk.size());
        
        for (int i=0; i<chalk.size(); i++){
          sum +=chalk[i];
            csum[i]= sum;
        } 
        
        if (sum <= k)
            k  %= sum;

        return upper_bound(begin(csum), end(csum), k)-csum.begin();
    }
};