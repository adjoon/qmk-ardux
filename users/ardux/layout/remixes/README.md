# adjoon's ardux remixing notes

## Directory Structure
```
remixes
|   README.md
|   remix_layers.h
|   remix_shared_defines.h
|
+---boards
|       ardux_thepaintbrush.h
|       crkbd_rev1.h
|
\---combos
        control.def
        layers.def
        symbols.def
```
### remix_layers.h

### remix_shared_defines.h
not exactly sure whats going on here, right now it only defines one line:
```c
#define RIGHT_ANSI_SIX_THREE KC_QUOT,
```

### 📂 boards
####    ardux_thepaintbrush.h
currently only defines the same custom layer from the start of remix_layers.h - testing shows that the remix_layers.h takes priority, will try clearing this file for the next build
####    ardux_crkbd_rev1.h
seems to define some basic layout for a larger board - hopefully not relevant to my build? will try deleting at some point

### 📂 combos
Contains .def files - these are created with whatever name you want?? so you can organise combos you add by different files?