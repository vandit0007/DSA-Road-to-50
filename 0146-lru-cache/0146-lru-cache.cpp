
class LRUCache {
private:
    int cap;
    list<pair<int, int>> cache; 
    // {key, value}; front = most recently used

    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        auto it = mp[key];
        int value = it->second;

        // Move accessed element to the front
        cache.splice(cache.begin(), cache, it);

        return value;
    }

    void put(int key, int value) {
        // If key exists, update it
        if (mp.find(key) != mp.end()) {
            auto it = mp[key];
            it->second = value;
            cache.splice(cache.begin(), cache, it);
            return;
        }

        // Remove least recently used element
        if (cache.size() == cap) {
            int lruKey = cache.back().first;
            cache.pop_back();
            mp.erase(lruKey);
        }

        // Insert new element at the front
        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};
