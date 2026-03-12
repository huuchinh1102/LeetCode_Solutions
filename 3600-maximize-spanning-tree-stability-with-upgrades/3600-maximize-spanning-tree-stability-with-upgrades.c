#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct Edge {
    int u, v, s;
};
int compareEdges(const void *a, const void *b) {
    struct Edge *ea = (struct Edge *)a;
    struct Edge *eb = (struct Edge *)b;
    if (ea->s < eb->s) return 1;
    if (ea->s > eb->s) return -1;
    return 0;
}
struct UnionFind {
    int *parent;
    int *rank;
};

struct UnionFind* createUF(int n) {
    struct UnionFind* uf = (struct UnionFind*)malloc(sizeof(struct UnionFind));
    uf->parent = (int*)malloc(n * sizeof(int));
    uf->rank = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }
    return uf;
}

int findSet(struct UnionFind* uf, int i) {
    int root = i;
    while (root != uf->parent[root]) {
        root = uf->parent[root];
    }
    int curr = i;
    while (curr != root) {
        int nxt = uf->parent[curr];
        uf->parent[curr] = root;
        curr = nxt;
    }
    return root;
}

int unionSet(struct UnionFind* uf, int i, int j) {
    int rootI = findSet(uf, i);
    int rootJ = findSet(uf, j);
    if (rootI != rootJ) {
        if (uf->rank[rootI] < uf->rank[rootJ]) {
            uf->parent[rootI] = rootJ;
        } else if (uf->rank[rootI] > uf->rank[rootJ]) {
            uf->parent[rootJ] = rootI;
        } else {
            uf->parent[rootJ] = rootI;
            uf->rank[rootI]++;
        }
        return 1;
    }
    return 0;
}

void freeUF(struct UnionFind* uf) {
    free(uf->parent);
    free(uf->rank);
    free(uf);
}

int maxStability(int n, int** edges, int edgesSize, int* edgesColSize, int k) {
    struct UnionFind* uf = createUF(n);
    int cnt = 0;
    int INF = 2000000000;
    int result = INF;
    for (int i = 0; i < edgesSize; i++) {
        if (edges[i][3] == 1) {
            if (!unionSet(uf, edges[i][0], edges[i][1])) {
                freeUF(uf);
                return -1;
            }
            cnt++;
            result = MIN(result, edges[i][2]);
        }
    }
    struct Edge* optEdges = (struct Edge*)malloc(edgesSize * sizeof(struct Edge));
    int optCount = 0;
    for (int i = 0; i < edgesSize; i++) {
        if (edges[i][3] == 0) {
            optEdges[optCount].u = edges[i][0];
            optEdges[optCount].v = edges[i][1];
            optEdges[optCount].s = edges[i][2];
            optCount++;
        }
    }

    qsort(optEdges, optCount, sizeof(struct Edge), compareEdges);
    for (int i = 0; i < optCount; i++) {
        if (!unionSet(uf, optEdges[i].u, optEdges[i].v)) {
            continue;
        }
        cnt++;
        if (cnt == (n - 1) - k) {
            result = MIN(result, optEdges[i].s);
        } 
        else if (cnt == n - 1) {
            result = MIN(result, 2 * optEdges[i].s);
        }
    }

    free(optEdges);
    freeUF(uf);
    if (cnt == n - 1) {
        return result;
    } else {
        return -1;
    }
}