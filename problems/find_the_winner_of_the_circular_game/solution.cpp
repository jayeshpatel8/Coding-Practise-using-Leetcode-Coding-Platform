class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> ones(n,true);
        int cnt=n,i=0;
        while(cnt > 1){

            for (int j=0; j<k; j++,i++){
                while (!ones[i%n])  i++;
                
            }
            ones[(i-1) % n ]=false;
            cnt--;
        }
         i=0;
        for (; !ones[i];i++);
        return i+1;
    }
};