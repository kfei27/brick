/*******************************************************************************
FILENAME:       modOpenGL.h
PROGRAMMER:     Goh Kin Fei
EMAIL:          kfei27 at gmail dot com

DESCRIPTION:
    OpenGL module.

ENVIRONMENT:
    libopengl32.a libgdi32.a libglu32.a
*******************************************************************************/

#ifndef _MODOPENGL_H
#define _MODOPENGL_H

#include <windows.h>        // Header File For Windows
#include <gl\gl.h>          // Header File For The OpenGL32 Library
#include <gl\glu.h>         // Header File For The GLu32 Library
//#include <gl\glaux.h>     // Header File For The Glaux Library (glaux.lib)

extern HDC         hDC;             // Private GDI Device Context
extern HGLRC       hRC;             // Permanent Rendering Context
extern HWND        hWnd;            // Holds Our Window Handle
extern HINSTANCE   hInstance;       // Holds The Instance Of The Application

extern bool    keys[256];           // Array Used For The Keyboard Routine
extern bool    active;              // Window Active Flag Set To TRUE By Default
extern bool    fullscreen;          // Fullscreen Flag Set To Fullscreen Mode By Default
extern GLfloat rtri;                // Angle for the Triangle
extern GLfloat rquad;               // Angle for the Quad

#ifdef OFFICECFG
    #define SCRW 160
    #define SCRH 120
#else
    #define SCRW 640
    #define SCRH 480
#endif

GLvoid ReSizeGLScene(GLsizei width, GLsizei height);     // Resize And Initialize The GL Window
int InitGL(GLvoid);                                      // All Setup For OpenGL Goes Here
#ifdef TESTSCENE
int DrawGLScene(GLvoid);                                 // Here's Where We Do All The Drawing
#endif
GLvoid KillGLWindow(GLvoid);                             // Properly Kill The Window
BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);   // Declaration For WndProc

#endif

