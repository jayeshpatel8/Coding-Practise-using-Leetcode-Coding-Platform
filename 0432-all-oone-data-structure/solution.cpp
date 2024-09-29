class AllOne {
public:

    void inc(string key) {
        
        // If the key doesn't exist, insert it with value 0.
        if (!map.count(key))
            map[key] = buckets_list.insert(buckets_list.begin(), {0, {key}});
            
        // Insert the key in next bucket and update the lookup.
        auto next = map[key], bucket = next++;
        if (next == buckets_list.end() || next->value > bucket->value + 1)
            next = buckets_list.insert(next, {bucket->value + 1, {}});
        next->keys.insert(key);
        map[key] = next;
        
        // Remove the key from its old bucket.
        bucket->keys.erase(key);
        if (bucket->keys.empty())
            buckets_list.erase(bucket);
    }

    void dec(string key) {

        // If the key doesn't exist, just leave.
        if (!map.count(key))
            return;

        // Maybe insert the key in previous bucket and update the lookup.
        auto prev = map[key], bucket = prev--;
        map.erase(key);
        if (bucket->value > 1) {
            if (bucket == buckets_list.begin() || prev->value < bucket->value - 1)
                prev = buckets_list.insert(bucket, {bucket->value - 1, {}});
            prev->keys.insert(key);
            map[key] = prev;
        }
        
        // Remove the key from its old bucket.
        bucket->keys.erase(key);
        if (bucket->keys.empty())
            buckets_list.erase(bucket);
    }

    string getMaxKey() {
        return buckets_list.empty() ? "" : *(buckets_list.rbegin()->keys.begin());
    }
    
    string getMinKey() {
        return buckets_list.empty() ? "" : *(buckets_list.begin()->keys.begin());
    }

private:
    struct Bucket { int value; unordered_set<string> keys; };
    list<Bucket> buckets_list;
    unordered_map<string, list<Bucket>::iterator> map;
};
