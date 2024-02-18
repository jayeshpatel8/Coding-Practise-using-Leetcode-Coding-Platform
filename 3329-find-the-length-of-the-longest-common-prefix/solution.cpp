class Solution {
public:
    struct Trie {
        Trie * dig[10]={};
    };
    struct Trie head;
    void add(int n){
        string s = to_string(n);
        Trie *t = &head;
        for (auto c : s){
            if (!t->dig[c-'0']){
                t->dig[c-'0'] = new Trie;                
            }
            t = t->dig[c-'0'];
        }   
    }
    int check(int n){
        string s = to_string(n);
        Trie *t = &head;
        int l=0;
        for (auto c : s){
            if (!t->dig[c-'0']){
                break;
            }
            else l++;
            t = t->dig[c-'0'];
        }   
        return l;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        for (auto n : arr1) add(n);
        int ans  = 0;
        for (auto n : arr2) ans= max(ans, check(n));
        return ans;
    }
};
