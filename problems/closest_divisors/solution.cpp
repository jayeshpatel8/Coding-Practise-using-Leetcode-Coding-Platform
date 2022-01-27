class Solution {
public:
    int diff=INT_MAX, a1=0,a2=0;
    vector<int> closestDivisors(int num) {
        int n1= num+1, n2 = num+2;
        find(n1);find(n2);
        return {a1,a2};
    }
    void find(int i){
        for ( int j = 1 ; diff && j*j<= i; j++){
            if (i%j ) continue;
            int d =  abs(j - i/j );
            if (d < diff){
                 diff=d; a1= j, a2 = i/j;
            }
        }
        
    }
};