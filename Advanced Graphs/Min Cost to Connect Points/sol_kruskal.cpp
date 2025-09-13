class Solution {
public:
    class DSU{
    public:
        vector<int> parent, size;
        DSU(int n){
            parent.resize(n);
            size.resize(n,1);
            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
        }

        int find(int i){
            while(parent[i] != i){
                parent[i] = parent[parent[i]];
                i = parent[i];
            }
            return i;
        }

        void weightedUnion(int x, int y){
            int parentX = find(x);
            int parentY = find(y);
            if(size[parentX] > size[parentY]){
                parent[parentY] = parent[parentX];
                size[parentX] += size[parentY];
            }else{
                parent[parentX] = parent[parentY];
                size[parentY] += size[parentX];
            }
        }
    };
    
    static bool comparator(vector<int> &a, vector<int> &b){
        return a[2] < b[2];
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        int n = points.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({i, j, dist});
            }
        }
        sort(edges.begin(), edges.end(), comparator);
        DSU dsu(n);

        int cost = 0, count = 0;
        for(auto edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            if(dsu.find(u) != dsu.find(v)){
                dsu.weightedUnion(u, v);
                cost += w;
                count++;
                if(count == n - 1){
                    break;
                }
            }
        }
        return cost;
    }
};



// Time Complexity: O(n² log n)
// Space Complexity: O(n²)
