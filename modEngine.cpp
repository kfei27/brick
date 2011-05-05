/*******************************************************************************
FILENAME:       modEngine.h
PROGRAMMER:     Goh Kin Fei
EMAIL:          kfei27 at gmail dot com

DESCRIPTION:
    Engine module.

ENVIRONMENT:

REVISION:
20110503        1.0     File creation.
*******************************************************************************/

#include "modEngine.h"

extern GLfloat draw::rotate;
extern GLfloat draw::col;
extern GLfloat draw::row;

int draw::shapeL(GLvoid)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear Screen And Depth Buffer
    glLoadIdentity();                           // Reset The Current Modelview Matrix
    glTranslatef(col, row, -15.0f);
    glRotatef(rotate, 0.0f, 0.0f, 1.0f);        // Rotate on the Z axis

    glColor3f(1.0f, 0.0f, 0.0f);                // Red
    brick(0.0f, 0.0f);

    glColor3f(0.0f, 1.0f, 0.0f);                // Green
    brick(2.0f, 0.0f);

    glColor3f(0.0f, 0.0f, 1.0f);                // Blue
    brick(0.0f, 2.0f);

    glColor3f(1.0f, 1.0f, 0.0f);                // Yellow
    brick(-4.0f, -2.0f);

    return TRUE;                                        // Everything Went OK
}

int draw::brick(GLfloat x, GLfloat y)
{
    glTranslatef( x, y, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f( 1.0f, 1.0f, 0.0f);          // Top Right Of The Quad (Front)
        glVertex3f(-1.0f, 1.0f, 0.0f);          // Top Left Of The Quad (Front)
        glVertex3f(-1.0f,-1.0f, 0.0f);          // Bottom Left Of The Quad (Front)
        glVertex3f( 1.0f,-1.0f, 0.0f);          // Bottom Right Of The Quad (Front)
    glEnd();

    return TRUE;                                        // Everything Went OK
}

