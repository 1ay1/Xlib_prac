//
// Created by ayush on 8/15/19.
//

#ifndef UNTITLED3_WM_HINTS_H
#define UNTITLED3_WM_HINTS_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>

void set_wm_hints(Display *display, Window window, int initial_state);
void set_class_hints(Display *display, Window window, char *res_name, char *res_class);
void set_window_name(Display *display, Window window, char name[]);

#endif //UNTITLED3_WM_HINTS_H
