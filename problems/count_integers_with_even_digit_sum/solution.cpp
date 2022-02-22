class Solution {
public:
    int countEven(int num) {
        int ans=0;
        for ( int i=2; i<=num; i++){
            ans+= even(i);
        }
        return ans;
    }
    bool even(int i){
        int sum = 0;
        while(i){
            sum  +=i%10;
            i/=10;
        }
        return (sum & 1) == 0;
    }
};