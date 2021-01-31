class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        const int max_cnt = 9+9+9+9+9+1;
        int cnt[max_cnt]={};
        for (int i=lowLimit; i<=highLimit; i++){
            int sum = 0,n=i;
            while(n){
                sum +=n%10; n/=10;
            }
            ++cnt[sum];
        }
        return *max_element(begin(cnt), end(cnt));
    }
};