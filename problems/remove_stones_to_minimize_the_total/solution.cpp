class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        map<int,int,greater<>> map;
        int sum = 0;
        for (auto i : piles)
            map[i]++;
        while (k){
            auto it = begin(map);
            auto &[top, val] = *it;
            if (top == 1) break;
            auto cnt = min(k,val);
            map[top/2 + (top &1)] += cnt;
            k -=cnt;
            if (val > cnt) sum += (top * (val - cnt));       
            map.erase(it);
        }
        for (auto &[k,v] : map) sum+= (k*v);
        return sum;
    }
};