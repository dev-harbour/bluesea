# bluesea

## Installing on Windows

- MSYS2

   ```
   pacman -S mingw-w64-x86_64-glfw
   pacman -S mingw-w64-x86_64-cairo
   pacman -S mingw-w64-x86_64-freetype
   ```
   To test it, type:

   ```
      $ cd examples/main
      $ gcc pl.c -o pl -I ../../include -L ../../lib/win/mingw64 -lbluesea -lglfw3 -lcairo -lm $(pkg-config --cflags freetype2) $(pkg-config --libs freetype2)
   ```

## Installing on Linux

- Debian

   ```
   sudo apt-get update
   sudo apt-get install libglfw3-dev
   sudo apt-get install libcairo2-dev
   sudo apt-get install libfreetype6-dev
   ```
   To test it, type:

   ```
      $ cd examples/main
      $ gcc pl.c -o pl -I ../../include -L ../../lib/linux/gcc -lbluesea -lglfw -lcairo -lm $(pkg-config --cflags freetype2) $(pkg-config --libs freetype2)
   ```

---
