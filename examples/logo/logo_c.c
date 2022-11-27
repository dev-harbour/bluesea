/*
 *
 */

#include "bluesea.h"

int main( void )
{
   pBlueSea app;
   int x, y, x1, y1, x2, y2, w, h;
   double a;
   int r = 200;
   uint8_t i;

   app = bs_CreateWindow( 720, 450, "Logo C" );

   while( ! bs_MainLoop( app ) && ! bs_GetKey( app, KEY_ESCAPE ) )
   {
      bs_Begin( app );

         bs_Background( app, 0x530972 );

         x = bs_WinWidth( app ) / 2;
         y = bs_WinHeight( app ) / 2;

         a = 2 * M_PI / 6;

         bs_HexagonFilled( app, x, y, r, 0x5c6bbf );
         for( i = 0; i < 2; i++ )
         {
            x1 = x + r * cos( a * i + M_PI / 6 );
            y1 = y + r * sin( a * i + M_PI / 6 );
            x2 = x + r * cos( a * ( i + 1 ) + M_PI / 6 );
            y2 = y + r * sin( a * ( i + 1 ) + M_PI / 6 );
            bs_TriangleFilled( app, x, y, x1, y1, x2, y2, 0x283492 );
         }

         bs_CircleLineWidth( app, x, y, 100, 66, 0xffffff );

         x1 = x + r * cos( a * 5 + M_PI / 6 );
         y1 = y + r * sin( a * 5 + M_PI / 6 );
         x2 = x + r * cos( a * ( 5 + 1 ) + M_PI / 6 );
         y2 = y + r * sin( a * ( 5 + 1 ) + M_PI / 6 );
         bs_TriangleFilled( app, x, y, x1, y1, x2, y2, 0x3848aa );

      bs_End( app );

      bs_WaitEvents( app );
   }

   bs_CloseWindow( app );

   return 0;
}
