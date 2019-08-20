//
// Created by ayush on 8/20/19.
//

#include "loadfont.h"

XFontStruct *load_font(Display *display, GC *gc, char font_name[])
{
    XFontStruct *font_struct;

    font_struct = XLoadQueryFont(display, font_name);
    //set the gc too
    XSetFont(display, *gc, font_struct->fid);
    return font_struct;
}