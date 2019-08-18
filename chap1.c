#include "connect.h"
#include "size_hints.h"
#include "wm_hints.h"
#include "window.h"
#include <time.h>
#include <unistd.h>

//constant angles for archs
#define START_ANGLE 0
#define PATH_ANGLE 360*64

/* Code of GC(Graphics context).C*/
GC create_gc(Display * display, Drawable drawable, unsigned long forecolor, unsigned long backcolor)
{
    //create the GCValues structures
    XGCValues xgcvalues;
    GC gc;

    xgcvalues.foreground = forecolor;
    xgcvalues.background = backcolor;
    xgcvalues.line_width = 2;

    gc = XCreateGC(display, drawable, (GCForeground | GCBackground | GCLineWidth), &xgcvalues);

    return gc;
}


int main(int argc, char **argv)
{
    //connect to the display ( server)
    Display *display;
    //get the motherfucking window
    Window root_window, window;
    //get the screen of that display you are gonna open
    int screen;

    //get the size fucking hints
    int x, y , width, height;
    //visual, we will get that from the parent
    Visual *visual = CopyFromParent;
    //get the XEvent structure
    XEvent event;
    int count; //for the event loop

    //connect to the X Server
    display = connect_to_server((char *) NULL, &screen, &root_window);

    //create a window on the display, put the geometry
    x = 100;
    y = 100;
    width = 500;
    height = 500;
    window = open_window(display, root_window, x, y, width, height, BlackPixel(display, screen), WhitePixel(display, screen), ExposureMask, visual);

    set_standard_hints(display, window, argv[0], argv[0], x, y, height, width);

    //creating the gc for the window
    GC gc;
    gc = create_gc(display,  window, BlackPixel(display, screen), WhitePixel(display, screen));

    XMapRaised(display, window);
    XFlush(display);

//    XGrabKeyboard(display, window, True, GrabModeAsync, GrabModeAsync, CurrentTime);


//    while (1);

    //event loop
    Bool running = True;
    int arc_h = 100;
    int arc_w = 100;
    count = 0;
    while (running)
    {
        XNextEvent(display, &event);
        if(event.type == Expose)
        {
            for(int i = 0; i < 1000; i++)
            {
                XDrawLine(display, window, gc, rand()%400, rand()%400, rand()%400 +100, 100+rand()*400);
                usleep(100000);
                XSync(display, True);
            }
//            XDrawArc(display, window, gc, 100, 100, 400, 200, START_ANGLE, PATH_ANGLE);
            count++;
            printf("For Expose event %d,", count);
            printf("the area is: \n");
            printf("\tAt %d,%d," ,event.xexpose.x, event.xexpose.y);
            printf(" %d pixels wide, %d high\n", event.xexpose.width, event.xexpose.height);
        }
    }

    XCloseDisplay(display);
}