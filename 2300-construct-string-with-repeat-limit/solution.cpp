class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<array<int,2>> pq;
        int freq[26]={};
        for (auto &c : s) freq[c-'a']++;
        for ( int i=0;i<26; i++){
             if (freq[i]){
                 pq.push({i + 'a', freq[i]});
             }
        }
        string ans;
        while (!pq.empty()){
            auto i = pq.top(); pq.pop();
            if (i[1]>repeatLimit){
                ans += string(repeatLimit, i[0]); 
                if (pq.empty()){                    
                    break;
                }
                else{
                    auto  j = pq.top(); pq.pop();
                    ans += string(1, j[0]); 
                    j[1]--;
                    i[1]-=repeatLimit;
                    if (j[1]>0)
                        pq.push(j);
                    pq.push(i);
                    
                }
            }
            else{
                ans += string(i[1], i[0]);
            }
        }
        return ans;
    }
};
