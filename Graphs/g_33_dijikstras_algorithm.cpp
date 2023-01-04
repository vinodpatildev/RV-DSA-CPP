#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, int S, vector<vector<int>> adj[]){
    set<pair<int,int>> st;
    vector<int> dist(V, 1e9);

    st.insert({0,S});
    dist[S] = 0;

    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;

        st.erase(it);

        for(auto it : adj[node]){
            int edgeWeight = it[1];
            int adjNode = it[0];

            if(dis + edgeWeight <dist[adjNode]){
                if(dist[adjNode] != 1e9){
                    st.erase({dist[adjNode],adjNode});
                }
                dist[adjNode] = dis + edgeWeight;
                st.insert({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}

int main(){
    //

    return 0;
}