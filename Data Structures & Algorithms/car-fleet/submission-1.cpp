class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for (int i = 0 ; i < position.size() ; i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());

        stack<double> temp_stack;

        for (int i = cars.size() - 1 ; i > -1 ; i--){
            if (temp_stack.empty() || temp_stack.top() < (double)(target - cars[i].first) / cars[i].second)
                temp_stack.push((double)(target - cars[i].first) / cars[i].second);
        }
        return temp_stack.size();
    }
};
