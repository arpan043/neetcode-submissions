class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() > n-1){
            return false;
        }
        vector<vector<int> > adj(n);

        for( auto& node : edges){
            adj[node[0]].push_back(node[1]);
            adj[node[1]].push_back(node[0]);
        }

        queue<pair<int, int>> q;
        unordered_set<int> visit;

        q.push({0,-1});
        visit.insert(0);
        while(!q.empty()){
            auto[node, parent] = q.front();
            q.pop();

            for( auto nei : adj[node]){
                if(nei == parent){
                    continue;
                }

                if(visit.count(nei)){
                    return false;
                }
                visit.insert(nei);
                q.push({nei, node});
            }
        }

        return visit.size() == n;
    }
};
