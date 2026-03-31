class Solution {
private:
    unordered_map<int, vector<int>> hash;
    void dfs(int& course, vector<int>& visitset, bool& ret){
        if (!ret)   return;
        if (find(visitset.begin(), visitset.end(), course) != visitset.end()){
            ret = false;return;
        }  
        if (hash.find(course) == hash.end())    return;   
                
        visitset.push_back(course);     
        
        for(auto& crs : hash[course]){
            dfs(crs, visitset, ret);
        }
        visitset.pop_back();
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto& pairs : prerequisites){
            hash[pairs[0]].push_back(pairs[1]);
        }for (auto& prereqs : hash){
                vector<int> visitset;
                visitset.push_back(prereqs.first); 
            for (auto& course : prereqs.second){
                bool ret = true;
                dfs(course, visitset, ret);
                if (ret == false)  return false;
            }
        }return true;
    }
};
