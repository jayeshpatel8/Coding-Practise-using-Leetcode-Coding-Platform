class Solution {
public:
    int splitNum(int num) {
        vector<int> dig;
        while (num > 0){
            dig.push_back(num%10);
            num/=10;
        }
        sort(begin(dig),end(dig));
        int a=0,b=0;
        for (int i=0; i<dig.size(); i++){
            if (i &1){
                b = b * 10 + dig[i];
            }
            else
                a = a * 10 + dig[i];
        }
        return a + b;
    }
};