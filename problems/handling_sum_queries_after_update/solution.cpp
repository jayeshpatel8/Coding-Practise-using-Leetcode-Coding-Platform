#define lson (ind<<1)
#define rson (ind<<1|1)
struct SegTree {
    static const int maxn = 100010;
    
    struct node {
        int l, r;
        int s, tag;
        
        int get_sum() {
            if(tag)return (r - l + 1) - s;
            return s;
        }
    };
    
    node no[maxn * 4];
    
    void push_up(int ind) {
        no[ind].s = no[lson].get_sum() + no[rson].get_sum();
    }
    
    void push_down(int ind) {
        if(no[ind].tag) {
            no[lson].tag ^= 1;
            no[rson].tag ^= 1;
        }
        no[ind].tag = 0;
    }
    
    void build(int l, int r, int ind, vector<int> &arr) {
        no[ind].l = l;
        no[ind].r = r;
        no[ind].tag = no[ind].s = 0;
        
        if(l == r) {
            no[ind].s = arr[l];
        } else {
            int mid = (l + r) / 2;
            build(l, mid, lson, arr);
            build(mid + 1, r, rson, arr);
            push_up(ind);
        }
    }
    
    void update(int l, int r, int ind, int val) {
        if(l > no[ind].r || r < no[ind].l)return;
        if(l <= no[ind].l && no[ind].r <= r) {
            no[ind].tag ^= 1;
        } else {
            push_down(ind);
            update(l, r, lson, val);
            update(l, r, rson, val);
            push_up(ind);
        }
    }
    
    void query(int l, int r, int ind, int &ans) {
        if(l > no[ind].r || r < no[ind].l)return;
        if(l <= no[ind].l && no[ind].r <= r) {
            ans += no[ind].get_sum();
        } else {
            push_down(ind);
            query(l, r, lson, ans);
            query(l, r, rson, ans);
            push_up(ind);
        }
    }
};

SegTree tr;

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        using ll = long long;
        tr.build(0, nums1.size() - 1, 1, nums1);
        ll sum  = 0 ;
        vector<long long> ans;
        for(auto i: nums2)sum += i;
        for(auto q: queries) {
            int t, l, r;
            t = q[0], l = q[1], r = q[2];
            if(t == 1) {
                tr.update(l, r, 1, 1);
            } else if(t == 2) {
                int s = 0;
                tr.query(0, nums1.size() - 1, 1, s);
                sum += (ll) s * l;
            } else {
                ans.push_back(sum);
            }
        }
        return ans;
    }
};