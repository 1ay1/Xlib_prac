//
// Created by ayush on 8/20/19.
//

#ifndef UNTITLED3_LOADFONT_H
#define UNTITLED3_LOADFONT_H

#include <X11/Xlib.h>
#include <stdio.h>

XFontStruct *load_font(Display *display, GC *gc, char font_name[]);

#endif //UNTITLED3_LOADFONT_H
