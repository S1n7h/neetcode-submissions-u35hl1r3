#include <bits/stdc++.h>
using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> object;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        object[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        // Key not found
        if (object.find(key) == object.end()) return "";

        auto &temp = object[key]; // reference to avoid copying
        int l = 0, r = temp.size() - 1;
        string result = "";

        while (l <= r) {
            int mid = (l + r) / 2;
            if (temp[mid].first <= timestamp) {
                result = temp[mid].second; // store best so far
                l = mid + 1;               // search for later timestamp
            } else {
                r = mid - 1;               // search earlier timestamps
            }
        }
        return result;
    }
};

