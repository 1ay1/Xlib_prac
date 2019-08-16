//
// Created by clay on 16/08/19.
//

#ifndef UNTITLED3_WINDOW_H
#define UNTITLED3_WINDOW_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#define BORDER_WIDTH 2
#define APP_CLASS "Examples"


Window open_window(Display *display, Window parent, int x, int y, int width, int height, unsigned long bordercolor,
                   unsigned long backcolor, unsigned long even_mask, Visual *visual);
void set_standard_hints(Display *display, Window window, char app_name[], char win_name[], int x, int y, int height, int width);


#endif //UNTITLED3_WINDOW_H
