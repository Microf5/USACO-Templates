vector<long long> dists(n, -1);
    vector<int> prev(n, -1);
    pq.push({ 0,0 });
    dists[0] = 0;
    while (!pq.empty()) {
        auto fr = pq.top(); pq.pop();
        int dist = fr.first; int node = fr.second;
        for (auto c : g[node]) {
            int v = c.first;
            int weight = c.second;
            if (dists[v] > dists[node] + weight || dists[v]==-1) {
                dists[v] = dists[node] + weight;
                prev[v] = node;
                pq.push(make_pair(dists[v], v));
            }
        }
    }
