#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;

const int MAX_V = 110000;
vector<int> g[MAX_V];
vector<bool> used(MAX_V, false);
int component_cnt = 0;
vector<int> component[MAX_V];

void dfs(int v)
{
    used[v] = true;
    component[component_cnt].push_back(v);
    for (int i = 0; i < g[v].size(); i++)
    {
        int y = g[v][i];
        if (!used[y])
            dfs(y);
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0; i < n; i++)
        if (used[i] == 0)
        {
            dfs(i);
            component_cnt++;
        }
    int min = 1000000;
    for (int i = 0; i < component_cnt; i++)
    {
        if (component[i].size() < min)
            min = component[i].size();
    }
    cout << (min != 1000000 ? min : 1);
    return 0;
}