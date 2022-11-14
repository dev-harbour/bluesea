/*
 *
 */
#include "bluesea.h"

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
// static functions
static void cursor_position_callback( GLFWwindow *window, double x, double y )
{
   pBlueSea s_w = glfwGetWindowUserPointer( window );

   s_w->cursorX = x;
   s_w->cursorY = y;
}

static void key_callback( GLFWwindow *window, int key, int scancode, int action, int mods )
{
   pBlueSea s_w = glfwGetWindowUserPointer( window );

   s_w->keyKey      = key;
   s_w->keyScancode = scancode;
   s_w->keyAction   = action;
   s_w->keyMods     = mods;
}

static void mouse_button_callback( GLFWwindow *window, int button, int action, int mods )
{
   pBlueSea s_w = glfwGetWindowUserPointer( window );

   s_w->mouseButton = button;
   s_w->mouseAction = action;
   s_w->mouseMods   = mods;
}

static void window_maximize_callback( GLFWwindow *window, int maximized )
{
   pBlueSea s_w = glfwGetWindowUserPointer( window );

   s_w->winMaximized = maximized;
}

static void hex_to_rgb( cairo_t *cr, uint32_t hexColor )
{
   double r, g, b;
   r = ( ( hexColor >> 16 ) & 0xFF ) / 255.0;
   g = ( ( hexColor >> 8  ) & 0xFF ) / 255.0;
   b = (   hexColor         & 0xFF ) / 255.0;

   cairo_set_source_rgba( cr, r, g, b, 1.0 );
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
// API functions
pBlueSea bs_CreateWindow( int width, int height, const char *title )
{
   pBlueSea w;

   if( ! glfwInit() )
   {
      exit( EXIT_FAILURE );
   }

   glfwWindowHint( GLFW_CLIENT_API, GLFW_NO_API );

   w = calloc( 1, sizeof( BlueSea ) );

   w->width  = width;
   w->height = height;
   w->title  = title;
   w->tmp_width  = 0;
   w->tmp_height = 0;

   w->window = glfwCreateWindow( w->width, w->height, title, NULL, NULL );
   if( ! w->window )
   {
      free( w );
      glfwTerminate();
      exit( EXIT_FAILURE );
   }
   glfwMakeContextCurrent( w->window );
   glfwSetWindowUserPointer( w->window, w );

   glfwSetCursorPosCallback( w->window, cursor_position_callback );
   glfwSetKeyCallback( w->window, key_callback );
   glfwSetMouseButtonCallback( w->window, mouse_button_callback );
   glfwSetWindowMaximizeCallback( w->window, window_maximize_callback );

   glfwSetWindowSizeLimits( w->window, w->width, w->height, GLFW_DONT_CARE , GLFW_DONT_CARE );

#if defined( GLFW_EXPOSE_NATIVE_WIN32 )
   w->dc = GetDC( glfwGetWin32Window( w->window ) );
#endif
#if defined( GLFW_EXPOSE_NATIVE_X11 )
   w->xd = glfwGetX11Display();
   w->sf = cairo_xlib_surface_create( w->xd, glfwGetX11Window( w->window ), DefaultVisual( w->xd, DefaultScreen( w->xd ) ), w->width, w->height );
   w->cr = cairo_create( w->sf );
#endif

   return w;
}

bool bs_MainLoop( pBlueSea w )
{
   w->closeFlag = glfwWindowShouldClose( w->window );
   glfwSetWindowShouldClose( w->window, GLFW_FALSE );

   return w->closeFlag;
}

bool bs_CloseWindow( pBlueSea w )
{
   glfwDestroyWindow( w->window );
   free( w );
   glfwTerminate();

   exit( EXIT_SUCCESS );
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
void begin_drawing( pBlueSea w )
{
   glfwGetFramebufferSize( w->window, &w->width, &w->height );

#if defined( GLFW_EXPOSE_NATIVE_WIN32 )
   if( w->tmp_width != w->width || w->tmp_height != w->height )
   {
      w->sf = cairo_win32_surface_create_with_format( w->dc, CAIRO_FORMAT_ARGB32 );
      w->cr = cairo_create( w->sf );
      w->tmp_width  = w->width;
      w->tmp_height = w->height;
   }
#endif
#if defined( GLFW_EXPOSE_NATIVE_X11 )
   cairo_xlib_surface_set_size( w->sf, w->width, w->height );
#endif

   cairo_push_group( w->cr );

   hex_to_rgb( w->cr, w->background );
   cairo_paint ( w->cr );
}

void end_drawing( pBlueSea w )
{
   cairo_pop_group_to_source( w->cr );
   cairo_paint( w->cr );
   cairo_surface_flush( w->sf );

   glfwWaitEvents();
}

int cairo_primitive( pBlueSea w, iCairo type, int par1, int par2, int par3, int par4, int par5, int par6, int par7 )
{
   int ret = 1;

   switch( type )
   {
      case CAIRO_ARC:
         break;
      case CAIRO_ARC_FILLED:

         break;
      case CAIRO_BACKGROUND:

         w->background = par1;
         break;
      case CAIRO_CIRCLE:

         break;
      case CAIRO_CIRCLE_FILLED:

         break;
      case CAIRO_CURVE:

         break;
      case CAIRO_GETPIXEL:

         break;
      case CAIRO_IMAGE:

         break;
      case CAIRO_LINE:

         hex_to_rgb( w->cr, par5 );
         cairo_set_line_width( w->cr, 1.0 );
         cairo_move_to( w->cr, par1, par2 );
         cairo_line_to( w->cr, par3, par4 );
         cairo_stroke( w->cr );
         break;

      case CAIRO_RGBTODEC:

         ret = ( ( par1 & 0xff ) << 16 ) + ( ( par2 & 0xff ) << 8 ) + ( par3 & 0xff );
         break;

      case CAIRO_POLYGON:

         break;
      case CAIRO_POLYGON_FILLED:

         break;
      case CAIRO_POLYLINE:

         break;
      case CAIRO_PUTPIXEL:

         hex_to_rgb( w->cr, par3 );
         cairo_set_line_width( w->cr, 1.0 );
         cairo_rectangle( w->cr, par1, par2, 1.0, 1.0 );
         cairo_fill( w->cr );
         break;

      case CAIRO_RECT:

         hex_to_rgb( w->cr, par6 );
         cairo_set_line_width( w->cr, 1.0 );
         if( par5 == 0 )
         {
            cairo_rectangle( w->cr, par1, par2, par3, par4 );
         }
         else
         {
            cairo_new_sub_path( w->cr );
            cairo_arc( w->cr, par1 + par5, par2 + par5, par5, M_PI, 3 * M_PI / 2 );
            cairo_arc( w->cr, par1 + par3 - par5, par2 + par5, par5, 3 * M_PI / 2, 2 * M_PI );
            cairo_arc( w->cr, par1 + par3 - par5, par2 + par4 - par5, par5, 0, M_PI / 2 );
            cairo_arc( w->cr, par1 + par5, par2 + par4 - par5, par5, M_PI / 2, M_PI );
            cairo_close_path( w->cr );
         }
         cairo_stroke( w->cr );
         break;

      case CAIRO_RECT_FILLED:

         hex_to_rgb( w->cr, par6 );
         cairo_set_line_width( w->cr, 1.0 );
         if( par5 == 0 )
         {
            cairo_rectangle( w->cr, par1, par2, par3, par4 );
         }
         else
         {
            cairo_new_sub_path( w->cr );
            cairo_arc( w->cr, par1 + par5, par2 + par5, par5, M_PI, 3 * M_PI / 2 );
            cairo_arc( w->cr, par1 + par3 - par5, par2 + par5, par5, 3 * M_PI / 2, 2 * M_PI );
            cairo_arc( w->cr, par1 + par3 - par5, par2 + par4 - par5, par5, 0, M_PI / 2 );
            cairo_arc( w->cr, par1 + par5, par2 + par4 - par5, par5, M_PI / 2, M_PI );
            cairo_close_path( w->cr );
         }
         cairo_fill( w->cr );
         break;

      case CAIRO_RECT_MULTI_COLOR:

         break;
      case CAIRO_TRIANGLE:

         hex_to_rgb( w->cr, par7 );
         cairo_set_line_width( w->cr, 1.0 );
         cairo_move_to( w->cr, par1, par2 );
         cairo_line_to( w->cr, par3, par4 );
         cairo_line_to( w->cr, par5, par6 );
         cairo_close_path( w->cr );
         cairo_stroke( w->cr );
         break;

      case CAIRO_TRIANGLE_FILLED:

         hex_to_rgb( w->cr, par7 );
         cairo_set_line_width( w->cr, 1.0 );
         cairo_move_to( w->cr, par1, par2 );
         cairo_line_to( w->cr, par3, par4 );
         cairo_line_to( w->cr, par5, par6 );
         cairo_close_path( w->cr );
         cairo_fill( w->cr );
         break;

      default:
         return 0;
   }
   return ret;
}

void cairo_text( pBlueSea w, int x, int y, const char *text, int color )
{
   cairo_select_font_face( w->cr, "FreeMono", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL );
   cairo_set_font_size( w->cr, 18 );
   hex_to_rgb( w->cr, color );
   cairo_move_to( w->cr, x, y );
   cairo_show_text( w->cr, text );
}

int glfw_functions( pBlueSea w, iGlfw type, int par1 )
{
   int ret = 1;

   switch( type )
   {
   case GLFW_GETKEY:

      ret = ( w->keyKey == par1 ) == GLFW_PRESS ? T : F;
      break;

   case GLFW_GETMOUSEBUTTON:

      ret = ( w->mouseButton == par1 ) == GLFW_PRESS ? T : F;
      break;

   case GLFW_WINDOWWIDTH:

      ret = w->width;
      break;

   case GLFW_WINDOWHEIGHT:

      ret = w->height;
      break;

   case GLFW_WINMAXIMIZED:

      ret = w->winMaximized;
      break;

   default:

      return 0;
   }

   return ret;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
