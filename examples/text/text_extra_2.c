/*
 *
 */

#include "bluesea.h"

#define TEXTSIZE 36

int main( void )
{
   pBlueSea app;
   const char *text = "Text extra";
   int textWidth;
   int textHeight;

   app = bs_CreateWindow( 720, 450, text );

   bs_FreeType( app, "../../font/freemono/FreeMono.otf" );

   textWidth  = bs_TextWidth( app, text, TEXTSIZE );
   textHeight = bs_TextHeight( app, text, TEXTSIZE );

   while( ! bs_MainLoop( app ) && ! bs_GetKey( app, KEY_ESCAPE ) )
   {
      bs_Begin( app );

         bs_Background( app, 0xffffff );
         bs_TextEx( app, text, ( bs_WinWidth( app ) - textWidth ) / 2, ( bs_WinHeight( app ) + textHeight ) / 2, TEXTSIZE, 0x000000 );

      bs_End( app );

      bs_WaitEvents( app );
   }

   bs_CloseWindow( app );

   return 0;
}
