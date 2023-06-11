class SnapshotArray {
public:
vector<map<int,int>> m;
int id=0;
    SnapshotArray(int length) {
        m.resize(length);
    }
    
    void set(int index, int val) {
        m[index][id]=val;
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        auto it =  m[index].upper_bound(snap_id);
        return it == begin(m[index]) ? 0 : prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */