#include <iostream>
#include <vector>

std::vector<std::vector<int>> matrixAdder( std::vector<std::vector<int>>& _matrix1,  std::vector<std::vector<int>>& _matrix2)
{
    std::vector<std::vector<int>> returnMatrix=_matrix1;
 for(int i=0; i<_matrix1.size(); i++){
     for(int j=0; j<_matrix1.size(); j++){
         if(_matrix2[i][j]>_matrix1[i][j]){
             returnMatrix[i][j]=_matrix2[i][j];
         }
         std::cout << returnMatrix[i][j] << " ";
     }
     std::cout << std::endl;
 }
 return returnMatrix;
}

int main() {

    std::vector<std::vector<int>> matrix1={{1,2,3},{4,5,6},{7,8,9}};
    std::vector<std::vector<int>> matrix2={{2,3,4,},{2,3,4,},{8,8,8}};

    matrixAdder(matrix1, matrix2);

}

