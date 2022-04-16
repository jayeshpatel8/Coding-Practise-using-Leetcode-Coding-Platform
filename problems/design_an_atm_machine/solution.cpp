class ATM {
public:
    vector<long long> cnt;
    ATM() : cnt(5){
        //20, 50, 100, 200, and 500
    }
    
    void deposit(vector<int> banknotesCount) {
        
        for (int i=0; i<5;i++)
            cnt[i] +=banknotesCount[i];
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ans(5,0);

        int arr[5] = {20,50,100,200,500};
        for (int i=4; i>=0; i--){
            if (amount >= arr[i]){
                if (cnt[i] > 0) {
                    int c = min<long long>(amount/arr[i], cnt[i]);
                     ans[i]=c;
                    amount -= c * arr[i];
                }
            }
        }

        if (amount !=0 )
            return {-1};
        for (int i=0; i<5;i++)
            cnt[i] -=ans[i];
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */