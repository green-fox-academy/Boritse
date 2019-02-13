#include <vector>
#include <iostream>

void printMatrix(const std::vector<std::vector<int>>& matrix);

std::vector<std::vector<int>> rotateMatrix(const std::vector<std::vector<int>>& _matrix){
    std::vector<std::vector<int>> rotatedMatrix=_matrix;
    int otherIndex=_matrix.size()-1;
    for(int i=0; i<_matrix.size(); i++){
        for(int j=_matrix.size()-1; j>=0; j--){
            rotatedMatrix[j][otherIndex]=_matrix[i][j];
        }
        otherIndex--;
    }
    return rotatedMatrix;
}

int main()
{
    // Create a function named `rotateMatrix` that takes an n×n integer matrix (vector of vectors) as parameter
    // and returns a matrix which elements are rotated 90 degrees clockwise.
    //
    // example input:
    // [[1, 2, 3],
    // [4, 5, 6],
    // [7, 8, 9]]

    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    std::vector<std::vector<int>> rotatedMatrix = rotateMatrix(matrix);

    printMatrix(rotatedMatrix);
    // should print
    // 7 4 1
    // 8 5 2
    // 9 6 3

    return 0;
}

void printMatrix(const std::vector<std::vector<int>>& matrix)
{
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}