# bluesea

Playground with graphics, with the use of [GLFW](https://www.glfw.org/) and [Cairo](https://gitlab.freedesktop.org/cairo/cairo).

### Getting Started

For more info see [getting started](examples/README.md).

``` c
#include "bluesea.h"

int main( void )
{
   pBlueSea app;

   app = bs_CreateWindow( 720, 450, "おはようございます" );

   while( ! bs_MainLoop( app ) && ! bs_GetKey( app, KEY_ESCAPE ) )
   {
      bs_Begin( app );

         bs_Background( app, 0x006994 );

      bs_End( app );
   }

   bs_CloseWindow( app );

   return 0;
}
```
