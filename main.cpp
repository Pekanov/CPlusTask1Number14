#include <iostream>

using namespace std;


int** generateMatrinx (int row, int column){
    int** matrix = new int* [row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new int[column];
    }

    srand(time(nullptr));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            matrix[i][j] = rand() % 100 - 50;
        }
    }

    return matrix;
}

void printMatrix(int** matrix, int row, int column) {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

bool* generateVector(int row){
    bool *vector = new bool [row];
    for (int i = 0; i < row; i++) {
        vector[i] = true;
    }
    return vector;
}

void printVector(bool* vector, int row) {

    for (int i = 0; i < row; i++) {
        cout << vector[i] << "\t\n";
    }
}

bool* fillingVector(int** matrix, bool* vector, int row, int column){
    int previous;
    for (int i = 0; i < row; i++) {
        for (int j = 1; j < column; j++) {
            previous = matrix[i][j-1];
            if (matrix[i][j] <= previous){
                vector[i] = false;
                break;
            }
        }
    }
    return vector;
}

int main() {

    int row, column;

    cout << "enter rows - ";
    cin >> row;
    cout << "enter columns - ";
    cin >> column;

    int** matrix = generateMatrinx(row, column);
    printMatrix(matrix, row, column);

    cout << endl;

    bool* vector = fillingVector(matrix, generateVector(row), row, column);
    printVector(vector,row);


}
