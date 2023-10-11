#import <map>
#import <algorithm>

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        std::map<int, int> flower_count;
        
        for(auto &it:flowers) {
            flower_count[it[0]]++;
            flower_count[it[1] + 1]--;
        }

        int sum = 0;
        for(auto &it:flower_count) {
            sum += it.second;
            it.second = sum;
        }

        int len = people.size();
        std::vector<int> res(len, 0);

        for(int i = 0; i < len; i++) {
            auto it = flower_count.upper_bound(people[i]);
            if (it != flower_count.begin()) {
                it--;
                res[i] = it->second;
            }
        }
        return res;
    }
};