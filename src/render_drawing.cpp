/*
 * CS475/CS675 - Computer Graphics
 *  ToyLOGO Assignment Base Code
 *
 * Copyright 2009-2014, Parag Chaudhuri, Department of CSE, IIT Bombay
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "render_drawing.hpp"
#include <cmath>

int depth = 5;

void subTriangle(turtle_t &turt, int n, float x1, float y1, float x2, float y2, float x3, float y3)
{
    turt.set_pos(x1,  y1);
    turt.set_dir(-60);
    double dis = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    turt.forward(dis);

    turt.set_pos(x2,  y2);
    turt.set_dir(60);
    dis = sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
    turt.forward(dis);
    
    turt.set_pos(x3,  y3);
    turt.set_dir(180);
    dis = sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));
    turt.forward(dis);
    
    if(n < depth)
    {
        subTriangle
        (
         turt,
         n+1,
         (x1 + x2) / 2 + (x1 - x3) / 2,
         (y1 + y2) / 2 + (y1 - y3) / 2,
         (x1 + x2) / 2 + (x2 - x3) / 2,
         (y1 + y2) / 2 + (y2 - y3) / 2,
         (x1 + x2) / 2,
         (y1 + y2) / 2 
         );
        
        subTriangle
        (
         turt,
         n+1, 
         (x3 + x2) / 2, 
         (y3 + y2) / 2, 
         (x3 + x2) / 2 + (x2 - x1) / 2, 
         (y3 + y2) / 2 + (y2 - y1) / 2,
         (x3 + x2) / 2 + (x3 - x1) / 2, 
         (y3 + y2) / 2 + (y3 - y1) / 2
         );
       
        subTriangle
        (
	 turt,
         n+1, 
         (x1 + x3) / 2 + (x1 - x2) / 2,
         (y1 + y3) / 2 + (y1 - y2) / 2,
         (x1 + x3) / 2,
         (y1 + y3) / 2,
         (x1 + x3) / 2 + (x3 - x2) / 2,
         (y1 + y3) / 2 + (y3 - y2) / 2
         );
    }
}

void drawSierpinski(turtle_t &turt, float x1, float y1, float x2, float y2, float x3, float y3)
{
	
    turt.reset();
    turt.clear();
    turt.set_col(1.0, 1.0, 1.0);

    turt.set_pos(x1,  y1);
    turt.set_dir(60);
    double dis = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    turt.forward(dis);

    turt.set_pos(x2,  y2);
    turt.set_dir(-60);
    dis = sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
    turt.forward(dis);
    
    turt.set_pos(x3,  y3);
    turt.set_dir(180);
    dis = sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));
    turt.forward(dis);

    
    subTriangle
    (
     turt,
     1, 
     (x1 + x2) / 2, 
     (y1 + y2) / 2, 
     (x1 + x3) / 2, 
     (y1 + y3) / 2, 
     (x2 + x3) / 2, 
     (y2 + y3) / 2  
     );
}

void render_drawing(turtle_t &turt)
{
    drawSierpinski(turt, -0.3, 0.0, 0.0, 0.5196, 0.3, 0.0);
}
