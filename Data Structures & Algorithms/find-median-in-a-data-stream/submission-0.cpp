class MedianFinder {
public:
    vector<int> arr;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (arr.empty())    arr.push_back(num);
        else{
            int j = 0;
            while (j < arr.size() && arr[j] < num)  j++;
            arr.insert(arr.begin() + j, num);
        }
    }
    
    double findMedian() {
        if (arr.size() % 2 == 0)    return (float)(arr[arr.size()/2 - 1] + arr[arr.size()/2])/2;
        else return arr[arr.size()/2];
    }
};
