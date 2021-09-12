class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double,int> freq;
        
        for(auto &i : rectangles)
            freq[(double)i[0]/i[1]]++;
        long long ans = 0;
        for ( auto i : freq){
            long long n = i.second - 1;
            ans += (n * (n+1) / 2);
        }
        return ans;
    }
};