#include "connect.h"
#include "size_hints.h"
#include "wm_hints.h"
#include "window.h"


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
    width = 800;
    height = 800;
    window = open_window(display, root_window, x, y, width, height, BlackPixel(display, screen), WhitePixel(display, screen), ExposureMask, visual);

    set_standard_hints(display, window, argv[0], argv[0], x, y, height, width);

    XMapRaised(display, window);
    XFlush(display);

//    XGrabKeyboard(display, window, True, GrabModeAsync, GrabModeAsync, CurrentTime);


//    while (1);

    //event loop
    count = 0;
    while (count < 20)
    {
        XNextEvent(display, &event);
        if(event.type == Expose)
        {
            count++;
            printf("For Expose event %d,", count);
            printf("the area is: \n");
            printf("\tAt %d,%d," ,event.xexpose.x, event.xexpose.y);
            printf(" %d pixels wide, %d high\n", event.xexpose.width, event.xexpose.height);
        }
    }

    XCloseDisplay(display);
}