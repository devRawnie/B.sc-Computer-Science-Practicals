#ifndef _MATRIX_3D_H_
#define _MATRIX_3D_H_

#include<iostream>
using namespace std;

class Matrix3D{
    public:
    float **arr;
    int r,c;
    Matrix3D(){}
    Matrix3D(int r, int c){
        this->r = r;
        this->c = c;
        this->arr = new float* [r];
        for(int i = 0; i < r; i++){
            arr[i] = new float[c];
        }
    }
    int* getPlotPoints(){
        int *points = new int[r*2];
        int k=0;
        for(int i =0 ; i<r;i++){
            points[k++] = (int) arr[i][0];
            points[k++] = (int) arr[i][1];            
        }
        points[k++] = (int) arr[0][0];
        points[k++] = (int) arr[0][1];
        // for(int i =0; i<=2*r; i+=2){
        //     cout<<points[i]<<","<<points[i+1]<<"\n";
        // }
        return points;
    }
    void setMatrix(float a[][4]){
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                this->arr[i][j] = a[i][j];
            }
        }
    }
    void printMatrix(){
        for(int i =0 ; i < r; i++){
            cout<<"[ ";
            for(int j = 0; j <c; j++){
                cout<<arr[i][j]<<" ";
            }
            
            i==r-1 ? printf("](%d,%d)\n",r,c): printf("]\n");
        }
    }
    static Matrix3D multiply(Matrix3D m1, Matrix3D m2){
        Matrix3D m(m1.r, m2.c);
        for(int i = 0; i < m1.r; i++){
            for(int j = 0; j < m2.c ; j++){
                for(int k = 0; k < m1.c ; k++){
                    m.arr[i][j] += m1.arr[i][k]*m2.arr[k][j];
                }
            }
        }
        return m;
    }
    static Matrix3D multiply(Matrix3D* m1, Matrix3D m2){
        Matrix3D m(m1->r, m2.c);
        for(int i = 0; i < m1->r; i++){
            for(int j = 0; j < m2.c ; j++){
                for(int k = 0; k < m1->c ; k++){
                    m.arr[i][j] += m1->arr[i][k]*m2.arr[k][j];
                }
            }
        }
        return m;
    }
};
#endif