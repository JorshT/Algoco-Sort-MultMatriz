#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <chrono>
using namespace std;

typedef vector<vector<int>> Matrix;

Matrix add(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

Matrix subtract(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

Matrix strassen(const Matrix &A, const Matrix &B) {
    int n = A.size();
    if (n == 1) {
        Matrix C(1, vector<int>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int newSize = n / 2;
    Matrix A11(newSize, vector<int>(newSize)), A12(newSize, vector<int>(newSize)),
           A21(newSize, vector<int>(newSize)), A22(newSize, vector<int>(newSize));
    Matrix B11(newSize, vector<int>(newSize)), B12(newSize, vector<int>(newSize)),
           B21(newSize, vector<int>(newSize)), B22(newSize, vector<int>(newSize));

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    Matrix M1 = strassen(add(A11, A22), add(B11, B22));
    Matrix M2 = strassen(add(A21, A22), B11);
    Matrix M3 = strassen(A11, subtract(B12, B22));
    Matrix M4 = strassen(A22, subtract(B21, B11));
    Matrix M5 = strassen(add(A11, A12), B22);
    Matrix M6 = strassen(subtract(A21, A11), add(B11, B12));
    Matrix M7 = strassen(subtract(A12, A22), add(B21, B22));

    Matrix C11 = add(subtract(add(M1, M4), M5), M7);
    Matrix C12 = add(M3, M5);
    Matrix C21 = add(M2, M4);
    Matrix C22 = add(subtract(add(M1, M3), M2), M6);

    Matrix C(n, vector<int>(n));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    return C;
}





Matrix multiplicar_matrices_transpuesta(vector<vector<int>>& A , vector<vector<int>>& B, int n){
    vector<vector<int>> C(n,vector<int>(n));

    //Antes de multiplicar, calcular transpuesta

    vector<vector<int>> B_T(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            B_T[j][i] = B[i][j];
        }
    }




    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                C[i][j] = C[i][j]+A[i][k] * B_T[j][k];
            }
        }
    }
    return C;
}

Matrix multiplicar_matrices_convencional(vector<vector<int>>& A , vector<vector<int>>& B, int n){
    vector<vector<int>> C(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                C[i][j] = C[i][j]+A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

void printMatrix(const Matrix &M) {
    int n = M.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}


int main(){

    ifstream fp("datasets/matrix_mediumA.txt");
    if(!fp.is_open()){
        cout<<"Error al abrir el archivo";
        return 1;
    }
    int n_elements;
    int elem;
    fp>>n_elements;
    vector<vector<int>> matrixA(n_elements,vector<int>(n_elements));
    for(int i=0;i<n_elements;i++){
        for(int j=0;j<n_elements;j++){
            fp>>elem;
            matrixA[i][j]=elem;
        }

    }
    fp.close();
    ifstream fp2("datasets/matrix_mediumB.txt");
    if(!fp2.is_open()){
        cout<<"Error al abrir el archivo";
        return 1;
    }
    fp2>>n_elements;
    vector<vector<int>> matrixB(n_elements,vector<int>(n_elements));
    for(int i=0;i<n_elements;i++){
        for(int j=0;j<n_elements;j++){
            fp2>>elem;
            matrixB[i][j]=elem;
        }

    }
    fp2.close();
    
    cout<<"Multiplicando matrices..."<<endl;
    auto start = chrono::high_resolution_clock::now();
    //Matrix C = multiplicar_matrices_convencional(matrixA,matrixB,n_elements);
    Matrix C = multiplicar_matrices_transpuesta(matrixA,matrixB,n_elements);
    //Matrix C = strassen(matrixA,matrixB);
    auto end = chrono::high_resolution_clock::now();
    cout<<"Matrices multiplicadas completamente :)"<<endl;
    chrono::duration<double> duracion = end-start;
    cout<<"Ha tardado: "<<duracion.count()<<" segundos en multiplicar matrices"<<endl;

    ofstream fp_w("Salida_matriz.txt");
    if(!fp_w){
        cout<<"Error al abrir el archivo"<<endl;
        return 1;
    }


    cout<<"Escribiendo salida..."<<endl;
    for(int i=0;i<n_elements;i++){
        for(int j=0;j<n_elements;j++){
            fp_w<<C[i][j];
            fp_w<<" ";
        }
        fp_w<<"\n";
    }
    fp_w.close();


    return 0;
}