#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int row, col, time;
};

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    queue<Cell> q;
    int freshCount = 0;

    // Step 1: Push all initially rotten oranges into queue
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j, 0}); // rotten source
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }

    // Directions: up, down, left, right
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};

    int maxTime = 0;

    // Step 2: BFS from all rotten oranges
    while (!q.empty()) {
        auto [r, c, t] = q.front();
        q.pop();
        maxTime = max(maxTime, t);

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                grid[nr][nc] = 2;       // make rotten
                freshCount--;           // one less fresh orange
                q.push({nr, nc, t + 1});
            }
        }
    }

    // Step 3: Check if all fresh oranges rotted
    return (freshCount > 0) ? -1 : maxTime;
}

int main()
{
    cout<<"Enter the size of the grid n,m : ";
    int n,m;
    cin>>n>>m;
    cout<<"Enter the elements in the grid : ";
    vector<vector<int>> grid(m,vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> grid[i][j];  // 0 = empty, 1 = fresh, 2 = rotten
        }
    }
    int result=rott(grid);
    cout<<"minimum time required = "<<result;
    return 0;
}

