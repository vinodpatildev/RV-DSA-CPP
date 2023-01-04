#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, int S, vector<vector<int>> adj[]){
    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
    vector<int> dist(V,1e9);
    dist[S] = 0;
    pq.push({0,S});

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]){
            int edgeWeight = it[1];
            int adjNode = it[0];

            if(dis + edgeWeight < dist[adjNode]){
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}

int main(){
    //

    return 0;
}