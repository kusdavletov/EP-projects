#include "matrix.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

/*
 *--------------------
 * Matrix Creation
 *--------------------
 */
Matrix* rand(const int numRows, const int numCols)
{
    Matrix *M;
    M = new Matrix[numRows];
    for (int i = 0; i < numRows; i++)
    {
            M[i].numCols = numCols;
            M[i].numRows = numRows;
            M[i].mat = new float[numCols];
            for (int j = 0; j < numCols; j++)
                M[i].mat[j] = (rand() % 100) + 1;
    }
    return M;
}

Matrix* ones(const int numRows, const int numCols)
{
    Matrix *M;
    M = new Matrix[numRows];
    for (int i = 0; i < numRows; i++)
    {
            M[i].numCols = numCols;
            M[i].numRows = numRows;
            M[i].mat = new float[numCols];
            for (int j = 0; j < numCols; j++)
                M[i].mat[j] = 1;
    }
    return M;
}

Matrix* zeros(const int numRows, const int numCols)
{
    Matrix *M;
    M = new Matrix[numRows];
    for (int i = 0; i < numRows; i++)
    {
            M[i].numCols = numCols;
            M[i].numRows = numRows;
            M[i].mat = new float[numCols];
            for (int j = 0; j < numCols; j++)
                M[i].mat[j] = 0;
    }
    return M;
}

/*
 *--------------------
 * Matrix Addition
 *--------------------
 */
Matrix* add(const Matrix* A, const Matrix* B)
{
    if (A -> numRows == B -> numRows && A -> numCols == B -> numCols)
    {
        Matrix *M = zeros(A -> numRows, A -> numCols);
        for (int i = 0; i < A -> numRows; i++)
            for (int j = 0; j < A -> numCols; j++)
                M[i].mat[j] = A[i].mat[j] + B[i].mat[j];
        return M;
    }
    else
        return NULL;
}

Matrix* add(const Matrix* A, const Matrix* B, const Matrix* C)
{
    if ((A -> numRows == B -> numRows) && (A -> numCols == B -> numCols) && (A -> numRows == C -> numRows) && (A -> numCols == C -> numCols))
    {
        Matrix *M = zeros(A -> numRows, A -> numCols);
        for (int i = 0; i < A -> numRows; i++)
            for (int j = 0; j < A -> numCols; j++)
                M[i].mat[j] = A[i].mat[j] + B[i].mat[j] + C[i].mat[j];
        return M;
    }
    else
        return NULL;
}

/*
 *--------------------
 * Matrix Transpose
 *--------------------
 */
Matrix* transpose(const Matrix* A)
{
    Matrix *M = zeros(A -> numRows, A -> numCols);
    for (int i = 0; i < A -> numRows; i++)
        for (int j = 0; j < A -> numCols; j++)
            M[i].mat[j] = A[j].mat[i];
    return M;
}

/*
 *-----------------------
 * Matrix Multiplication
 *-----------------------
 */
Matrix* multiply(const Matrix* A, const Matrix* B)
{
    if (A -> numCols == B -> numRows)
    {
        Matrix *M = zeros(A -> numRows, B -> numCols);
        for (int i = 0; i < A -> numRows; i++)
            for (int j = 0; j < B -> numCols; j++)
                for (int k = 0; k < B -> numRows; k++)
                    M[i].mat[j] += A[i].mat[k] * B[k].mat[j];
        return M;
    }
    else
        return NULL;
}

Matrix* multiply(const Matrix* A, const Matrix* B, const Matrix* C)
{
    if (A -> numCols == B -> numRows && B -> numCols == C -> numRows)
    {
        int way1 = A -> numRows * B -> numCols * A -> numCols + A -> numRows * C -> numCols * B -> numCols;
        int way2 = B -> numRows * C -> numCols * B -> numCols + A -> numRows * C -> numCols * A -> numCols;
        if (way1 >= way2)
            return multiply(A, multiply (B, C));
        else
            return multiply(multiply (A, B), C);
    }
    else
        return NULL;
}

/*
 *------------------------------
 * Matrix Scalar Multiplication
 *------------------------------
 */
