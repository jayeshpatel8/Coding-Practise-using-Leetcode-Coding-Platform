class Solution {
public:
    map<int,int> interval;
    multiset<int> len;
    vector<int> longestRepeating(string s, string qc, vector<int>& qi) {
        int qsz = qi.size(),sz=s.size();
        vector<int> ans(qsz);
        auto it = end(interval);
        for ( int i=0; i<sz; i++){
            if (i==0 || s[i] !=s[i-1])
                it = interval.insert({i,1}).first;
            else
                ++it->second;   
        }
        for (auto &i : interval) len.insert(i.second);
        auto insert = [&](int i, int sz){            
            len.insert(sz);
            return interval.insert({i,sz}).first;
        };
        auto erase = [&](auto p){            
            len.erase(len.find(p->second));
            interval.erase(p);
        };
        auto replace = [&](auto p, int sz){
            len.erase(len.find(p->second));
            len.insert(sz);
            p->second = sz;
        };
        for ( int q = 0; q<qsz; q++){
            int i = qi[q], ch=qc[q];
            if (ch != s[i]){
                s[i]=ch;
                auto it = interval.lower_bound(i);
                //left break
                if (i>0 && (it == end(interval) || it->first > i)){
                    int newsize = i -  prev(it)->first;
                    it = insert (i, prev(it)->second - newsize);
                    replace(prev(it), newsize);
                }
                // now it points to current i
                
                // right break
                if (it->second > 1){
                    insert(i+1, it->second-1);
                    replace(it,1);
                }
                // right join
                if (i+1 < sz && s[i]==s[i+1]){
                    replace(it,next(it)->second+1);
                    erase(next(it));
                }
                
                // left join
                if (i>0 && s[i]==s[i-1]){
                    replace(prev(it),prev(it)->second + it->second);
                    erase(it);
                }
            }
            ans[q] = *rbegin(len);
        }
        return ans;
    }
};