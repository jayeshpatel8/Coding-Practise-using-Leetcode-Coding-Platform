
   
class RangeModule {
public:
 class segtree  {
    public:
    segtree * left=0, * right=0;
    int l=0, r=0;
    int status=true;;
    
    segtree(int l1, int r1, bool st): l(l1),r(r1),status(st){
    }
} ; 
     segtree  *root;
    bool update(segtree * node, int l, int r, bool status){
        if (!node) return false;
        if (l<= node->l   && node->r <= r){
            node->status = status; 
            if (node->left) {
                 node->left = node->right = 0;
            }
            return status;
        }
        if (l>=node->r || r <= node->l) return node->status;
        int mid = node->l + (node->r - node->l) / 2;
        if (!node->left){
            node->left = new segtree(node->l,mid,node->status);
            node->right = new segtree(mid,node->r,node->status);
        }
        
        auto l1 = update(node->left,l,r,status);
        auto r1 = update(node->right,l,r,status);
        return node->status = l1 && r1;
    }
   
    bool query(segtree * node, int l, int r){
        if (l>node->r || r < node->l) return true;
        if ((l<= node->l && node->r <= r)  || !node->left) return node->status;
        int mid = node->l + (node->r - node->l) / 2;
        if (l >= mid)
            return query(node->right,l,r);
        else if (r<=mid)
            return query(node->left,l,r);
        else
            return query(node->right,l,r) && query(node->left,l,r);
    }
    RangeModule() {
        root  = new segtree(0,(int) 1000000000,false);
        //root.status =false;
    }
    
    void addRange(int left, int right) {
        update(root,left,right,true);
    }
    
    bool queryRange(int left, int right) {
        return query(root,left,right);
    }
    
    void removeRange(int left, int right) {
        update(root,left,right,false);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */