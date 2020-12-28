int Msb=31;
int mXor;
class Trie{
        Trie* T[2];
    public:
        Trie(){T[0]=T[1]=0;}
        void insert(int num){
            Trie *t = this;
            for (int b=Msb; b>=0; b--){
                int bit = (num>>b) & 1;
                if (t->T[bit]== NULL) t->T[bit] = new Trie();
                t = t->T[bit];
            }
        }
    int search(int num){
        Trie * t = this;int val=0;
        
        for (int b=Msb; b>=0; b--){            
            int bit = num >> b & 1;
            
            if (t->T[!bit]) bit = !bit;
            else if(mXor > (val ^ num)) return 0;
            t = t->T[bit];
            if (bit) val |=1<<b;                   
        }
        return val ^ num;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        //[3,10,5,25,2,8]
        //[2,3,5,8,10,25]
        //if (nums.size()<2) return 0;
        Trie root;
        mXor=0;
        int ored=0;
        for (auto i : nums) ored|=i;
        int b=31;
        for (;b>1; b--) if (ored & 1<<b) break;
        Msb=b;
        for (auto i : nums) root.insert(i);
        for (auto i : nums){
            mXor = max(mXor,root.search(i));            
        }
        return mXor;
    }
};