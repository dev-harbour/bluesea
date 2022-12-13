/*
 *
 */

#ifndef BLUESEA_H_
#define BLUESEA_H_

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <cairo/cairo.h>
#include <cairo/cairo-ft.h>

#include <freetype2/freetype/freetype.h>

#if defined( GLFW_EXPOSE_NATIVE_WIN32 )
   #include <cairo/cairo-win32.h>
#endif
#if defined( GLFW_EXPOSE_NATIVE_X11 )
   #include <cairo/cairo-xlib.h>
#endif

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
// tokens
#define KEY_UNKNOWN            -1

/* Printable keys */
#define KEY_SPACE              32
#define KEY_APOSTROPHE         39  /* ' */
#define KEY_COMMA              44  /* , */
#define KEY_MINUS              45  /* - */
#define KEY_PERIOD             46  /* . */
#define KEY_SLASH              47  /* / */
#define KEY_0                  48
#define KEY_1                  49
#define KEY_2                  50
#define KEY_3                  51
#define KEY_4                  52
#define KEY_5                  53
#define KEY_6                  54
#define KEY_7                  55
#define KEY_8                  56
#define KEY_9                  57
#define KEY_SEMICOLON          59  /* ; */
#define KEY_EQUAL              61  /* = */
#define KEY_A                  65
#define KEY_B                  66
#define KEY_C                  67
#define KEY_D                  68
#define KEY_E                  69
#define KEY_F                  70
#define KEY_G                  71
#define KEY_H                  72
#define KEY_I                  73
#define KEY_J                  74
#define KEY_K                  75
#define KEY_L                  76
#define KEY_M                  77
#define KEY_N                  78
#define KEY_O                  79
#define KEY_P                  80
#define KEY_Q                  81
#define KEY_R                  82
#define KEY_S                  83
#define KEY_T                  84
#define KEY_U                  85
#define KEY_V                  86
#define KEY_W                  87
#define KEY_X                  88
#define KEY_Y                  89
#define KEY_Z                  90
#define KEY_LEFT_BRACKET       91  /* [ */
#define KEY_BACKSLASH          92  /* \ */
#define KEY_RIGHT_BRACKET      93  /* ] */
#define KEY_GRAVE_ACCENT       96  /* ` */
#define KEY_WORLD_1            161 /* non-US #1 */
#define KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define KEY_ESCAPE             256
#define KEY_ENTER              257
#define KEY_TAB                258
#define KEY_BACKSPACE          259
#define KEY_INSERT             260
#define KEY_DELETE             261
#define KEY_RIGHT              262
#define KEY_LEFT               263
#define KEY_DOWN               264
#define KEY_UP                 265
#define KEY_PAGE_UP            266
#define KEY_PAGE_DOWN          267
#define KEY_HOME               268
#define KEY_END                269
#define KEY_CAPS_LOCK          280
#define KEY_SCROLL_LOCK        281
#define KEY_NUM_LOCK           282
#define KEY_PRINT_SCREEN       283
#define KEY_PAUSE              284
#define KEY_F1                 290
#define KEY_F2                 291
#define KEY_F3                 292
#define KEY_F4                 293
#define KEY_F5                 294
#define KEY_F6                 295
#define KEY_F7                 296
#define KEY_F8                 297
#define KEY_F9                 298
#define KEY_F10                299
#define KEY_F11                300
#define KEY_F12                301
#define KEY_F13                302
#define KEY_F14                303
#define KEY_F15                304
#define KEY_F16                305
#define KEY_F17                306
#define KEY_F18                307
#define KEY_F19                308
#define KEY_F20                309
#define KEY_F21                310
#define KEY_F22                311
#define KEY_F23                312
#define KEY_F24                313
#define KEY_F25                314
#define KEY_KP_0               320
#define KEY_KP_1               321
#define KEY_KP_2               322
#define KEY_KP_3               323
#define KEY_KP_4               324
#define KEY_KP_5               325
#define KEY_KP_6               326
#define KEY_KP_7               327
#define KEY_KP_8               328
#define KEY_KP_9               329
#define KEY_KP_DECIMAL         330
#define KEY_KP_DIVIDE          331
#define KEY_KP_MULTIPLY        332
#define KEY_KP_SUBTRACT        333
#define KEY_KP_ADD             334
#define KEY_KP_ENTER           335
#define KEY_KP_EQUAL           336
#define KEY_LEFT_SHIFT         340
#define KEY_LEFT_CONTROL       341
#define KEY_LEFT_ALT           342
#define KEY_LEFT_SUPER         343
#define KEY_RIGHT_SHIFT        344
#define KEY_RIGHT_CONTROL      345
#define KEY_RIGHT_ALT          346
#define KEY_RIGHT_SUPER        347
#define KEY_MENU               348

#define KEY_LAST               KEY_MENU

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
// types

