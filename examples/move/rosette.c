/*
 *
 */

#include "bluesea.h"

int main( void )
{
   pBlueSea app;
   int x, y, radius = 100, speed1 = 1, speed2 = -1;
   int tmp_w = 0, tmp_h = 0;
   int i, nx, ny;

   app = bs_CreateWindow( 720, 450, "Rosette move" );

   while( ! bs_MainLoop( app ) && ! bs_GetKey( app, KEY_ESCAPE ) )
   {
      bs_Begin( app );

      if( tmp_w != bs_WinWidth( app ) || tmp_h != bs_WinHeight( app ) )
      {
         tmp_w = bs_WinWidth( app );
         tmp_h = bs_WinHeight( app );
         x = tmp_w / 2;
         y = tmp_h / 2;
      }
         bs_Background( app, 0x006994 );

         if( x <= 0 + radius * 2 ) speed1 = - speed1;
         if( y <= 0 + radius * 2 ) speed2 = - speed2;
         if( x >= tmp_w - radius * 2 ) speed1 = - speed1;
         if( y >= tmp_h - radius * 2 ) speed2 = - speed2;

         x += speed1;
         y += speed2;

         for( i = 0; i < 44; i++ )
         {
            nx = sin( i ) * radius + x;
            ny = cos( i ) * radius + y;
            bs_Circle( app, nx, ny, radius, 0x000000 );
         }

      bs_End( app );
   }

   bs_CloseWindow( app );

   return 0;
}
