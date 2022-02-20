class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& ints) {
        sort(begin(ints) ,end(ints));
        int start=-1, end=-1, cnt = 0;
        for (auto &i :ints){
            if (start == i[0])
                end= i[1];
            else if (end < i[1])
                end = i[1], start=i[0], cnt++;
        }
        return cnt;
    }
};