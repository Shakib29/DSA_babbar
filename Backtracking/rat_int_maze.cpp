#include <bits/stdc++.h> 

using namespace std;

bool issafe(int newx, int newy, int n, vector<vector<int>> &visited, vector<vector<int>> &arr) {
    return (newx >= 0 && newx < n && newy >= 0 && newy < n && visited[newx][newy] == 0 && arr[newx][newy] == 1);
}

void solve(int x, int y, int n, vector<vector<int>> &arr, vector<vector<int>> &visited, string path, vector<string> &ans) {
    if (x == n-1 && y == n-1) {
        ans.push_back(path);
        return;
    }

    // Down
    if (issafe(x+1, y, n, visited, arr)) {
        visited[x][y] = 1;
        solve(x+1, y, n, arr, visited, path + 'D', ans);
        visited[x][y] = 0;
    }
    // Left
    if (issafe(x, y-1, n, visited, arr)) {
        visited[x][y] = 1;
        solve(x, y-1, n, arr, visited, path + 'L', ans);
        visited[x][y] = 0;
    }
    // Right
    if (issafe(x, y+1, n, visited, arr)) {
        visited[x][y] = 1;
        solve(x, y+1, n, arr, visited, path + 'R', ans);
        visited[x][y] = 0;
    }
    // Up
    if (issafe(x-1, y, n, visited, arr)) {
        visited[x][y] = 1;
        solve(x-1, y, n, arr, visited, path + 'U', ans);
        visited[x][y] = 0;
    }
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
    vector<string> ans;
    if (arr[0][0] == 0 || arr[n-1][n-1] == 0) {
        // If start or end cell is blocked, no path possible
        return ans;
    }

    vector<vector<int>> visited(n, vector<int>(n, 0));
    visited[0][0] = 1; // Mark the start cell as visited
    solve(0, 0, n, arr, visited, "", ans);

    return ans;
}
