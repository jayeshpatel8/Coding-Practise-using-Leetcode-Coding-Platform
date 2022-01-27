    int Msb=31;
int mXor;
class Solution {
public:
    
    class Trie{
        public:
        Trie *  bits[2]={NULL,NULL};
    } ;
    void insert(Trie * root, int n){
        Trie *r = root;
        for (int i=31; i>=0; i--){
            int b = (n >> i) & 1;
            if (r->bits[b] == NULL){
                r->bits[b] = new Trie;                
            }
            r = r->bits[b];
        }
    }
    int search(Trie *root, int n){
        Trie *r = root;
        int ans=0;
      
        for (int i=31; i>=0; i--){
            int b = (n >> i) & 1;
            if (r->bits[!b])
                b= !b,ans  |= 1<<i;;
            
            r = r->bits[b];
        }        
        return ans;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        Trie root;
        int ans = 0;
        for ( int i=1; i<nums.size(); i++){
            insert(&root, nums[i-1]);
            ans = max(ans, search(&root,nums[i]));            
        }
        return ans;
    }

};