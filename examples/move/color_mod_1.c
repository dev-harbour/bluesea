/*
 *
 */

#include "bluesea.h"

static uint32_t Color( int col, int row );

int main( void )
{
   pBlueSea app;
   int mod, col, row;
   const char *c;

   app = bs_CreateWindow( 830, 450, "bs_DispOutAt( w, text, col, row, hexColor )" );

   bs_FreeType( app, "../../font/9x18.bdf" );

   while( ! bs_MainLoop( app ) && ! bs_GetKey( app, KEY_ESCAPE ) )
   {
      for( mod = 0; mod <= 3; mod++ )
      {
         bs_Begin( app );

            bs_Background( app, 0x006994 );

               for( row = 0; row <= 24; row++ )
               {
                  for( col = 0; col <= 91; col++ )
                  {
                     if(      col == 0  && row == 0 )  c = "┌";
                     else if( col == 0  && row == 24 ) c = "└";
                     else if( col == 0 )               c = "├";
                     else if( col == 91 && row == 0 )  c = "┐";
                     else if( col == 91 && row == 24 ) c = "┘";
                     else if( col == 91 )              c = "┤";
                     else if(              row == 0 )  c = "┬";
                     else if(              row == 24 ) c = "┴";
                     else                              c = "┼";

                     bs_DispOutAt( app, c, col, row, Color( col, row + mod ) );
                  }

               }

         bs_WaitEventsTimeout( app, 1.0 );
         bs_End( app );
      }
   }

   bs_CloseWindow( app );

   return 0;
}

static uint32_t Color( int col, int row )
{
   switch( (int) row % 4 * 10 + col % 4 )
   {
   case  2:
   case 11:
   case 20:
   case 33:
      return 0xffffff;
   case  0:
   case 13:
   case 22:
   case 31:
      return 0xff0000;
   }
   return 0x323232;
}
