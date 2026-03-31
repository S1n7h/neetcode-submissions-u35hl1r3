class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, pair<int, int>>> heap;
        vector<vector<int>> ret;
        for (int i = 0 ; i < points.size() ; i++){
            heap.push({(double)sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]), {points[i][0], points[i][1]}});

            if (heap.size() > k){
                heap.pop();
            }
        }while(!heap.empty()){
            ret.push_back({heap.top().second.first, heap.top().second.second});
            heap.pop();
        }return ret;
    }
};
