class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj_list(n);
        vector<bool> visited(n, false);
        for( auto edge : edges)
        {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        for(int node = 0;node < n ; ++node){
            if(!visited[node]){
                dfs(adj_list, visited, node);
                res++;
            }
        }
        return res;
    }

    private:
    void dfs(const vector<vector<int>> & adj_list, vector<bool>& visited,
        int node)
        {
            visited[node] = true;
            for(int neighbour : adj_list[node]){
                if(!visited[neighbour]){
                    dfs(adj_list, visited, neighbour);
                }
            }
        }
};
