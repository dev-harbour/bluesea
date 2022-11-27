/*
 *
 */

#include "bluesea.h"

int main( void )
{
   pBlueSea app;
   double a;
   int x, y, x1, y1, x2, y2;
   int color[] = { 0xffffff, 0xffff00, 0x00ffff, 0x00ff00, 0xff00ff, 0xff0000 };
   int r = 150;
   uint8_t i;

   app = bs_CreateWindow( 720, 450, "Shape test" );

   while( ! bs_MainLoop( app ) && ! bs_GetKey( app, KEY_ESCAPE ) )
   {
      bs_Begin( app );

         bs_Background( app, 0x323232 );

         x = bs_WinWidth( app ) / 2;
         y = bs_WinHeight( app ) / 2;

         a = 2 * M_PI / 6;

         for( i = 0; i < 6; i++ )
         {
            x1 = x + r * cos( a * i );
            y1 = y + r * sin( a * i );
            x2 = x + r * cos( a * ( i + 1 ) );
            y2 = y + r * sin( a * ( i + 1 ) );

            bs_TriangleFilled( app, x, y, x1, y1, x2, y2, color[ i ] );
         }

      bs_End( app );

      bs_WaitEvents( app );
   }

   bs_CloseWindow( app );

   return 0;
}
