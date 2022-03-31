class Solution {
public:
    struct Segment{
        //int l , r;
        int prefix, suffix, maxLen; 
    };
    string s;
    Segment tree[4 * 100000 + 5]; 
    void build(int i, int l, int r){
        if (l==r){
            //tree[i].r = tree[i].l = l;
            tree[i].prefix = tree[i].suffix = tree[i].maxLen = 1;
        }
        else{
            int m = (l + r)/2;
            build(i*2,l,m);
            build(i*2+1,m+1,r);
            push_up(i,l,r);
        }
    }
    void push_up(int i, int l, int r){
        auto &left  = tree[2*i] ;
        auto &right  = tree[2*i+1] ;
        tree[i].maxLen = max(left.maxLen, right.maxLen);
        tree[i].prefix = left.prefix;
        tree[i].suffix = right.suffix;
        int m = (l+r)/2;
        if (s[m] == s[m+1]){
            tree[i].maxLen = max(tree[i].maxLen, left.suffix + right.prefix);
            if (m-l+1 == left.maxLen)
                tree[i].prefix += right.prefix;
            if (r-m == right.maxLen)
                tree[i].suffix += left.suffix;
        }
    }
    void query(int i, int l, int r, int idx, char ch){
        if (l==r){
            s[l] = ch;
        }
        else{
            int m = (l + r)/2;
            if (idx <= m )
                query(i*2,l,m,idx,ch);
            else
                query(i*2+1,m+1,r,idx,ch);
            push_up(i,l,r);
        }
    }
    vector<int> longestRepeating(string _s, string qc, vector<int>& qi) {
        s = _s;        
        int qsz = qi.size(),sz=s.size();
        build(1,0,sz-1);
        vector<int> ans(qsz);
        for ( int q = 0; q<qsz; q++){
            int i = qi[q], ch=qc[q];
            if (ch != s[i]){
                query(1,0,sz-1,i,ch);
            }
            ans[q] = tree[1].maxLen;;
        }
        return ans;
    }
};
/* class Solution {
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
};*/