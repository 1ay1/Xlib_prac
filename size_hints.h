//
// Created by ayush on 8/15/19.
//

#ifndef UNTITLED3_SIZE_HINTS_H
#define UNTITLED3_SIZE_HINTS_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>

void set_size_hints(Display * display, Window window, int x, int y, int width, int height);
void fill_size_hints(int x, int y, int width, int height, XSizeHints *size_hints);

#endif //UNTITLED3_SIZE_HINTS_H
