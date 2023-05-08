class FrequencyTracker {
public:
    int n[100001]={},f[100001]={};
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        auto &i = n[number];
        f[i]--;
        f[++i]++;
    }
    
    void deleteOne(int number) {
        auto &i = n[number];
        if (i>0){
            f[i]--;
            f[--i]++;
        }
    }
    
    bool hasFrequency(int frequency) {        
        return  f[frequency] != 0;;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */