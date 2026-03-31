class WordDictionary {
public:
    unordered_map<string, int> h;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        h[word]++;
    }
    
    bool search(string word) {
        for (auto i : h){
            int check = 0;
            if (i.first.size() > word.size() || i.first.size() < word.size()) continue;
            for (int j = 0 ; j < word.size() ; j++){
                if (word[j] == '.') continue;
                if (word[j] != i.first[j]){
                    check = 1;
                    break;
                }
            }if (check == 0)    return true;
        }return false;
    }
};
