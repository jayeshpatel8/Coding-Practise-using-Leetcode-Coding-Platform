class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        priority_queue<array<int,2>,vector<array<int,2>>, greater<>> q;
        for (int i=0; i < ranges.size(); i++){
            q.push({i - ranges[i], i + ranges[i]});
        }
        int start=0, cnt=0, end=-1;
        while(!q.empty() && end <n){
            bool f=false;
            while (!q.empty() && q.top()[0]<=start){
                end= max(end, q.top()[1]);
                q.pop();
                f=true;
            }          
            start = end;
            if (f)
                cnt++;
            else
                return -1;
        }
        return end>=n ? cnt : -1;
    }
};