#include <bits/stdc++.h>
using namespace std;

struct Canh {
    int dau, cuoi;
    double trongso;
};

struct Subset {
    int parent;
    int rank;
};

// Find the parent of a node (using path compression)
int find(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union of two sets (by rank)
void unionSets(vector<Subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Comparator function to sort edges by weight
bool compareEdges(const Canh& a, const Canh& b) {
    return a.trongso < b.trongso;
}

// Find the minimum weighted spanning tree using Kruskal's algorithm
vector<Canh> kruskalMST(vector<Canh>& edges, int V) {
    vector<Canh> result;
    vector<Subset> subsets(V);

    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    sort(edges.begin(), edges.end(), compareEdges);

    int e = 0;
    int i = 0;
    while (e < V - 1 && i < edges.size()) {
        Canh nextEdge = edges[i++];

        int x = find(subsets, nextEdge.dau);
        int y = find(subsets, nextEdge.cuoi);

        if (x != y) {
            result.push_back(nextEdge);
            unionSets(subsets, x, y);
            e++;
        }
    }

    return result;
}

int main() {
    ifstream inputFile("Graph.txt");
    ofstream outputFile("Kruskal.txt");
    int V;
    inputFile >> V;

    vector<Canh> edges;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            double weight;
            inputFile >> weight;
            // Using the condition i < j, we ensure that we only consider the upper triangular part of the matrix, avoiding duplicate edges
            if (weight != 0 && i < j) {
                Canh edge;
                edge.dau = i;
                edge.cuoi = j;
                edge.trongso = weight;
                edges.push_back(edge);
            }
        }
    }

    vector<Canh> result = kruskalMST(edges, V);

    double totalWeight = 0;
    for (const auto& edge : result) {
        totalWeight += edge.trongso;
    }

    outputFile << fixed << setprecision(2) << totalWeight << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
