//
// Created by clay on 16/08/19.
//

#include "window.h"
#include "size_hints.h"
#include "wm_hints.h"

Window open_window(Display *display, Window parent, int x, int y, int width, int height, unsigned long bordercolor,
                   unsigned long backcolor, unsigned long even_mask, Visual *visual)
{
    Window window;
    XSetWindowAttributes attributes;
    unsigned  long attr_mask;

    //set up window attributes before making window
    attributes.event_mask = even_mask;
    attributes.border_pixel = bordercolor;
    attributes.background_pixel = backcolor;
    attr_mask = CWEventMask | CWBorderPixel | CWBackPixel;

    //override the WM
//    attributes.override_redirect = True;
//    attr_mask |= CWOverrideRedirect;

    //done with the attributes, create the motherfucking window now
    window = XCreateWindow(display, parent, x, y, width, height, BORDER_WIDTH, CopyFromParent, InputOutput, visual, attr_mask, &attributes);

    return window;
}

void set_standard_hints(Display *display, Window window, char app_name[], char win_name[], int x, int y, int height, int width)
{
    set_size_hints(display, window, x, y, width, height);
    set_window_name(display, window, win_name);
    set_class_hints(display, window, app_name, APP_CLASS);
    set_wm_hints(display, window, NormalState);
}