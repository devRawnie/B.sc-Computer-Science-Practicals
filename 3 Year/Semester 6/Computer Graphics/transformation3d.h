#ifndef _TRANSFORMATION_3D_H_
#define _TRANSFORMATION_3D_H_
#include<iostream>
#include<cstdio>
#include<cmath>
#include "matrix3d.h"
#include "projection.h"

using namespace std;

class transform3d{
    public:
        Matrix3D *p;
    transform3d(){p = nullptr;}
    ~transform3d(){
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
        p = new Matrix3D(n,4);
        float x,y,z;
        for(int i = 0; i < n; i++){
            printf("Point %d\nEnter x co-ordinate: ", i+1);
            cin>>x;
            cout<<"Enter y co-ordinate: ";
            cin>>y;
            cout<<"Enter z co-ordinate: ";
            cin>>z;            
            p->arr[i][0] = x;
            p->arr[i][1] = y;
            p->arr[i][2] = z; 
            p->arr[i][3] = 1; 
        }
        cout<<"Points matrix is:\n";
        p->printMatrix();
    }
    void setPoints(int n,float arr[][4]){
        if(p != nullptr){
            free(p);
        }
        p = new Matrix3D(n,4);
        p->setMatrix(arr);
    }
    void translate(){
        float tx, ty,tz;
        cout<<"Enter translation in x-axis: ";
        cin>>tx;
        cout<<"Enter translation in y-axis: ";
        cin>>ty;
        cout<<"Enter translation in z-axis: ";
        cin>>tz;

        float t[4][4] = {
            {1,0,0,0},
            {0,1,0,0},
            {0,0,1,0},
            {tx,ty,tz,1}         
        };
        Matrix3D trf(4,4);
        trf.setMatrix(t);
        cout<<"\nTransformation matrix:\n";
        trf.printMatrix();
        cout<<"\nOriginal points:\n";
        this->p->printMatrix();
        Matrix3D result = Matrix3D::multiply(this->p, trf);
        cout<<"\nTransformed points: \n";
        result.printMatrix();        
    }   
    void scale(){
        float sx, sy,sz;
        cout<<"Enter X-axis scaling factor: ";
        cin>>sx;
        cout<<"Enter Y-axis scaling factor: ";
        cin>>sy;
        cout<<"Enter Z-axis scaling factor: ";
        cin>>sz;
        
        float t[4][4] = {
            {sx,0,0,0},
            {0,sy,0,0},
            {0,0,sz,0},
            {0,0,0,1}         
        };
        Matrix3D trf(4,4);
        trf.setMatrix(t);
        cout<<"\nTransformation matrix:\n";
        trf.printMatrix();
        cout<<"\nOriginal points:\n";
        this->p->printMatrix();
        Matrix3D result = Matrix3D::multiply(this->p, trf);
        cout<<"\nTransformed points: \n";
        result.printMatrix();        
    }
    /*
        1. With respect to X axis
                     [  1  0    0    0]
        PointMatrix* [  0  cosT sinT 0]
                     [  0 -sinT cosT 0]
                     [  0  0    0    1]
        
        2. With respect to Y axis
                     [  cosT  0  -sinT 0]
        PointMatrix* [  0     0  1     0]
                     [  sinT  0  cosT  0]
                     [  0     0    0   1]

        3. With respect to Z axis
                     [  cosT sinT 0 0]
        PointMatrix* [ -sinT cosT 0 0]
                     [  0    0    0 0]
                     [  0    0    0 1]

    */

    void rotate(){
        float thetaR, thetaD;
        cout<<"Enter angle of rotation, in degrees";
        cin>>thetaD;
        thetaR = thetaD * 3.14159/180;
        float cosT = (float) cos(thetaR);
        float sinT = (float) sin(thetaR);
        float t[4][4] = {
            {1,0,0,0},
            {0,1,0,0},
            {0,0,1,0},
            {0,0,0,1}         
        };
        bool flag = true;
        while(flag){
            int choice;
            cout<<"\nRotate about:\n1.X-Axis\n2.Y-Axis\n3.Z-Axis: ";
            cin>>choice;
            switch (choice)
            {
                case 1:
                    t[1][1] = t[2][2] = cosT;
                    t[1][2] = -1*sinT;
                    t[2][1] = sinT;
                    flag = false;
                    break;
                case 2:
                    t[0][0] = t[2][2] = cosT;
                    t[0][2] = sinT;
                    t[2][0] = -1*sinT;
                    flag = false;
                    break;
                case 3:
                    t[0][0] = t[1][1] = cosT;
                    t[0][1] = -1*sinT;
                    t[1][0] = sinT;
                    flag = false;
                    break;
                default: cout<<"Invalid choice, try again";
                }
        }
        Matrix3D trf(4,4);
        trf.setMatrix(t);
        cout<<"\nTransformation matrix:\n";
        trf.printMatrix();
        cout<<"\nOriginal points:\n";
        this->p->printMatrix();
        Matrix3D result = Matrix3D::multiply(this->p, trf);
        cout<<"\nTransformed points: \n";
        result.printMatrix();        
    }
    void reflect(){
        float t[4][4] = {
            {1,0,0,0},
            {0,1,0,0},
            {0,0,1,0},
            {0,0,0,1}         
        };
        bool flag = true;
        while(flag){
            cout<<"\nReflect about:\n1.X-Axis\n2.Y-Axis\n3.Z-Axis: ";
            int choice;
            cin>>choice;
            switch (choice)
            {
                case 1:
                    t[1][1] = t[2][2] = -1;
                    flag = false;
                    break;
                case 2:
                    t[0][0] = t[2][2] = -1;
                    flag = false;
                    break;
                case 3:
                    t[0][0] = t[1][1] = -1;
                    flag = false;
                    break;
                default: cout<<"Invalid choice, try again";
                }
        }
        Matrix3D trf(4,4);
        trf.setMatrix(t);
        cout<<"\nTransformation matrix:\n";
        trf.printMatrix();
        cout<<"\nOriginal points:\n";
        this->p->printMatrix();
        Matrix3D result = Matrix3D::multiply(this->p, trf);
        cout<<"\nTransformed points: \n";
        result.printMatrix();       
    }
};

int execute_3d(){
    transform3d t;
    t.getPoints();
    Projection p(t.p); 
    while(true){
        cout<<"\nEnter your choice:\n";
        cout<<"1.Translate\n2.Scale\n3.Rotate\n4.Reflect\n5.Projection\n6.Show points\n7.Change points\n8.Exit\n: ";
        int choice;
        cin>>choice;
        switch(choice)
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
            p.exec();
        case 6:
            cout<<"\nPoints Matrix is:\n";
            t.p->printMatrix();
            break;
        case 7:
            t.getPoints();
            break;
        case 8:
            return 0;
        default:
            cout<<"\nInvalid choice. Please try again";
            break;
        }
    }
    return -1;
}
#endif