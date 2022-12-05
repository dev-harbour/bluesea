/*
 *
 */

#include "bluesea.h"

int main( void )
{
   pBlueSea app;
   const char *text = "おはようございます";

   app = bs_CreateWindow( 820, 450, text );

   bs_FreeType( app, "../../font/18x18ja.pcf" );

   while( ! bs_MainLoop( app ) && ! bs_GetKey( app, KEY_ESCAPE ) )
   {
      bs_Begin( app );

         bs_Background( app, 0x006994 );
         bs_Text( app, text, ( bs_WinWidth( app ) - 162 ) / 2, ( bs_WinHeight( app ) + 11 ) / 2, 0x000000 );

      bs_End( app );

      bs_WaitEvents( app );
   }

   bs_CloseWindow( app );

   return 0;
}
