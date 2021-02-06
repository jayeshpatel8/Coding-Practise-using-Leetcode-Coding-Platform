class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int N[101]={};
        
        for (auto i : nums) N[i]+=1;
        int sum=0;
        for(int i=1;i<=100;i++) if (N[i]==1) sum +=i;
        return sum;
    }
};