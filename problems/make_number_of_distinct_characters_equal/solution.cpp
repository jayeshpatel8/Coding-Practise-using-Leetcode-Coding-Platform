class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> f1(128),f2(128);
        for (auto c : word1) f1[c]++;
        for (auto c : word2) f2[c]++;
        int cnt1= count_if(begin(f1),end(f1),[](int a){return a > 0;});
        int cnt2= count_if(begin(f2),end(f2),[](int a){return a > 0;});
        if (cnt1== cnt2) {
            for (char i='a'; i<='z' ; i++) if (f1[i] && f2[i]) return true;    
        }
        
        if (cnt1<cnt2)
            swap(word1,word2), swap(f1,f2),swap(cnt1,cnt2);
        int diff = cnt1-cnt2;

        if (diff >2) return false;
        for (char i='a'; i<='z' ; i++){
            if (!f1[i]) continue;
            for (char j='a'; j<='z' ; j++){
                if (!f2[j]) continue;
                if (i!= j ){
                    int c1 = cnt1  -(f1[i]==1) + (f1[j]==0);
                    int c2 = cnt2  -(f2[j]==1) + (f2[i]==0);
                    if (c1== c2)
                        return true;                    
                }
            }
        }
        return false;
    }
};