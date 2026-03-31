class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (int i = 0 ; i < tasks.size() ; i++){
            count[tasks[i] - 'A']++;
        }
        sort(count.begin(), count.end());
        
        int j = count.size() - 1;
        int maxFreq = count[j];
        int maxCount = 0;
        while (j >= 0 && count[j] == maxFreq){
            maxCount++;j--;
        }
        return max((int)tasks.size(), (n + 1)*(maxFreq - 1) + maxCount);
    }
};
