/*
 *
 */

#include "bluesea.h"

int main( void )
{
   pBlueSea app;

   app = bs_CreateWindow( 720, 450, "良い一日。" );

   while( ! bs_MainLoop( app ) && ! bs_GetKey( app, KEY_ESCAPE ) )
   {
      bs_Begin( app );

         bs_Background( app, 0x006994 );

      bs_End( app );
   }

   bs_CloseWindow( app );

   return 0;
}
