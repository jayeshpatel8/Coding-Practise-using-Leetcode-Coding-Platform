class Solution {
public:
struct Trie{
    Trie * bits[2]={0};
    int cnt=0;    
};

    void insert(Trie *root , int n){
        
        for (int i=14; i>=0; i--){
            bool bit=  (1<<i) & n;
            if (!root->bits[bit])
                root->bits[bit]=new Trie();
            root->bits[bit]->cnt++;
            root = root->bits[bit];
            
        }
    }
    /*
      k = 1 1 0 0 
      n = 1 0 1 0
      X = 1 0 1 0
          
    */
    int getLess(Trie *root, int n, int k){
        
        int ans = 0;
        for (int i=14; i>=0 && root; i--){
            bool bitn=  ((1<<i) & n);
            bool bitk=  ((1<<i) & k);
            if (bitk==0){
                root = root->bits[bitn];    
                continue;
            }
            if (root->bits[bitn])
                ans += root->bits[bitn]->cnt;     
            
            root = root->bits[1-bitn];    
        }
        return ans;
    }
    int countPairs(vector<int>& nums, int low, int high) {
        Trie r;
        int ans = 0;
        for (auto i : nums){
            ans += getLess(&r,i,high+1) - getLess(&r,i,low);
            insert(&r,i);
        }
        return ans;
    }
};