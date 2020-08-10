#ifndef _CURVES_H
#define _CURVES_H

#include<iostream>
#include "point.h"
#include<vector>
#include<cmath>
// #include<random>
using namespace std;

class Curve{
    private:
        vector<point<float>> control_points, points_to_plot;
        void get_control_points(){
            point<float> p;
            float x,y;
            cout<<"\nEnter control point: \n";
            for(int i =0 ; i < 4; i++){
                cout<<"Point "<<i+1<<":\n";
                p.enterPoint();
                control_points.push_back(p);
            }
        }

        void show_points(vector<point<float>> t){
            cout<<"\nControl points are: \n";
            for(int i = 0; i < t.size(); i++){
                t[i].printForMatrix();
            }
        }
            void generateDefaultControlPoints(){
                point<float> temp;
                temp.setPoint(100,100);
                control_points.push_back(temp);
                temp.setPoint(200,300);
                control_points.push_back(temp);
                temp.setPoint(400,300);
                control_points.push_back(temp);
                temp.setPoint(300,100);
                control_points.push_back(temp);

            }
    protected:        
        void plot_helper(bool random,bool showConvexHull){
            if(random){
                generateDefaultControlPoints();
            }else{
                get_control_points();
            }

            show_points(control_points);
            float x[4],y[4];
            
            for(int i = 0; i < control_points.size(); i++){
                x[i] = control_points[i].x;
                y[i] = control_points[i].y;
            }
            
            for(float t = 0; t<=1.0; t+=0.01){
                point<float> temp;
                temp.x = getQPolynomial(t, x);
                temp.y = getQPolynomial(t, y);
                points_to_plot.push_back(temp);    
            }

            cout<<"\nPoints for curve: \n";
            show_points(points_to_plot);
        }
        public:
            virtual float getQPolynomial(float t, float *arr) = 0;
            virtual void plot(bool random) = 0;
            Curve(){
            }
};

class Hermite : public Curve{
    public:
    Hermite(){
        cout<<"\nHERMITE CURVE IMPLEMENTATION\n";
    }

    float getQPolynomial(float t, float *arr){
        return (2*t*t*t - 3*t*t + 1)*arr[0] +
                (3*t*t - 2*t*t*t)*arr[1] + 
                (t*t*t - 2*t*t + t)*arr[2] +
                (t*t*t - t*t)*arr[3];
    }

    void plot(bool random){
        plot_helper(random,false);
    }

};

class Bezier : public Curve{
    public:
        Bezier(){
        cout<<"\nBEZIER CURVE IMPLEMENTATION\n";            
        }

        float getQPolynomial(float t, float *arr){
            return (1-t)*(1-t)*(1-t)*arr[0] + 
                        3*t*(1-t)*(1-t)*arr[1] + 
                            3*t*t*(1-t)*arr[2] + 
                            t*t*t*arr[3]; 
        }

    void plot(bool random){
        plot_helper(random,true);
    }


};


int execute_curve(){
    Curve *curve = nullptr;
    while(true){
        int choice;
        cout<<"\nEnter your choice:\n";
        cout<<"1.Hermite curve\n";
        cout<<"2.Bezier curve\n";
        cout<<"2.Exit\n: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            curve = new Hermite();
            curve->plot(false);
            break;
        case 2:
            curve = new Bezier();
            curve->plot(false);
            break;            
        case 3:
            if(curve != nullptr){
                free(curve);
            }
            return 0;
            break;

        default: 
            cout<<"Invalid choice. Please try again";
            break;
        }

    }
    return 0;
}

#endif