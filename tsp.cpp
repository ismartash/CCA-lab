#include <iostream>
using namespace std;

#define MAX 9999

int n;
int dist[20][20];
int completed;
int dp[32][8];
int path[32][8];

int tsp(int mask, int pos) {
    if (mask == completed) {
        return dist[pos][0];
    }
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = MAX;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int new_ans = dist[pos][city] + tsp(mask | (1 << city), city);
            if (new_ans < ans) {
                ans = new_ans;
                path[mask][pos] = city;
            }
        }
    }
    return dp[mask][pos] = ans;
}

void printPath() {
    int mask = 1, pos = 0;
    cout << "Path: ";
    while (mask != completed) {
        cout << pos << " ";
        pos = path[mask][pos];
        mask |= (1 << pos);
    }
    cout << pos;
    cout << endl;
}

int main() {
    cout << "Enter the number of cities: ";
    cin >> n;

    cout << "Enter the distance matrix (0 for the same city):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    completed = (1 << n) - 1;

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    cout << "Minimum Distance Travelled -> " << tsp(1, 0) << endl;
    printPath();

    return 0;
}
