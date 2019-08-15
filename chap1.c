#include "connect.h"

void print_x_info(Display *dis, int screen)
{
    //server version and vendor release
    printf("%s version %d of the %s\n", ServerVendor(dis), VendorRelease(dis), "X Window System");

    //info on the protocol version and revision
    printf("X Protocol %d.%d\n", ProtocolVersion(dis), ProtocolRevision(dis));

    //depth
    int depth;
    depth = DefaultDepth(dis, screen);
    if(depth == 1) {
        printf("Color plane depth ...... %d (MONO)\n", depth);
    } else {
        printf("Color plane depth ... %d\n", depth);
    }


    //get the size of screen in pixels
    printf("Display Width ... %d pixels.\n", DisplayWidth(dis, screen));
    printf("Display Height ... %d pixels.\n", DisplayHeight(dis, screen));

    // Black and White preallocated codes

    printf("Black ....... %ld\n", BlackPixel(dis, screen));
    printf("White ....... %ld\n", WhitePixel(dis, screen));

    //get the name of the display usually unix:0

    char *len = malloc(10);
    gethostname(len, 10);
    printf("For the display [%s%s]\n", len  ,XDisplayName((char * )NULL));
}

int main()
{
    //connect to the server(display)
    Display *display;
    Window rootwindow;
    int screen;
    //use the connection function
    display = connect_to_server((char *)NULL, &screen, &rootwindow);


    /*get and print the info about the X server
     */

    print_x_info(display, screen);

    return 0;
}