class Solution {
public:
    string frequencySort(string s) {
        int freq[128] = {};
        for (auto c : s) freq[c]++;
        sort(begin(s),end(s), [&](auto a, auto b){ return freq[a] != freq[b] ? freq[a] > freq[b] : a > b;});
        return s;
    }

    string frequencySort2(string s) {
        int freq[128] = {};
        for (auto c : s) freq[c]++;
        string res;
        priority_queue<pair<int,char>>pq;
        for (int i=0; i<128; i++)
            if (freq[i])
                pq.push({freq[i],i});
        while(!pq.empty()){
            auto [f , c] = pq.top(); pq.pop(); 
            res += string(f,c);
        }
        return res;
    }
};