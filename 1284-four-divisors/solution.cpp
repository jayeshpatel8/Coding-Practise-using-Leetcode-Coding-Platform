class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for (auto i : nums)
            ans += get_divisor(i);
        return ans;
    }
    int get_divisor(int a){
        int  d=0;
          for (int i=2; i*i<=a; i++){
            if (a%i == 0){
                if (d==0) d=i;
                else{
                    d=0;
                    break;
                }
            } 
        }

        return (d!=0 && d !=a/d) ? (1+a+d+a/d) :0;
    }
};
