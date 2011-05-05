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

#ifndef _MODENGINE_H
#define _MODENGINE_H

#include "modOpenGL.h"

class draw
{
public:
    static int brick(GLfloat x, GLfloat y);
    static int shapeL(GLvoid);
    static GLfloat rotate;
    static GLfloat col;
    static GLfloat row;
private:
};

#endif
