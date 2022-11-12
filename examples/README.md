## Installing on Linux

```
sudo apt-get update
sudo apt-get install libglfw3-dev
sudo apt-get install libcairo2-dev
```

To test it, type:

```
   $ cd examples/main
   $ gcc main.c -o main -I ../../include -L ../../lib/linux/gcc -lbluesea -lglfw -lcairo -lm
```

---
