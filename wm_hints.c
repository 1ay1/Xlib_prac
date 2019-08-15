//
// Created by ayush on 8/15/19.
//

#include "wm_hints.h"


void set_wm_hints(Display *display, Window window, int initial_state)
{
    XWMHints wm_hints;

    wm_hints.flags = InputHint | StateHint;

    //starting the window in iconic or normal state?

    wm_hints.initial_state = initial_state;

    //want keyboard input or not?
    wm_hints.input = True;

    //set

    XSetWMHints(display, window, &wm_hints);
}

void set_class_hints(Display *display, Window window, char *res_name, char *res_class)
{
    XClassHint class_hints;

    class_hints.res_class = res_class;
    class_hints.res_name = res_name;

    XSetClassHint(display, window, &class_hints);
}

void set_window_name(Display *display, Window window, char name[])
{
    XStoreName(display, window, name);
}