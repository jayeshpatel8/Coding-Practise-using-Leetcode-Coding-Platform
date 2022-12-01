class Solution {
public:
    int subtractProductAndSum(int n) {
        vector<int> dig;
        while (n>0){
            dig.push_back(n%10);
            n/=10;
        }
        int pro=1,sum=0;
        for (auto d : dig) pro *=d, sum+=d;
        return pro - sum;
    }
};