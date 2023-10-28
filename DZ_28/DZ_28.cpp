#include <iostream>

using namespace std;

int** NewColumn(int** A, int s1, int s2, int p)
{
    for (int k = 0; k < s1; k++) {
        for (int j = s2; j >= 0; j--)
            if (j == p) 
                A[k][j] = 0;
            else if (j > p)
                A[k][j] = A[k][j - 1];
    }
    return A;
}
int** DeleteColumn(int** Arr, int s1, int s2, int p)
{
    for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s2; j++) {
            if (j >= p) {
                Arr[i][j] = Arr[i][j + 1];
            }
        }
    }
    return Arr;
}
int** NewArray(int** NArr, int m, int n, int c, char h)
{
    int temp1;
    for (int i = 0; i < m; i++) {    
        if (h == 'r' || h == 'R' || h == 'l' || h == 'L') {
            for (int j = 0; j < c; j++) {
                if (h == 'r' || h == 'R') {
                    for (int k = 0; k < n - 1; k++) {
                        if (k == 0) {
                            temp1 = NArr[i][k + 1];
                            NArr[i][k + 1] = NArr[i][k];
                            NArr[i][k] = NArr[i][n - 1];

                        }
                        else {
                            NArr[i][k + 1] = temp1;
                        }
                    }
                }
                else if (h == 'l' || h == 'L') {
                    for (int k = n - 1; k >= 0; k--) {
                        if (k == n - 1) {
                            temp1 = NArr[i][k - 1];
                            NArr[i][k - 1] = NArr[i][k];
                            NArr[i][k] = NArr[i][0];

                        }
                        else {
                            NArr[i][k - 1] = temp1;
                        }
                    }
                }
            }
        }
        else {
            cout << "Invalid command!" << endl;
            break;
        }
    }
    return NArr;
}
int main()
{
    //1
    int m1 = 3; int m2 = 3;
    int** A = new int* [m1];
    for (int i = 0; i < m1; i++) {
        A[i] = new int[m2];
    }
    int c = 0;
    for (int k = 0; k < m1; k++) {
        for (int l = 0; l < m2; l++) {
            A[k][l] = c;
            c++;
        }
    }
    cout << "Old:\n";
    for (int k = 0; k < m1; k++) {
        for (int l = 0; l < m2; l++) {
            cout << A[k][l] << " ";
        }
        cout << endl;
    }
    int np;
    cout << "Enter the position of the new column: ";
    cin >> np;
    NewColumn(A, m1, m2, np);
    cout << "New:\n";
    for (int k = 0; k < m1; k++) {
        for (int l = 0; l < m2+1; l++) {
            cout << A[k][l] << " ";
        }
        cout << endl;
    }

    //2
    int size1 = 3; int size2 = 3;
    int** Arr = new int* [size1];
    for (int i = 0; i < size1; i++) {
        Arr[i] = new int[size2];
    }
    int s = 0;
    for (int k = 0; k < size1; k++) {
        for (int l = 0; l < size2; l++) {
            Arr[k][l] = s;
            s++;
        }
    }
    cout << "Old:\n";
    for (int k = 0; k < size1; k++) {
        for (int l = 0; l < size2; l++) {
            cout << Arr[k][l] << " ";
        }
        cout << endl;
    }
    int cp;
    cout << "Enter the position of the column: ";
    cin >> cp;
    DeleteColumn(Arr, size1, size2, cp);
    cout << "New:\n";
    for (int k = 0; k < size1; k++) {
        for (int l = 0; l < size2-1; l++) {
            cout << Arr[k][l] << " ";
        }
        cout << endl;
    }

    //3
    int M = 3; int N = 3;
    int** NArr = new int* [M];
    for (int i = 0; i < M; i++) {
        NArr[i] = new int[N];
    }
    int S = 0;
    for (int k = 0; k < M; k++) {
        for (int l = 0; l < N; l++) {
            NArr[k][l] = S;
            S++;
        }
    }
    cout << "Old:\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << NArr[i][j] << " ";
        }
        cout << endl;
    }
    int cn;
    cout << "How much to move: ";
    cin >> cn;
    char ch;
    cout << "Which way (r - right, l - left): ";
    cin >> ch;
    NewArray(NArr, M, N, cn, ch);
    cout << "New:\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << NArr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}