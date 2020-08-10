#ifndef _PROJECTION_H
#define _PROJECTION_H
#include<iostream>
#include "matrix3d.h"
#include<cmath>
class Projection{
    private:
        Matrix3D *points;
        int orthographic(){
            cout<<"\nPARALLEL: ORTHOGRAPHIC PROJECTION***\n";
            Matrix3D trf(4,4);
            float t[][4]={
                {1,0,0,0},
                {0,1,0,0},
                {0,0,1,0},
                {0,0,0,1},
            };
            cout<<"Enter projection on:\n";
            cout<<"\n1.X=0 plane\n2.Y=0 plane\n3.Z=0 plane\n: ";
            int ortho;
            cin>>ortho;
            if(ortho == 1){
                t[0][0] = 0;
            }else if(ortho == 2){
                t[1][1] = 0;
            }else if(ortho == 3){
                t[2][2] = 0;
            }else{
                cout<<"Invalid choice";
                return 0;
            }
            trf.setMatrix(t);
            cout<<"\nTransformation matrix:\n";
            trf.printMatrix();
            cout<<"\nOriginal points:\n";
            this->points->printMatrix();
            Matrix3D result = Matrix3D::multiply(this->points, trf);
            cout<<"\nTransformed points: \n";
            result.printMatrix();
            return 0;
        }
        int oblique(){
            cout<<"\n***PARALLEL: OBLIQUE PROJECTION***\n";
            cout<<"***(Taking horizontal inclination angle = 30 degree)***\n";
            Matrix3D trf(4,4);
            float t[][4]={
                {1,0,0,0},
                {0,1,0,0},
                {0,0,1,0},
                {0,0,0,1},
            };
            cout<<"Enter your choice:\n";
            cout<<"\n1.Cavalier projection\n2.Cabinet projection\n: ";
            int ob;
            cin>>ob;
            if(ob == 1){
                t[2][0] = -0.866;
                t[2][1] = -0.5;
            }else if(ob == 2){
                t[2][0] = -0.433;
                t[2][1] = -0.25;
            }else{
                cout<<"Invalid choice";
                return 0;
            }
            trf.setMatrix(t);
            cout<<"\nTransformation matrix:\n";
            trf.printMatrix();
            cout<<"\nOriginal points:\n";
            this->points->printMatrix();
            Matrix3D result = Matrix3D::multiply(this->points, trf);
            cout<<"\nTransformed points: \n";
            result.printMatrix();
            return 0;
        }
        int axonometric(){
            cout<<"\nPARALLEL: AXONOMETRIC PROJECTION***\n";
            cout<<"***(Onto Z=0 plane)***\n";
            Matrix3D trf(4,4);
            float t[][4]={
                {1,0,0,0},
                {0,1,0,0},
                {0,0,1,0},
                {0,0,0,1},
            };
            cout<<"Enter your choice:\n";
            cout<<"\n1.Trimetric projection\n2.Dimetric projection\n3.Isometric projection\n: ";
            int axono;
            cin>>axono;
            if(axono == 1){
                t[2][2] = 0;
                int theta, phi;
                cout<<"Enter angle for first rotation: ";
                cin>>phi;
                cout<<"Enter angle for second rotation: ";
                cin>>theta;
                float sintheta;
                sintheta = sin(theta*3.14159/180);

                t[0][0] = cos(phi*3.14159/180);
                t[2][0] = sin(phi*3.14159/180); 
                
                t[0][1] = sintheta * t[2][0];
                t[1][1] = cos(theta*3.14159/180);
                t[2][1] = -1*sintheta*t[0][0];

            }else if(axono == 2){
                t[2][2] = 0;
                float fz,phi,theta,sintheta;
                cout<<"Enter foreshortening factor Fz:  ";
                cin>>fz;
                phi = fz / (float) sqrt(2 - fz*fz);
                theta = fz / (float) sqrt(2);
                cout<<"Angle for first rotation (phi): "<<phi<<" degree\n";
                cout<<"Angle for second rotation (theta): "<<theta<<" degree\n";

                sintheta = sin(theta*3.14159/180);

                t[0][0] = cos(phi*3.14159/180);
                t[2][0] = sin(phi*3.14159/180); 
                
                t[0][1] = sintheta * t[2][0];
                t[1][1] = cos(theta*3.14159/180);
                t[2][1] = -1*sintheta*t[0][0];


            }else if(axono == 3){
                t[2][2] = 0;
                cout<<"Taking Angle for first rotation (phi): -45 degree\n";
                cout<<"Taking Angle for second rotation (theta): 35.26 degree";
                t[0][0] = 0.707;
                t[2][0] = -0.707;
                
                t[0][1] = -0.408;
                t[1][1] =  0.816;
                t[2][1] = -0.408;
            }else{
                cout<<"Invalid choice";
                return 0;
            }
            trf.setMatrix(t);
            cout<<"\nTransformation matrix:\n";
            trf.printMatrix();
            cout<<"\nOriginal points:\n";
            this->points->printMatrix();
            Matrix3D result = Matrix3D::multiply(this->points, trf);
            cout<<"\nTransformed points: \n";
            result.printMatrix();
            return 0;
        }

        int parallel(){
            cout<<"\n***PARALLEL PROJECTION***\n";
            int choicep1;
            cout<<"Enter your choice:\n";
            cout<<"\n1.ORTHOGRAPHIC\n2.AXONOMETRIC\n3.OBLIQUE\n: ";
            cin>>choicep1;
            switch (choicep1)
            {
            case 1:
                orthographic();
                break;
            case 2:
                axonometric();
                break;
            case 3:
                oblique();
                break;
            default: cout<<"Invalid choice.";
                break;
            }
            return 0;
        }
        int perspective(){
            cout<<"\n***PERSPECTIVE PROJECTION***\n";
            cout<<"***(Onto Z=0 plane)***\n";
            cout<<"***(Taking p,q,r to be 0.1 in all 3 cases)***\n";
            Matrix3D trf(4,4);
            float t[][4]={
                {1,0,0,0},
                {0,1,0,0},
                {0,0,1,0},
                {0,0,0,1},
            };
            cout<<"Enter your choice:\n";
            cout<<"1.One point projection\n2.Two point projection\n3.Three point projection\n: ";
            int pers;
            cin>>pers;
            if(pers == 1){
                t[2][2] = 0;
                t[0][3] = 0.1;
            }else if(pers == 2){
                t[2][2] = 0;
                t[0][3] = 0.1;
                t[1][3] = 0.1;
            }else if(pers == 3){
                t[2][2] = 0;
                t[0][3] = 0.1;
                t[1][3] = 0.1;
                t[2][3] = 0.1;
            }else{
                cout<<"Invalid choice";
                return 0;
            }
            trf.setMatrix(t);
            cout<<"\nTransformation matrix:\n";
            trf.printMatrix();
            cout<<"\nOriginal points:\n";
            this->points->printMatrix();
            Matrix3D result = Matrix3D::multiply(this->points, trf);
            cout<<"\nTransformed points: \n";
            result.printMatrix();
            return 0;
        }
    public:
        int exec(){
            int choice;
            while(true){
                cout<<"\n\n Select the type of projection:\n";
                cout<<"1.Perspective\n2.Parallel\n3.Exit\n:";
                cin>>choice;
                switch (choice)
                {
                case 1:
                    perspective();
                    break;
                case 2:
                    parallel();
                    break;
                case 3:
                    return 0;
                default:
                    cout<<"Invalid choice, try again.";
                    break;
                }
            }
           return 0; 
        }
        Projection(Matrix3D *t){
            this->points = t;
        }
};


#endif