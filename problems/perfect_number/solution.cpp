class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum=num==1?0:1;
        
        for (int i=2;i*i<=num; i++){
            if (num % i == 0) {sum +=i; sum +=num/i;}
        }
        return sum == num ;
    }
};//  1+ 28 , 2 + 14, 4  +7,=56