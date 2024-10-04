# adjoon's ardux remixing notes

## Directory Structure
```
remixes
│   remix_layers.h
│   remix_shared_defines.h
│   remix_globals.h
|
└───combos
        control.def
        layers.def
        symbols.def
```
### remix_globals.h
Instructed to include in /layout/_layout.h
Not sure what it's used for yet.

### remix_layers.h

### remix_shared_defines.h
Used to redefine IDs that are used in layers to actual keys?
This also seems like a good place to define other important variables since it is included early in the compile process?
Included by /layout/layers.h which also includes the base shared_defines.h first - therefore in our remix_shared_defines.h we need to first #undef any base keys that we want to redefine.

### remix_layer_ids.h
Included by /layout/layer_ids.h
Probably used to define numeric IDs for remix layers - not sure whether you will be able to redefine the base layers which are already defined. There is not a flag to disable the base layer definition, so probably again need to #undef the base layer ids if you are changing the order.

### remix_combos.def
Looks like a file where you define extra .def files in /remixes/combos/ - seen in purple_rw repo, haven't found the include for it in the base files yet.

### 📂 combos
Contains .def files - these are created with whatever name you want so you can organise combos you add by different files.

However, there are a set of combos files existing in the base ardux, these are:
```
    ansi.def
    control.def
    layers.def
    mods.def
    symbols.def
```
You can open each of these to see the inputs they define. If you want to change these inputs, create a .def file with the same name in /remixes/combos/ directory. You can copy the structure from the base .def file. The base .def specifies to include the equivalent remix .def file if it exists.

In order to make this work, you must define the flag to 'DISABLE_DEFAULT_XXXX_COMBOS' specified in the base .def file. You can add this to your remix_shared_defines.h file. (There are probably plenty of other places you could define it instead but this makes sense to me)

