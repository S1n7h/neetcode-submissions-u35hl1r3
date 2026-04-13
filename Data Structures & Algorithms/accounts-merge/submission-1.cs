public class Solution {
    public List<List<string>> AccountsMerge(List<List<string>> accounts) {
        Union un = new Union(accounts.Count);
        Dictionary<string, int> emailToAcc = new Dictionary<string, int>();

        //make the disjoint set
        for(int i = 0 ; i < accounts.Count ; i++){
            for(int j = 1 ; j < accounts[i].Count ; j++){
                string email = accounts[i][j];
                if (emailToAcc.ContainsKey(email)){
                    un.unionByRank(i, emailToAcc[email]);
                }else emailToAcc[email] = i;
            }
        }
        Dictionary<int, List<string>> emailGroup = new Dictionary<int, List<string>>(); 

        //merge duplicates
        foreach(var pair in emailToAcc){
            var email = pair.Key;
            var parent = pair.Value;
            var ultimateParent = un.Find(parent);
            if (!emailGroup.ContainsKey(ultimateParent)) emailGroup[ultimateParent] = new List<string>();
            emailGroup[ultimateParent].Add(email);
        }
        List<List<string>> ret = new List<List<string>>(); 
        //make sorted emailGroup
        foreach(var pair in emailGroup){
            var account = accounts[pair.Key][0];
            var list = pair.Value;            
            List<string> temp = new List<string>();
            list.Sort(); 
            temp.Add(account);
            temp.AddRange(list);
            ret.Add(temp);
        }return ret;
    }

    public class Union{
        int[] rank;
        int[] parent;
        public Union(int n){
            rank = new int[n];
            parent = new int[n];

            Array.Fill(rank, 1);
            for(int i = 0 ; i < n ; i++) parent[i] = i;
        }

        public int Find(int node){
            if (node != parent[node]){
                parent[node] = Find(parent[node]);
            }return parent[node];
        }

        public bool unionByRank(int x, int y){
            int parentX = Find(x);
            int parentY = Find(y);

            if (parentX == parentY) return false;

            else if(rank[parentX] < rank[parentY]){
                parent[parentX] = parentY;
                rank[parentY] += rank[parentX];
            }
            else{
                parent[parentY] = parentX;
                rank[parentX] += rank[parentY];
            }

            return true;
        }
    }
}