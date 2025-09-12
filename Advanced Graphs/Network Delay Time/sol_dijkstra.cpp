class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>> > adjList;
        for(auto edge : times){
            adjList[edge[0]].push_back({edge[1], edge[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1, INT_MAX);
        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            // If d is greater than dist[u], it means we will relax neighbour's weights with longer distance
            // We would process the node multiple times with outdated (longer) distances.
            // Algorithm would still be correct ✅, because shorter paths are found earlier.
            // But it would be much slower, especially on dense graphs → could blow up to O(E log E) operations. 
            if(d > dist[u]){
                continue;
            }
            for(auto [v, w] : adjList[u]){
                // note akash : earlier I was making a mistake -> auto [w, v] : adjList[u]
                // since in pq, i stored weight first and then node, so i was doing the same as pq
                // but in adjacencyList, i stored node first and then weight, so it was giving wrong answer
                if(dist[v] > d + w){
                    dist[v] = d + w;
                    cout<<endl;
                    pq.push({dist[v], v});
                }
            }
        }
        int maxDuration = 0;
        for(int i = 1; i <= n; i++){
            maxDuration = max(maxDuration, dist[i]);
        }
        return maxDuration == INT_MAX ? -1 : maxDuration;

    }
};

// TC = O(Elog(v))
