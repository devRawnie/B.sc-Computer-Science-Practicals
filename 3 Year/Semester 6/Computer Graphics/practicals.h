#ifndef _PRACTICALS_H
#define _PRACTICALS_H

#include "dda.h"
#include "bresenham_line.h"
#include "circle.h"
#include "ellipse.h"
#include "line_clipping.h"
#include "polygon_clipping.h"
#include "scanline.h"
#include "transformation2d.h"
#include "transformation3d.h"
#include "curves.h"
void exec(){
    do{
        cout<<"\n\n\n***********Computer Graphics Practicals***********\n\n";
        cout<<"1.DDA Line Drawing Algorithm\n";
        cout<<"2.Bresenham's Line Drawing Algorithm\n";
        cout<<"3.Midpoint Circle Drawing Algorithm\n";
        cout<<"4.Midpoint Ellipse Drawing Algorithm\n";
        cout<<"5.Line Clipping using Cohen-Sutherland Algorithm\n";
        cout<<"6.Polygon Clipping using Sutherland-Hodgeman Algorithm\n";
        cout<<"7.Scan Line Fill Algorithm\n";
        cout<<"8.2D Transformations\n";
        cout<<"9.3D Transformations\n";
        cout<<"10. Hermite/Bezier Curve\n";
        cout<<"0.Exit\n";
        cout<<"Enter your choice: ";
        int ch;
        cin>>ch;
        switch(ch){
            case 0: exit(0);
            case 1: execute_dda();
                    break;
            case 2: execute_b();
                    break;
            case 3: execute_circle();
                    break;
            case 4: execute_ellipse();
                    break;                    
            case 5: execute_line_clipping();
                    break;
            case 6: execute_polygon_clipping();
                    break;                    
            case 7: execute_scan_line();
                    break;
            case 8: execute_2d();
                    break;                    
            case 9:
                    execute_3d();
                    break;
            case 10:
                    execute_curve();
                    break;    
            default:cout<<"\nInvalid Choice. Please try again\n";
        }
        
    }while(true);
}

#endif