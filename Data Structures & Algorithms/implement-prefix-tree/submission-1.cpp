class PrefixTree {
public:
    unordered_map<string,int> hash;
    PrefixTree() {
        
    }
    
    void insert(string word) {
        hash[word]++;
    }
    
    bool search(string word) {
        if (hash.find(word) == hash.end())  return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        for (auto& i : hash){
            if (i.first.size() >= prefix.size() && i.first.substr(0,prefix.size()) == prefix) return true;
        }return false;
    }
};
