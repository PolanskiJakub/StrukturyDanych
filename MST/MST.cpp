#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <chrono>
#include <fstream>


using namespace std::chrono;
using namespace std;


const int MAX = 1e6 + 5;
int id[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];


void initialize()
{
    for (int i = 0; i < MAX; ++i)
        id[i] = i;
}

int root(int x)
{
    while (id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int> > p[])
{
    int x, y;
    long long cost, minimumCost = 0;

    cout << "Minimum Spanning Tree (T): ";
    for (int i = 0; i < edges; ++i)
    {
        
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;

        
        if (root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
            cout << "(" << x << "," << y << "),";
        }
    }
    return minimumCost;
}

int main()
{
    double x, y;
    long long weights, cost, costMinimum;
    initialize();
    ifstream infile;
    infile.open("dane.txt");

    if (!infile) {
        cout << "Unable to open file";
        exit(1); 
    }
    auto start = high_resolution_clock::now();
    infile >> nodes;
    for (int i = 0; !infile.eof(); ++i) {
        
        infile >> x >> y >> weights;
        p[i] = make_pair(weights, make_pair(x, y));
        edges += 1;
        if (i > 10000) {
            break;
        }
    }
    sort(p, p + edges);
    costMinimum = kruskal(p);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << endl << "Total Executiontime: " << duration.count() << "ms" << endl;
    cout << "Minimum Cost = " << costMinimum << endl;
    ofstream outFile2;
    outFile2.open("czasy.csv", ios::app);
    outFile2 << duration.count() << ";"  << costMinimum <<";" << "Kurskal" << endl;
}