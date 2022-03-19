class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq(begin(nums), end(nums));
        long sum = accumulate(begin(nums), end(nums),0L); int cnt=0;
        
        double sum2 = sum/ 2.0 ,s3=0;
        while (sum2 > s3){
            auto i = pq.top()/2; pq.pop();
            s3 += i;
            pq.push(i);
            cnt++;
        }
        return cnt;
    }
};