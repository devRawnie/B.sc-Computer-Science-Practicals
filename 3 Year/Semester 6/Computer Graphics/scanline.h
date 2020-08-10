#ifndef _SCANLINE_H
#define _SCANLINE_H
#include<iostream>
#include<graphics.h>
#include<vector>
#include "point.h"
#include<cmath>
#include<algorithm>
using namespace std;

class EdgeBucket{
    public:
        int yMax;
        float x_YMin, slopeInverse;
        EdgeBucket(int ymax, float x_ymin, float slope){
            yMax = ymax;
            x_YMin = x_ymin;
            slopeInverse = slope;
        }
        void show(){
            cout<<"|"<<yMax<<"|"<<x_YMin<<"|"<<slopeInverse<<"|->";
        }
};
bool comparator(EdgeBucket e1, EdgeBucket e2){
            return (e1.x_YMin<e2.x_YMin);
    }
class Scanline{
    private: 
        vector<point<int>> vertices;
        vector<EdgeBucket> *globalTable;
        int n_vertices;
        int Y_MAX;
        
        void getVertices(){
            cout<<"\nEnter number of vertices: ";
            cin>>n_vertices;
            cout<<"Enter vertices of the polygon:\n";
            point<int> temp;
            for(int i = 0; i < n_vertices; i++){
                cout<<"\nVertex "<<i+1<<endl;
                temp.enterPoint();
                vertices.push_back(temp);
                Y_MAX = max(Y_MAX, temp.y);
            }
            vertices.push_back(vertices.front());
        }

        void makeGlobalEdgeTable(){
            int y_min, y_max, x_ymin; 
            globalTable = new vector<EdgeBucket>[Y_MAX+1];
            for(int i = 1; i <= n_vertices; i++){
                if(vertices[i].y > vertices[i-1].y){
                    y_min = vertices[i-1].y;
                    x_ymin = vertices[i-1].x;
                    y_max = vertices[i].y;
                }else{
                    y_min = vertices[i].y;
                    x_ymin = vertices[i].x;
                    y_max = vertices[i-1].y;
                }
                float slopeInv = (float)(vertices[i].x - vertices[i-1].x) / (float)(vertices[i].y - vertices[i-1].y);
                if(!isinf(slopeInv)){
                    globalTable[y_min].push_back(EdgeBucket(y_max,(float) x_ymin, slopeInv));
                }
            }
        }
        void Line(EdgeBucket e1, EdgeBucket e2, int i){
            printf("Draw points from (%d,%d) to (%d,%d)\n",e1.x_YMin,i,e2.x_YMin,i);
            // line(
            //     (int)e1.x_YMin,
            //     i,
            //     (int)e2.x_YMin,
            //     i
            // );
        }
        void scanfill(){
            // int gd = DETECT, gm;
            // initgraph(&gd, &gm, NULL);
            vector<EdgeBucket> activeTable;
            for(int i = 0; i<= Y_MAX;i++){
                for(int j=0; j<activeTable.size();j++){
                    if(activeTable[j].yMax<=i){
                        activeTable.erase(activeTable.begin()+j);
                        j--;
                    }
                }

                for(int j = 0;j<globalTable[i].size();j++){
                    activeTable.push_back(globalTable[i][j]);
                }
                sort(activeTable.begin(), activeTable.end(), comparator);
                // setcolor(RED);
                for(int j=0;j<activeTable.size();j+=2){
                    Line(activeTable[j],activeTable[j+1], i);
                    activeTable[j].x_YMin += activeTable[j].slopeInverse;
                    activeTable[j+1].x_YMin += activeTable[j+1].slopeInverse;
                }
            }
            // getchar();
            // closegraph();
        }
        public:
            Scanline(){
                Y_MAX = 0;
                globalTable = nullptr;
            }

            void exec(){
                getVertices();
                makeGlobalEdgeTable();
                scanfill();
            }
};
void execute_scan_line(){
    Scanline l;
    l.exec();
}
#endif