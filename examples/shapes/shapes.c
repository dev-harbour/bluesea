/*
 *
 */

#include "bluesea.h"

int main( void )
{
   pBlueSea app;
   int x, y, w, h;
   size_t i;
   int color[] = { 0xffffff, 0xffff00, 0x00ffff, 0x00ff00, 0xff00ff, 0xff0000, 0x0000ff, 0x000000 };

   app = bs_CreateWindow( 720, 450, "Shape test" );

   while( ! bs_MainLoop( app ) && ! bs_GetKey( app, KEY_ESCAPE ) )
   {
      bs_Begin( app );

         bs_Background( app, 0x808080 );

         x = 0, y = 0, w = 0, h = bs_WinHeight( app );
         for( i = 1; i < bs_WinWidth( app ); i++ )
         {
            bs_LineS( app, x += 20, y, w += 20, h, 0xffffff );
         }

         x = 0, y = 0, w = bs_WinWidth( app ), h = 0;
         for( i = 0; i < bs_WinHeight( app ); i++ )
         {
            bs_LineS( app, x, y += 20, w, h += 20, 0xffffff );
         }

         x = 60;
         for( i = 0; i < 8; i++ )
         {
            bs_RectFilled( app, x += 60, 120, 60, 120, NULL, color[ i ] );
         }

      bs_End( app );
   }

   bs_CloseWindow( app );

   return 0;
}
