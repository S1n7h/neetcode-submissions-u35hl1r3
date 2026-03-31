class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ret = 1;
        for (string& word : wordList){
            if (endWord == word)    break;
            if (word == wordList[wordList.size() - 1])  return 0;
        }
        wordList.push_back(beginWord);
        unordered_map<string, bool> visited;
        for (string& word : wordList){
            visited[word] = false;
        }
        queue<string> q;
        q.push(beginWord);
        visited[beginWord] = true;
        while(!q.empty()){
            int Size = q.size();
            ret++;
            cout << ret << "\n";
            for (int i = 0 ; i < Size ; i++){
                string temp = q.front();
                q.pop();

                //for the combinations
                for (int i = 0 ; i < temp.size() ; i++){
                    for (char add = 'a' ; add <= 'z' ; (int)add++){
                        string word = temp.substr(0, i);
                        word += add;
                        word += temp.substr(i + 1, temp.size() - i);
                        if (/*count(wordList.begin(), wordList.end() , word)*/visited.find(word) != visited.end() && word != temp){
                            if (visited[word] == false){
                                q.push(word);
                                cout << word << "\n";
                                visited[word] = true;
                            }
                        }beginWord = word;
                        if (word == endWord) return ret;
                    }
                }
            }cout << "\n";
        }if (beginWord != endWord) return 0;
        return ret;
    }
};
