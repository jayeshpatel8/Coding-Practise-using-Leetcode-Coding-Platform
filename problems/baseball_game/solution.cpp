class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> rec;
        int sz=0;
        for (auto &s : ops){
            int c = s[0];
            if (c =='C' ){
                rec.pop_back();sz--;
            }
            else if (c =='D'){
                rec.push_back(rec.back() *2);sz++;
            }
            else if (c=='+'){
                rec.push_back(rec.back() + rec[sz-2]);
                sz++;
            }
            else{
                //num
                rec.push_back(stoi(s));
                sz++;
            }
        }
        return accumulate(begin(rec),end(rec),0);
    }
};