typedef enum iCairo
{
   CAIRO,
   CAIRO_ARC,
   CAIRO_ARC_FILLED,
   CAIRO_BACKGROUND,
   CAIRO_CIRCLE,
   CAIRO_CIRCLE_FILLED,
   CAIRO_CIRCLELINEWIDTH,
   CAIRO_CURVE,
   CAIRO_ELLIPSE,
   CAIRO_ELLIPSE_FILLED,
   CAIRO_GETPIXEL,
   CAIRO_HEXAGON,
   CAIRO_HEXAGON_FILLED,
   CAIRO_IMAGE,
   CAIRO_LINE,
   CAIRO_LINES,
   CAIRO_RGBTODEC,
   CAIRO_POLYGON,
   CAIRO_POLYGON_FILLED,
   CAIRO_POLYLINE,
   CAIRO_PUTPIXEL,
   CAIRO_RECT,
   CAIRO_RECTS,
   CAIRO_RECT_FILLED,
   CAIRO_RECT_MULTI_COLOR,
   CAIRO_TRIANGLE,
   CAIRO_TRIANGLE_FILLED,
   SIZE_OF_CAIRO
} iCairo;

typedef enum iText
{
   TEXT,
   TEXT_FREE_TYPE,
   TEXT_CONST,
   TEXT_EXTRA,
   TEXT_DISPOUTAT,
   TEXT_WIDTH,
   TEXT_HEIGHT,
   TEXT_WINDOWTITLE,
   SIZE_OF_TEXT
} iText;

typedef enum iGlfw
{
   GLFW,
   GLFW_GET_KEY,
   GLFW_GET_MOUSEBUTTON,
   GLFW_WIN_WIDTH,
   GLFW_WIN_HEIGHT,
   GLFW_WIN_MAXCOL,
   GLFW_WIN_MAXROW,
   GLFW_WIN_MAXIMIZED,
   GLFW_POLLEVENTS,
   GLFW_WAITEVENTS,
   GLFW_WAITEVENTSTIMEOUT,
   SIZE_OF_GLFW
} iGlfw;

typedef enum bool
{
   F = 0,
   T = ( ! 0 )
} bool;

typedef struct _BlueSea
{
   GLFWwindow      *window;      // handle of the created window
   int              width;       // desired width, in screen coordinates, of the window
   int              height;      // desired height, in screen coordinates
   int              tmp_width;
   int              tmp_height;
   const char      *title;       // initial, UTF-8 encoded window title
   bool             closeFlag;   // returns the value of the close flag of the specified window
   // cursor
   double           cursorX;     // new cursor x-coordinate, relative to the left edge of the content area
   double           cursorY;     // new cursor y-coordinate, relative to the top edge of the content area
   // key
   int              keyKey;      // the keyboard key that was pressed or released
   int              keyScancode; // the system-specific scancode of the key
   int              keyAction;   // GLFW_PRESS, GLFW_RELEASE or GLFW_REPEAT. Future releases may add more actions
   int              keyMods;     // bit field describing which modifier keys were held down
   // mouse button
   int              mouseButton; // mouse button that was pressed or released
   int              mouseAction; // one of GLFW_PRESS or GLFW_RELEASE, future releases may add more actions
   int              mouseMods;   // bit field describing which modifier keys were held down
   // window maximized
   int              winMaximized;// GLFW_TRUE if the window was maximized, or GLFW_FALSE if it was restored
   // color
   int              background;
   // cairo
   cairo_surface_t     *sf;
   cairo_t             *cr;
   cairo_font_face_t   *ff;
   cairo_text_extents_t te;
   // FreeType
   FT_Library           library;
   FT_Face              face;
   //---
#if defined( GLFW_EXPOSE_NATIVE_WIN32 )
   HDC dc;
#endif
#if defined( GLFW_EXPOSE_NATIVE_X11 )
   Display *xd;
#endif
} BlueSea, *pBlueSea;

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
// API functions
pBlueSea bs_CreateWindow( int width, int height, const char *title );
bool bs_MainLoop( pBlueSea w );
bool bs_CloseWindow( pBlueSea w );

//---
void begin_drawing( pBlueSea w );
void end_drawing( pBlueSea w );
int  cairo_functions();
int  text_functions();
int  glfw_functions();

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
// macros
#define MAX( a, b ) ( ( a ) < ( b ) ? ( b ) : ( a ) )
#define MIN( a, b ) ( ( a ) < ( b ) ? ( a ) : ( b ) )
#define UNUSED( n ) ( ( void )( n ) )
#define LEN( n ) ( sizeof( n ) / sizeof( n )[ 0 ] )

#define bs_Begin( w ) do { begin_drawing( w )
#define bs_End( w ) end_drawing( w ); } while( 0 )

