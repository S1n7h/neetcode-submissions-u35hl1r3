class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for (int i = 0 ; i < stones.size() ; i++)   heap.push(stones[i]);

        while (heap.size() > 1){
            int first = heap.top();
            heap.pop();
            int second = heap.top();
            heap.pop();
            heap.push(first - second);
        }if (heap.size() == 0)  return 0;
        else return heap.top();
    }
};
