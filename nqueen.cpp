#include<iostream>
using namespace std;
bool safe(int arr[][4], int x, int y, int n) {
    for (int row = 0; row < x; row++) {  //column check
        if (arr[row][y] == 1) {
            return false;
        }
    }
    int row = x, col = y;  
    while (row >= 0 && col >= 0) {     //upper left diagonal
        if (arr[row][col] == 1) {
            return false;
        }
        row--;
        col--;
    }
    row = x, col = y;
    while (row >= 0 && col < n) { //uper right digonal
        if (arr[row][col] == 1) {
            return false;
        }
        row--;
        col++;
    }
    //  row = x, col = y;
    // while (row < n && col >= 0) {
    //     if (arr[row][col] == 1) {
    //         return false;
    //     }
    //     row++;
    //     col--;
    // }
    // row = x, col = y;
    // while (row < n && col < n) {
    //     if (arr[row][col] == 1) {
    //         return false;
    //     }
    //     row++;
    //     col++;
    // }
    return true;
}

bool nqueen(int arr[][4], int x, int n) {
    if (x >= n) {
        return true; 
    }
    
    for (int col = 0; col < n; col++) {
        if (safe(arr, x, col, n)) {
            arr[x][col] = 1; 

            if (nqueen(arr, x + 1, n)) {
                return true;
            }

            arr[x][col] = 0;
        }
    }

    return false; 
}

int main() {
    int n=4;
    int arr[4][4]={0};
    if (nqueen(arr, 0, n)) {
        cout<<"solutionn for 4x4 chess board"<<endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout <<"no solution exist"<< endl;
    }
    return 0;
}

