/*******************************************************************************
FILENAME:       main.cpp
PROGRAMMER:     Goh Kin Fei
EMAIL:          kfei27 at gmail dot com

DESCRIPTION:
    Main implementation.

ENVIRONMENT:
    Cygwin

REVISION:
20110503        1.0     Started Brick Project.
*******************************************************************************/

#include "modOpenGL.h"
#include "modEngine.h"
#include "time.h"

int WINAPI WinMain( HINSTANCE   hInstance,          // Instance
                    HINSTANCE   hPrevInstance,      // Previous Instance
                    LPSTR       lpCmdLine,          // Command Line Parameters
                    int         nCmdShow)           // Window Show State
{
    MSG     msg;                                    // Windows Message Structure
    BOOL    quit=FALSE;                             // Bool Variable To Exit Loop
    time_t  now = 0;                                // Record time

    //FreeConsole();                                  // Detach mingw console

    // Ask The User Which Screen Mode They Prefer
    if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Brick",MB_YESNO|MB_ICONQUESTION)==IDNO)
    {
        fullscreen=FALSE;                           // Windowed Mode
    }

    // Create Our OpenGL Window
    if (!CreateGLWindow("Brick",SCRW,SCRH,16,fullscreen))
    {
        return 0;                                   // Quit If Window Was Not Created
    }

    while(!quit)                                    // Loop That Runs While quit=FALSE
    {
        now = time(NULL);
        if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))   // Is There A Message Waiting?
        {
            if (msg.message==WM_QUIT)               // Have We Received A Quit Message?
            {
                quit=TRUE;                          // If So quit=TRUE
            }
            else                                    // If Not, Deal With Window Messages
            {
                TranslateMessage(&msg);             // Translate The Message
                DispatchMessage(&msg);              // Dispatch The Message
            }
        }
        else                                        // If There Are No Messages
        {
            // Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
            if (active)                             // Program Active?
            {
                if (keys[VK_ESCAPE])                // Was ESC Pressed?
                {
                    quit=TRUE;                      // ESC Signalled A Quit
                }
                else                                // Not Time To Quit, Update Screen
                {
                    #ifdef TESTSCENE
                    DrawGLScene();                  // Draw The Scene
                    #else
                    draw::shapeL();
                    #endif
                    SwapBuffers(hDC);               // Swap Buffers (Double Buffering)
                }
            }

            if (keys[VK_F1])                        // Is F1 Being Pressed?
            {
                keys[VK_F1]=FALSE;                  // If So Make Key FALSE
                KillGLWindow();                     // Kill Our Current Window
                fullscreen=!fullscreen;             // Toggle Fullscreen / Windowed Mode
                // Recreate Our OpenGL Window
                if (!CreateGLWindow("Brick",SCRW,SCRH,16,fullscreen))
                {
                    return 0;                       // Quit If Window Was Not Created
                }
            }

            if (keys[VK_SPACE] | keys[VK_UP])
            {
                keys[VK_SPACE]=FALSE;                       // Debounce
                keys[VK_UP]=FALSE;

                draw::rotate += 90.0f;                      // Increase The Rotation Variable
                if(360.0f == draw::rotate)
                {
                    draw::rotate = 0.0f;
                }
            }

            if (keys[VK_DOWN])
            {
                keys[VK_DOWN]=FALSE;                    // Debounce
                draw::row -= 1.0f;                      // Increase The Rotation Variable
            }

            if (keys[VK_LEFT])
            {
                keys[VK_LEFT]=FALSE;                    // Debounce
                draw::col -= 1.0f;                      // Increase The Rotation Variable
            }

            if (keys[VK_RIGHT])
            {
                keys[VK_RIGHT]=FALSE;                   // Debounce
                draw::col += 1.0f;                      // Increase The Rotation Variable
            }

            if(1.0f <= difftime(time(NULL), now))       // Every sec.
            {
                draw::row -= 1.0f;                      // Increase The Rotation Variable
                now = 0;
            }
        }
    }

    // Shutdown
    KillGLWindow();                                 // Kill The Window
    return (msg.wParam);                            // Exit The Program
}

