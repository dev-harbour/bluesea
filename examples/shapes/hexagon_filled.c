/*
 *
 */

#include "bluesea.h"

int main( void )
{
   pBlueSea app;
   double a;
   int x, y;
   int r = 200;

   app = bs_CreateWindow( 720, 450, "Shape test" );

   while( ! bs_MainLoop( app ) && ! bs_GetKey( app, KEY_ESCAPE ) )
   {
      bs_Begin( app );

         bs_Background( app, 0x323232 );

         x = bs_WinWidth( app ) / 2;
         y = bs_WinHeight( app ) / 2;

         bs_HexagonFilled( app, x, y, r, 0xff0000 );

      bs_End( app );

      bs_WaitEvents( app );
   }

   bs_CloseWindow( app );

   return 0;
}
