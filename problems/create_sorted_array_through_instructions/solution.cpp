typedef struct BT{
    BT * left,*right;
    int v;
    BT(int val):v(val),left(0),right(0){}
}BT;
class Solution {
public:
        const int BITree_size = 100002;
        vector<uint32_t> BITree;
    
    int createSortedArray(vector<int>& inst) {
        
        uint32_t cost=0, Mod=1e9+7;
        BITree.resize(BITree_size);
        //[1,5,6,2]
        for (int i=0; i< inst.size(); i++){
            
            uint32_t left=QueryToBITree(inst[i]-1),right=i-QueryToBITree(inst[i]);
            
            
            cost +=min(left,right);
            cost%=Mod;
            
            addToBITree(inst[i]);
        }
        return cost;
    }
    void addToBITree(int idx){
        
        for (; idx < BITree_size; idx+= idx & -idx){
            BITree[idx]++;
        }
    }
    uint32_t QueryToBITree(int idx){
        uint32_t cost =0;
        for (; idx > 0; idx-= idx & -idx){
            cost +=BITree[idx];
        }
        return cost;
    }  

};