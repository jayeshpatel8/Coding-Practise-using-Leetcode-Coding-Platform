int msb=0;
class Trie{    
    Trie * T[2];
    int minV;
public:
    Trie(){
        T[0]=T[1]=NULL;
        minV=INT_MAX;
    }
    void insert( int num){
        bitset<32> b(num);
        Trie * t = this;
        for (int i=msb; i>=0; i--){
            if (t->minV > num) t->minV=num;
            
            if (t->T[b[i]] == NULL) t->T[b[i]] = new Trie();    
            t=t->T[b[i]];            
        }
        t->minV=num;
    }
    int search (int xi, int mi){
        bitset<32> b=xi;       
        int val=0;
        Trie* t = this;

        for (int bnum=msb; bnum>=0; bnum-- ){
            if (t->minV > mi ) { return -1;}
            int togBit = !b[bnum];
            if (!(t->T[togBit] && t->T[togBit]->minV <= mi))
                togBit = !togBit;
            t=t->T[togBit];
            if (togBit)
                 val |=1<<bnum;
        }
 
        return xi ^ val;
    }
};
    
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie root;
        int ored=0;
        for (auto i: nums) ored|=i;
        int b=31;
        for (; b>1; b--){
            if (ored | 1 << b) break;
        }
        msb=b;
        for (auto i: nums){        
            root.insert(i);
        }
        vector<int> res;
        for (auto q : queries){
            res.push_back(root.search(q[0],q[1]));
        }
        return res;
    }
};