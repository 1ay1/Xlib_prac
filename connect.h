//
// Created by ayush on 8/15/19.
//

#ifndef UNTITLED3_CONNECT_H
#define UNTITLED3_CONNECT_H

#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

Display * connect_to_server(char * display_name, int *screen, Window * root_window);

#endif //UNTITLED3_CONNECT_H
