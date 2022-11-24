/*
 *
 */

#include "bluesea.h"

int main( void )
{
   pBlueSea app;

   app = bs_CreateWindow( 720, 450, "FreeType test" );

   bs_FreeType( app, "../../font/9x18.ttf" );

   while( ! bs_MainLoop( app ) && ! bs_GetKey( app, KEY_ESCAPE ) )
   {
      bs_Begin( app );

         bs_Background( app, 0xffffff );
         bs_Text( app, "Test", ( bs_WinWidth( app ) - 36 ) / 2, ( bs_WinHeight( app ) + 11 ) / 2, 0x000000 );

      bs_End( app );

      bs_WaitEvents( app );
   }

   bs_CloseWindow( app );

   return 0;
}
