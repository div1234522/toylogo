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
#include "gl_framework.hpp"

int depth = 7;

//The recursive function that'll draw all the upside down triangles
void subTriangle(int n, float x1, float y1, float x2, float y2, float x3, float y3)
{
    //Draw the 3 sides as black lines
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex3f(x1,  y1,  0.0f);
    glVertex3f(x2, y2,  0.0f);
    glVertex3f(x1,  y1,  0.0f);
    glVertex3f(x3,  y3,  0.0f);
    glVertex3f(x2,  y2,  0.0f);
    glVertex3f(x3,  y3,  0.0f);
    glEnd();
    
    //Calls itself 3 times with new corners, but only if the current number of recursions is smaller than the maximum depth
    if(n < depth)
    {
        //Smaller triangle 1
        subTriangle
        (
         n+1, //Number of recursions for the next call increased with 1
         (x1 + x2) / 2 + (x2 - x3) / 2, //x coordinate of first corner
         (y1 + y2) / 2 + (y2 - y3) / 2, //y coordinate of first corner
         (x1 + x2) / 2 + (x1 - x3) / 2, //x coordinate of second corner
         (y1 + y2) / 2 + (y1 - y3) / 2, //y coordinate of second corner
         (x1 + x2) / 2, //x coordinate of third corner
         (y1 + y2) / 2  //y coordinate of third corner
         );
        //Smaller triangle 2
        subTriangle
        (
         n+1, //Number of recursions for the next call increased with 1
         (x3 + x2) / 2 + (x2 - x1) / 2, //x coordinate of first corner
         (y3 + y2) / 2 + (y2 - y1) / 2, //y coordinate of first corner
         (x3 + x2) / 2 + (x3 - x1) / 2, //x coordinate of second corner
         (y3 + y2) / 2 + (y3 - y1) / 2, //y coordinate of second corner
         (x3 + x2) / 2, //x coordinate of third corner
         (y3 + y2) / 2  //y coordinate of third corner
         );
        //Smaller triangle 3
        subTriangle
        (
         n+1, //Number of recursions for the next call increased with 1
         (x1 + x3) / 2 + (x3 - x2) / 2, //x coordinate of first corner
         (y1 + y3) / 2 + (y3 - y2) / 2, //y coordinate of first corner
         (x1 + x3) / 2 + (x1 - x2) / 2, //x coordinate of second corner
         (y1 + y3) / 2 + (y1 - y2) / 2, //y coordinate of second corner
         (x1 + x3) / 2, //x coordinate of third corner
         (y1 + y3) / 2  //y coordinate of third corner
         );
    }
}

//Drawing a Sierpinski Triangle
void drawSierpinski(float x1, float y1, float x2, float y2, float x3, float y3)
{
    //Draw the 3 sides of the triangle as black lines
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex3f(x1,  y1,  0.0f);
    glVertex3f(x2,  y2,  0.0f);
    glVertex3f(x1,  y1,  0.0f);
    glVertex3f(x3,  y3,  0.0f);
    glVertex3f(x2,  y2,  0.0f);
    glVertex3f(x3,  y3,  0.0f);
    glEnd();
    
    //Call the recursive function that'll draw all the rest. The 3 corners of it are always the centers of sides, so they're averages
    subTriangle
    (
     1, //This represents the first recursion
     (x1 + x2) / 2, //x coordinate of first corner
     (y1 + y2) / 2, //y coordinate of first corner
     (x1 + x3) / 2, //x coordinate of second corner
     (y1 + y3) / 2, //y coordinate of second corner
     (x2 + x3) / 2, //x coordinate of third corner
     (y2 + y3) / 2  //y coordinate of third corner
     );
}

void render_drawing(turtle_t &turt)
{
    int h = 640, w = 480;
    drawSierpinski(10, h - 10, w - 10, h - 10, w / 2, 10);
}
