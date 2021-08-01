class Solution {
public:
    bool isThree(int n) {
        int cnt = 2;
        for ( int i=2; cnt <5 && i<=n/2; ++i){
            cnt += (n%i==0);
        }
        return cnt==3;
    }
};