// #define CAIRO_ARC
// #define CAIRO_ARC_FILLED,
#define bs_Background( w, hexColor )                               cairo_functions( w, CAIRO_BACKGROUND, hexColor )
#define bs_Circle( w, x, y, radius, hexColor )                     cairo_functions( w, CAIRO_CIRCLE, x, y, radius, hexColor )
#define bs_CircleFilled( w, x, y, radius, hexColor )               cairo_functions( w, CAIRO_CIRCLE_FILLED, x, y, radius, hexColor )
#define bs_CircleLineWidth( w, x, y, radius, lineWidth, hexColor ) cairo_functions( w, CAIRO_CIRCLELINEWIDTH, x, y, radius, lineWidth, hexColor )
// #define CAIRO_CURVE,
// #define CAIRO_GETPIXEL,
#define bs_Hexagon( w, x, y, radius, hexColor )                    cairo_functions( w, CAIRO_HEXAGON, x, y, radius, hexColor )
#define bs_HexagonFilled( w, x, y, radius, hexColor )              cairo_functions( w, CAIRO_HEXAGON_FILLED, x, y, radius, hexColor )
// #define CAIRO_IMAGE,
#define bs_Line( w, x, y, width, height, hexColor )                cairo_functions( w, CAIRO_LINE, x, y, width, height, hexColor )
#define bs_LineS( w, x, y, width, height, hexColor )               cairo_functions( w, CAIRO_LINES, x, y, width, height, hexColor )
#define bs_RGBToDec( w, r, g, b )                                  cairo_functions( w, CAIRO_RGBTODEC, r, g, b )
// #define CAIRO_POLYGON,
// #define CAIRO_POLYGON_FILLED,
// #define CAIRO_POLYLINE,
#define bs_PutPixel( w, x, y, hexColor )                           cairo_functions( w, CAIRO_PUTPIXEL, x, y, hexColor )
#define bs_Rect( w, x, y, width, height, radius, hexColor )        cairo_functions( w, CAIRO_RECT, x, y, width, height, radius, hexColor )
#define bs_RectS( w, x, y, width, height, radius, hexColor )       cairo_functions( w, CAIRO_RECTS, x, y, width, height, radius, hexColor )
#define bs_RectFilled( w, x, y, width, height, radius, hexColor )  cairo_functions( w, CAIRO_RECT_FILLED, x, y, width, height, radius, hexColor )
// #define CAIRO_RECT_MULTI_COLOR,
#define bs_Triangle( w, x, y, x1, y1, x2, y2, hexColor )           cairo_functions( w, CAIRO_TRIANGLE, x, y, x1, y1, x2, y2, hexColor )
#define bs_TriangleFilled( w, x, y, x1, y1, x2, y2, hexColor )     cairo_functions( w, CAIRO_TRIANGLE_FILLED, x, y, x1, y1, x2, y2, hexColor )

#define bs_FreeType( w, fileName )                  text_functions( w, TEXT_FREE_TYPE, fileName )
#define bs_Text( w, text, x, y, hexColor )          text_functions( w, TEXT_CONST, text, x, y, hexColor )
#define bs_TextEx( w, text, x, y, size, hexColor )  text_functions( w, TEXT_EXTRA, text, x, y, size, hexColor )
#define bs_DispOutAt( w, text, col, row, hexColor ) text_functions( w, TEXT_DISPOUTAT, text, col, row, hexColor )
#define bs_TextWidth( w, text, size )               text_functions( w, TEXT_WIDTH, text, size )
#define bs_TextHeight( w, text, size )              text_functions( w, TEXT_HEIGHT, text, size )
#define bs_WindowTitle( w, text )                   text_functions( w, TEXT_WINDOWTITLE, text )

#define bs_GetKey( w, key )                glfw_functions( w, GLFW_GET_KEY, key )
#define bs_GetMouseButton( w, button )     glfw_functions( w, GLFW_GET_MOUSEBUTTON, button )
#define bs_WinWidth( w )                   glfw_functions( w, GLFW_WIN_WIDTH )
#define bs_WinHeight( w )                  glfw_functions( w, GLFW_WIN_HEIGHT )
#define bs_WinMaxCol( w )                  glfw_functions( w, GLFW_WIN_MAXCOL )
#define bs_WinMaxRow( w )                  glfw_functions( w, GLFW_WIN_MAXROW )
#define bs_WinMaximized( w )               glfw_functions( w, GLFW_WIN_MAXIMIZED )
#define bs_PollEvents( w )                 glfw_functions( w, GLFW_POLLEVENTS )
#define bs_WaitEvents( w )                 glfw_functions( w, GLFW_WAITEVENTS )
#define bs_WaitEventsTimeout( w, timeout ) glfw_functions( w, GLFW_WAITEVENTSTIMEOUT, timeout )

#endif /* End BLUESEA_H_ */
