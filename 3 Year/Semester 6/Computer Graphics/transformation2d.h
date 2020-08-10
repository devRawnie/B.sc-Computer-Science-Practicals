#ifndef _TRANSFORMATION_2D_H_
#define _TRANSFORMATION_2D_H_
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
class Matrix2D{
    public:
    float **arr;
    int r,c;
    Matrix2D(){}
    Matrix2D(int r, int c){
        this->r = r;
        this->c = c;
        this->arr = new float* [r];
        for(int i = 0; i < r; i++){
            arr[i] = new float[c];
        }
    }
    void setMatrix(float a[][3]){
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
    static Matrix2D multiply(Matrix2D m1, Matrix2D m2){
        Matrix2D m(m1.r, m2.c);
        for(int i = 0; i < m1.r; i++){
            for(int j = 0; j < m2.c ; j++){
                for(int k = 0; k < m1.c ; k++){
                    m.arr[i][j] += m1.arr[i][k]*m2.arr[k][j];
                }
            }
        }
        return m;
    }
    static Matrix2D multiply(Matrix2D* m1, Matrix2D m2){
        Matrix2D m(m1->r, m2.c);
        for(int i = 0; i < m1->r; i++){
            for(int j = 0; j < m2.c ; j++){
                for(int k = 0; k < m1->c ; k++){
                    m.arr[i][j] += m1->arr[i][k]*m2.arr[k][j];
                }
            }
        }
        return m;
    }

    int* getPolygonPoints(){
        int size = r*c - 2;
        int * points = new int[size];
        int k = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c-1; j++){
                points[k++] = (int) abs(arr[i][j]);
            }
        }
        points[k++] = (int) abs(arr[0][0]);
        points[k++] = (int) abs(arr[0][1]);
        // cout<<endl;
        // for(int i = 0; i < size; i++){
        //     cout<<points[i]<<" ";
        // }
        return points;
    }

};
class transform2d{
    public:
        Matrix2D *p;
    transform2d(){p = nullptr;}
    ~transform2d(){
        if(p != nullptr){
            free(p);
        }
    }
    void getPoints(){
        int n;
        cout<<"Enter no of points: ";
        cin>>n;
        if(p != nullptr){
            free(p);
        }
        p = new Matrix2D(n,3);
        float x,y;
        for(int i = 0; i < n; i++){
            printf("Point %d\nEnter x co-ordinate: ", i+1);
            cin>>x;
            cout<<"Enter y co-ordinate: ";
            cin>>y;
            p->arr[i][0] = x;
            p->arr[i][1] = y;
            p->arr[i][2] = 1; 
        }
        cout<<"Points matrix is:\n";
        p->printMatrix();
    }
    void translate(){
        float tx, ty;
        cout<<"Enter translation in x-axis: ";
        cin>>tx;
        cout<<"Enter translation in y-axis: ";
        cin>>ty;

        float t[3][3] = {
            {1,0,0},
            {0,1,0},
            {tx,ty,1}         
        };
        Matrix2D trf(3,3);
        trf.setMatrix(t);
        cout<<"\nTransformation matrix:\n";
        trf.printMatrix();
        cout<<"\nOriginal points:\n";
        this->p->printMatrix();
        Matrix2D result = Matrix2D::multiply(this->p, trf);
        cout<<"\nTransformed points: \n";
        result.printMatrix();        
        // //plot(result);
    }
    void scale(){
        float sx, sy;
        cout<<"Enter X-axis scaling factor: ";
        cin>>sx;
        cout<<"Enter Y-axis scaling factor: ";
        cin>>sy;
        
        float t[3][3] = {
            {sx,0,0},
            {0,sy,0},
            {0,0,1}         
        };
        Matrix2D trf(3,3);
        trf.setMatrix(t);
        cout<<"\nTransformation matrix:\n";
        trf.printMatrix();
        cout<<"\nOriginal points:\n";
        this->p->printMatrix();
        Matrix2D result = Matrix2D::multiply(this->p, trf);
        cout<<"\nTransformed points: \n";
        result.printMatrix();        
        //plot(result);
    }
    /*
                     [  cosT sinT 0]
        PointMatrix* [ -sinT cosT 0] 
                     [  0    0    1]
    */
    void rotate(){
        float thetaR, thetaD;
        cout<<"Enter angle of rotation, in degrees: ";
        cin>>thetaD;
        thetaR = thetaD * 3.14159/180;
        float cosT = (float) cos(thetaR);
        float sinT = (float) sin(thetaR);
        float t[3][3] = {
            {cosT,sinT,0},
            {-1*sinT,cosT,0},
            {0,0,1}         
        };
        Matrix2D trf(3,3);
        trf.setMatrix(t);
        cout<<"\nTransformation matrix:\n";
        trf.printMatrix();
        cout<<"\nOriginal points:\n";
        this->p->printMatrix();
        Matrix2D result = Matrix2D::multiply(this->p, trf);
        cout<<"\nTransformed points: \n";
        result.printMatrix();     
        //plot(result);   
    }
    void reflect(){
        float t[3][3] = {
            {1,0,0},
            {0,1,0},
            {0,0,1}         
        };
        bool flag = true;
        while(flag){
            cout<<"\nReflect about:\n1.X-Axis\t2.Y-Axis\n3.Line X=Y\t4.Origin\n: ";
            int choice;
            cin>>choice;
            switch (choice)
            {
                case 1:
                    t[1][1] = -1;
                    flag = false;
                    break;
                case 2:
                    t[0][0] = -1;
                    flag = false;
                    break;
                case 3:
                    t[0][0] = t[1][1] = 0;
                    t[0][1] = t[1][0] = 1;
                    flag = false;
                    break;
                case 4:
                    t[0][0] = t[1][1] = -1;
                    flag = false;
                    break;
                default: cout<<"Invalid choice, try again";
                }
        }
        Matrix2D trf(3,3);
        trf.setMatrix(t);
        cout<<"\nTransformation matrix:\n";
        trf.printMatrix();
        cout<<"\nOriginal points:\n";
        this->p->printMatrix();
        Matrix2D result = Matrix2D::multiply(this->p, trf);
        cout<<"\nTransformed points: \n";
        result.printMatrix();     
        //plot(result);
    }
};

int execute_2d(){
    transform2d t;
    t.getPoints();
    while(true){
        cout<<"\nEnter your choice:\n";
        cout<<"1.Translate\n2.Scale\n3.Rotate\n4.Reflect\n5.Show Points\n6.Change Points\n7.Exit\n: ";
        int choice;
        cin>>choice;
        switch (choice)
        {
        case 1:
            t.translate();
            break;
        case 2:
            t.scale();
            break;
        case 3:
            t.rotate();
            break;
        case 4:
            t.reflect();
            break;
        case 5:
            cout<<"Points Matrix is:\n";
            t.p->printMatrix();
            break;
        case 6:
            t.getPoints();
            break;
        case 7:
            return 0;
        default:
            cout<<"\nInvalid choice. Please try again";
            break;
        }
    }
    return -1;
}
#endif