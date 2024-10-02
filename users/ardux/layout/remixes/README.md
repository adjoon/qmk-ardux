# adjoon's ardux remixing notes

## Directory Structure
```
remixes
│   README.md
│   remix_layers.h
│   remix_shared_defines.h
│
└───combos
        control.def
        layers.def
        symbols.def
```
### remix_layers.h

### remix_shared_defines.h
Used to redefine IDs that are used in layers to actual keys?
I am also defining #define DISABLE_DEFAULT_NUMBER_COMBOS and DISABLE_DEFAULT_ALPHA_COMBOS and more here instead of later to prevent redeclaration error

### 📂 combos
Contains .def files - these are created with whatever name you want?? so you can organise combos you add by different files?