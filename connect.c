//
// Created by ayush on 8/15/19.
//

#include "connect.h"

Display * connect_to_server(char * display_name, int *screen, Window * root_window) {

//    Open the connection with the display (server).
    Display *display;
    display = XOpenDisplay((char *) NULL);

//    and test it
    if(display == (Display *) NULL) {
        fprintf(stderr, "Can't open the connection to the server [%s]\n", XDisplayName((char *) NULL));
        exit(1);
    }
//    Connection opened and tested
    //screen is the default screen of the display
    *screen = DefaultScreen(display);

    //get the root window ID
    //get the root window ID

    *root_window = RootWindow(display, *screen);

    return display;
}