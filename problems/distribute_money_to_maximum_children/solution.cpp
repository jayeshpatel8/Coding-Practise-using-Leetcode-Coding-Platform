class Solution {
public:
    int distMoney(int money, int ch) {
        money -= ch;
        if (money < 0) return -1;
        
        if (money %7 == 0 && money/7 ==  ch) return ch;
        if (money %7 == 3 && money/7 == ch-1) return ch-2;
        return min(ch-1, money/7 );
    }
    int distMoney2(int money, int children) {
        int cnt= 0, ch=children;
        if (money < children ) return -1;
        if (money < 8) return 0;
        vector<int> ans;
      while (money >= 1 && ch > 0 && money >0){
          if (money >=8) {
              ans.push_back(8);
              money -=8;
          }
          else ans.push_back(1),money--;
          ch--;
      }

        if(money ==0 & ch ==0)
            return count(begin(ans),end(ans),8);
        else if(money ==0 & ch !=0){
            for (int i=0; i<ans.size() && ch > 0; i++){
                if (ans[i] > 1){
                    ch -= ans[i]-1;
                    ans[i] =1;
                }
            }
            if (ch>0) return -1;
            return count(begin(ans),end(ans),8);
        }
        else{
            for (int i=ans.size()-1; money > 0 && i>=0; i--){
                ans[i] += money;
                money = 0;
                if (ans[i]==4){
                    ans[i]--;
                    money=1;
                }
            }
            if (money>0) return -1;
            return count(begin(ans),end(ans),8);
        }
      return -1;
    }
};