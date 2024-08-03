class LRUCache {
public:
    int cap;
    list<int> keys; // yeh list keys ki order maintain karegi
    unordered_map<int, pair<int, list<int>::iterator>> cache; // yeh map key-value pair store karega
    
    int get(int key) {
        if(cache.find(key) == cache.end()) // agar key map mein nahi hai toh -1 return karo
            return -1;
        
        // key ko list ke front mein move karo kyunki yeh abhi use hua hai
        keys.erase(cache[key].second);
        keys.push_front(key);
        cache[key].second = keys.begin();
        
        return cache[key].first; // value return karo
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) { // agar key pehle se map mein hai
            // key ko list ke front mein move karo kyunki yeh abhi use hua hai
            keys.erase(cache[key].second);
            keys.push_front(key);
            cache[key] = {value, keys.begin()};
        } else { // agar key pehle se map mein nahi hai
            if(keys.size() == cap) { // agar cache full ho gaya hai
                // least recently used key ko remove karo
                cache.erase(keys.back());
                keys.pop_back();
            }
            // new key-value pair ko add karo
            keys.push_front(key);
            cache[key] = {value, keys.begin()};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
