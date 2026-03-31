class KthLargest {
public:
    int temp;
    vector<int> ooh;
    KthLargest(int k, vector<int>& nums) {
        temp = k;
        ooh = nums;
        sort(ooh.begin(), ooh.end(), greater<int> ());
    }
    
    int add(int val) {
        if (ooh.empty()){
            ooh.push_back(val);
            return val;
        }
        for (int i = 0 ; i < ooh.size() ; i++){
            if (ooh[i] <= val){
                ooh.insert(ooh.begin() + i, val);
                break;
            }if (i == ooh.size() - 1)  ooh.push_back(val);
        }return ooh[temp - 1];
    }
};
