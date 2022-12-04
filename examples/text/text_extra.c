/*
 *
 */

#include "bluesea.h"

#define TEXTSIZE 18

int main( void )
{
   pBlueSea app;
   const char *text = "Text extra";
   int textWidth;
   int textHeight;

   app = bs_CreateWindow( 720, 450, text );

   bs_FreeType( app, "../../font/9x18.bdf" );

   textWidth  = bs_TextWidth( app, text, TEXTSIZE );
   textHeight = bs_TextHeight( app, text, TEXTSIZE );

   while( ! bs_MainLoop( app ) && ! bs_GetKey( app, KEY_ESCAPE ) )
   {
      bs_Begin( app );

         bs_Background( app, 0xffffff );
         bs_TextEx( app, text, ( bs_WinWidth( app ) - textWidth ) / 2, ( bs_WinHeight( app ) + 11 ) / 2, TEXTSIZE, 0x000000 );

      bs_End( app );

      bs_WaitEvents( app );
   }

   bs_CloseWindow( app );

   return 0;
}
