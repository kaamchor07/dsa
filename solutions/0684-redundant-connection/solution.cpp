class DisjointSet {
private:
    std::vector<int> parent;
    std::vector<int> size;

public:
    // Initialize DSU for N elements (0 to N-1)
    DisjointSet(int n) {
        parent.resize(n);
        // Initially, every element is its own parent
        std::iota(parent.begin(), parent.end(), 0);
        // Initially, each set contains exactly 1 element
        size.assign(n, 1);
    }

    // Find the representative root of the set containing 'u'
    // Uses Path Compression to flatten the tree structure
    int find(int u) {
        if (u == parent[u]) {
            return u;
        }
        // Recursively find root and compress path
        return parent[u] = find(parent[u]);
    }

    // Merge the sets containing 'u' and 'v'
    // Uses Union by Size to always attach the smaller tree under the larger tree
    bool unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);

        // They already belong to the same set
        if (root_u == root_v) {
            return false;
        }

        // Attach smaller tree to the root of the larger tree
        if (size[root_u] < size[root_v]) {
            parent[root_u] = root_v;
            size[root_v] += size[root_u];
        } else {
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        }
        return true;
    }

    // Optional: Get the size of the set containing element 'u'
    int getSize(int u) {
        return size[find(u)];
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisjointSet DSU(n+1);
        for(auto i : edges){
            int node1=i[0];
            int node2=i[1];
            if(DSU.find(node1)==DSU.find(node2)){
                return i;
            }
            DSU.unite(node1,node2);
        }
        return {};
    }
};
