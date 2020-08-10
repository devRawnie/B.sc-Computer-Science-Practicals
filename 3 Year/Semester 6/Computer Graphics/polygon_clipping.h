#ifndef _POLYGON_CLIPPING_H
#define _POLYGON_CLIPPING_H
#include<iostream>
#include<vector>
#include "point.h"
#include<cmath>
class PolyClipping{
    private:
        int left, top, right, bottom;
        vector<point<float>> originalVertices; 
        vector<point<float>> clippedVertices; 
        int n_vertices;
        bool insidePolygon(point<float> pt){
            int x = (int) pt.x;
            int y = (int) pt.y;
            return  (
                x >= left &&
                x <= right &&
                y >= top &&
                y <= bottom
                );
        }
        // void plotPoly(vector<point<float>> v, int color, bool fill=false){
        //     int size = v.size()*2;
        //     int *p = new int[size];
        //     int k =0;
        //     for(int i= 0; i<v.size(); i++){
        //         p[k++] = (int) abs(v[i].x);
        //         p[k++] = (int) abs(v[i].y);
        //     }
        //     
        //     if(fill){
        //         fillpoly(n_vertices+1,p);
        //     }else{
        //         drawpoly(n_vertices+1, p);
        //     }
                
        // }
        void showVertices(vector<point<float>> v){
            if(!v.empty()){
                cout<<"\nVertices of the polygon are: ";
                for(int i= 0; i<v.size()-1; i++){
                    v[i].printForMatrix();
                }
            }else{
                cout<<"Polygon not clipped yet";
            }
        }
        void plotRectangle(){
            printf("Left: %d,Top: %d,Right: %d, Bottom: %d\n",left,top,right,bottom);
        }
        void getPolygonVertices(){
            cout<<"\nEnter number of vertices: ";
            cin>>n_vertices;
            cout<<"\nEnter vertices of the polygon: \n";
            point<float> temp;
            for(int i = 0 ; i < n_vertices; i++){
                cout<<"\nEnter vertex "<<i+1;
                temp.enterPoint();
                originalVertices.push_back(temp);
            }
            originalVertices.push_back(originalVertices.front());
        }
        void Line(point<float> a, point<float> b){
            int x1,y1,x2,y2;    
            x1 = (int) a.x;
            y1 = (int) a.y;
            x2 = (int) b.x;
            y2 = (int) b.y;
         }
        void clipPolygon(){
            point<float> point1 = originalVertices.front(), point2;
            for(int i =1; i <originalVertices.size(); i++){
                point2 = originalVertices[i];
                if(insidePolygon(point1)){
                    if(insidePolygon(point2)){
                        // both the points are inside, accept both
                        // clippedVertices.push_back(point1);
                        clippedVertices.push_back(point2);
                        // Line(point1,point2);
                    }else{
                        // line is going from inside the polygon to outside
                        point<float> intersection = getIntersectionPoint(point1,point2);
                        clippedVertices.push_back(intersection);
                        // Line(point1,intersection);
                    }
                }else{
                    if(insidePolygon(point2)){
                        //line is coming from outside the polygon to inside
                        point<float> intersection = getIntersectionPoint(point2,point1) ;
                        clippedVertices.push_back(intersection);
                        clippedVertices.push_back(point2);
                        // Line(point2,intersection);
                    }
                }
                point1 = point2;
            }
            clippedVertices.push_back(clippedVertices.front());
        }
        float getX(point<float> point1, point<float> point2, float y){
            float m = (point1.y - point2.y) / (point1.x - point2.x);
            float c = point1.y - m*point1.x;
            return (y-c)/m; 
        }
        float getY(point<float> point1, point<float> point2, float x){
            float m = (point1.y - point2.y) / (point1.x - point2.x);
            float c = point1.y - m*point1.x;
            return (m*x + c); 
        }
        point<float> getIntersectionPoint(point<float> p_in,point<float> p_out){
            point<float> intersection;
            if(p_out.x < left){
                intersection.setPoint(left, getY(p_in,p_out, (float) left));
            }
            else if(p_out.x > right){
                intersection.setPoint(right, getY(p_in,p_out, (float) right));
            }
            else if(p_out.y > bottom){
                intersection.setPoint(getX(p_in,p_out, (float) bottom), bottom);
            }
            else if(p_out.y < top){
                intersection.setPoint(getX(p_in,p_out, (float) top), top);
            }
            return intersection;
        }
    public:
        PolyClipping(int l = 200, int t = 200, int r = 500, int b =400){
            left=l;
            right=r;
            top=t;
            bottom=b;
        }
        void exec(){
            getPolygonVertices();
            showVertices(originalVertices);
            plotRectangle();
            // plotPoly(originalVertices, YELLOW);
            clipPolygon();
            showVertices(clippedVertices);
        }
};
void execute_polygon_clipping(){
    PolyClipping p;
    p.exec();
}
#endif