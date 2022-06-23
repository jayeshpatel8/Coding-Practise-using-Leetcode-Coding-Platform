class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(begin(courses),end(courses),[](auto &a, auto &b){return a[1] < b[1];});
        priority_queue<int> pq;
        int total= 0;
        for (auto & c : courses){
            //if (c[0] > c[1])  continue;
            total += c[0]; pq.push(c[0]);
            if (total > c[1]){
                total -= pq.top(); pq.pop();
            }
        }
        return pq.size();
    }
};