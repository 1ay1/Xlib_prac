//
// Created by ayush on 8/15/19.
//

#include "size_hints.h"

void set_size_hints(Display * display, Window window, int x, int y, int width, int height)
{
    //create the size hint structure
    XSizeHints size_hints;

    //get the hint values from the other function
    fill_size_hints(x, y, width, height, &size_hints);

    //size_hints structure is filled with the size hints now

    //set the size hints now
    XSetWMNormalHints(display, window, &size_hints);
//    XSetSizeHints(display, window, &size_hints);
}

//the "other function" called fill_size_hints
void fill_size_hints(int x, int y, int width, int height, XSizeHints *size_hints)
{
    //USPosition
    size_hints->x = x;
    size_hints->y = y;
    //USSize
    size_hints->height = height;
    size_hints->width = width;
    //PMinSize
    size_hints->min_height = height;
    size_hints->min_width = width;
    //PbaseSize
    size_hints->base_width = width;
    size_hints->base_height = height;
    //Now set what you did
    size_hints->flags = USPosition | USSize | PMinSize | PBaseSize;
}