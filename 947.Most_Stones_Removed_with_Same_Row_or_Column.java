import java.util.*;

class Solution {
    public int removeStones(int[][] stones) {
        int n = stones.length;
        UnionFind uf = new UnionFind(20002);

        for (int i = 0; i < n; ++i) {
            uf.union(stones[i][0], stones[i][1] + 10001);
        }
        return n - uf.componentCount;
    }

    class UnionFind {
        int[] parent;
        int componentCount;
        Set<Integer> uniqueNodes;

        UnionFind(int n) {
            parent = new int[n];
            Arrays.fill(parent, -1);
            componentCount = 0;
            uniqueNodes = new HashSet<>();
        }

        int find(int node) {
            if (!uniqueNodes.contains(node)) {
                componentCount++;
                uniqueNodes.add(node);
            }

            if (parent[node] == -1) {
                return node;
            }
            return parent[node] = find(parent[node]);
        }

        void union(int node1, int node2) {
            int root1 = find(node1);
            int root2 = find(node2);

            if (root1 == root2) {
                return;
            }

            parent[root1] = root2;
            componentCount--;
        }
    }
}
