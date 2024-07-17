class RandomizedCollection {
public:
    
    vector<pair<int, int>> a; // Pair ka vector to store values aur unki positions
    unordered_map<int, vector<int>> mp; // Map to store values aur unke indices
    
    RandomizedCollection() {
        // Constructor, kuch initialize karne ki zaroorat nahi
    }
    
    // Value ko insert karte hain
    bool insert(int val) {
        auto it = mp.find(val);
        if (it == mp.end()) {
            // Agar value nahi hai, toh naye value ka index map mein add karte hain
            mp[val].push_back(a.size());
            a.push_back(make_pair(val, mp[val].size() - 1));
            return true; // Naya value add hua
        } else {
            // Agar value pehle se hai, toh uske index ko update karte hain
            mp[val].push_back(a.size());
            a.push_back(make_pair(val, mp[val].size() - 1));
            return false; // Duplicate value add hui
        }
    }
    
    // Value ko remove karte hain
    bool remove(int val) {
        auto it = mp.find(val);
        if (it != mp.end()) {
            auto last = a.back();
            // Last element ko remove hone wale element ki jagah place karte hain
            mp[last.first][last.second] = mp[val].back();
            a[mp[val].back()] = last;
            mp[val].pop_back();
            if (mp[val].empty())
                mp.erase(val);
            a.pop_back();
            return true; // Value successfully remove hui
        }
        return false; // Value nahi mili
    }
    
    // Random value ko return karte hain
    int getRandom() {
        return a[rand() % a.size()].first; // Random index se value return karte hain
    }
};