Matrix* multiply(const Matrix* A, const float c)
{
    Matrix *M = zeros(A -> numRows, A -> numCols);
    for (int i = 0; i < A -> numRows; i++)
   		for (int j = 0; j < A -> numCols; j++)
        	M[i].mat[j] = A[i].mat[j] * c;
  	return M;
}

/*
 *--------------------
 * Matrix Load
 *--------------------
 */

Matrix* load(const char* fname)
{
    ifstream input(fname);
    int rows, columns;
    input >> rows >> columns;
    Matrix *M = zeros(rows, columns);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            input >> M[i].mat[j];
    input.close();
    return M;
}

Matrix* bload(const char* fname)
{
    ifstream input(fname, ios::in | ios::binary);
    int rows, columns;
    input >> rows >> columns;
    Matrix *M = zeros(rows, columns);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            input >> M[i].mat[j];
    input.close();
    return M;
}

/*
 *--------------------
 * Matrix Save
 *--------------------
 */
void save(const Matrix* A, const char* fname)
{
    ofstream output(fname);
    output << A -> numRows << "   " << A -> numCols << endl;
    int rows = A -> numRows;
    int columns = A -> numCols;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            output << A[i].mat[j] << "   ";
        output << endl;
    }
    output.close();
}

void bsave(const Matrix* A, const char* fname)
{
    ofstream output(fname, ios::out | ios::binary);
    output << A -> numRows << "   " << A -> numCols << endl;
    int rows = A -> numRows;
    int columns = A -> numCols;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            output << A[i].mat[j] << "   ";
        output << endl;
    }
    output.close();
}

/*
 *--------------------
 * Matrix Display
 *--------------------
 */
void show(const Matrix* A)
{
    for (int i = 0; i < A -> numRows; i++)
    {
        for (int j = 0; j < A -> numCols; j++)
            cout << A[i].mat[j] << "   ";
        cout << "\n";
    }
}

/*
 *--------------------
 * Matrix Deletion
 *--------------------
 */
void del(const Matrix* A)
{
    for (int i = 0; i < A -> numRows; i++)
        delete [] A[i].mat;
    delete [] A;
}












/*
 *-------------------------
 * Sparse Matrix Creation
 *-------------------------
 */
SparseMatrix* spzeros(const int numRows, const int numCols) {

}

SparseMatrix* spones(const int numRows, const int numCols) {

}

SparseMatrix* sprand(const int numRows, const int numCols) {

}


/*
 *-------------------------
 * Sparse Matrix Addition
 *-------------------------
 */
SparseMatrix* spadd(const SparseMatrix* A, const SparseMatrix* B) {

}

SparseMatrix* spadd(const SparseMatrix* A, const SparseMatrix* B, const SparseMatrix* C) {

}


/*
 *---------------------------
 * Sparse Matrix Transpose
 *---------------------------
 */
SparseMatrix* transpose(const SparseMatrix* A) {

}



/*
 *------------------------------
 * Sparse Matrix Multiplication
 *------------------------------
 */
SparseMatrix* spmultiply(const SparseMatrix* A, const SparseMatrix* B) {

}

SparseMatrix* spmultiply(const SparseMatrix* A, const SparseMatrix* B, const SparseMatrix* C) {

}


/*
 *-------------------------------------
 * Sparse Matrix Scalar Multiplication
 *-------------------------------------
 */
SparseMatrix* spmultiply(const SparseMatrix* A, const float c) {

}


/*
 *--------------------
 * Sparse Matrix Load
 *--------------------
 */
SparseMatrix* spload(const char* fname) {

}

SparseMatrix* spbload(const char* fname) {

}


/*
 *--------------------
 * Sparse Matrix Save
 *--------------------
 */
void spsave(const SparseMatrix* A, const char* fname) {

}

void spbsave(const SparseMatrix* A, const char* fname) {

}


/*
 *------------------------
 * Sparse Matrix Display
 *------------------------
 */
void spshow(const SparseMatrix* A) {

}


/*
 *-------------------------
 * Sparse Matrix Deletion
 *-------------------------
 */
void spdel(const SparseMatrix* mat) {

}
