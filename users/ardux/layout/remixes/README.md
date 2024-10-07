# adjoon's ardux remixing notes

## Directory Structure WIP
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
Instructed to include in `/layout/_layout.h`
Not sure what it's used for yet.

### remix_layers.h
Used to define layouts of alternate layers. Included by the base file `/layout/layers.h`.

The base file includes the remix files first, then uses `#ifndef` for all the layer name variables. Therefore you can define in `remix_layers.h` freely.

You can either copy the layer names from the base ardux, or I think you can just create your own. It seems easier to just copy the names of the base layers and modify them instead though. This way the layer ID system is already set up for you. 

(Also I guess it would save space when compiling? Probably not a significant factor, and you could alternatively undefine the base layers somewhere else later, or modify the base files if it was that critical to you.)

The downside of this method is the layer names won't necessarily match their actual purpose, making things slightly more confusing when referencing them.

### remix_shared_defines.h
Based on `/layout/shared_defines.h`
Used to define named variables which correspond to keys used in layers. This allows us to refer to keys in these layers by the position of the key when defining combos and layer layouts later, instead of the actual keycode.

This just makes things less confusing when editing, and also lets you change the layout of the base layer while preserving the physical inputs of combos.

This also seems like a good place to define other important variables since it is included early in the compile process?

Included by `/layout/layers.h` which also includes the base `shared_defines.h` first - therefore in our `remix_shared_defines.h` we need to first `#undef` any base keys that we want to redefine.

### remix_layer_ids.h
When using QMK syntax for layer swaps/activation, layers are called by number.
Ex: in `remix_shared_defines.h`, `#define KEY_B4 LT(LAYER_ID_CUSTOM, KC_SPACE)` means if held swap to layer  `(value of) LAYER_ID_CUSTOM` (expects numerical value), if tapped send Space.
So then `layer_ids.h` and `remix_layer_ids.h` exist so that we can create variables with memorable names and use those instead of keeping track of numbers for layers. 

##### But where do the numbers for the layers come from in the first place?

#### How the whole layer IDs chain actually works:

##### _layout.h -> sets up handed-specific alias eg:
```c
#ifdef ARDUX_SIZE_STD
#ifdef ARDUX_HAND_LEFT
...
#define ARDUX_STD_LAYER_PAR ARDUX_STD_LAYER_PAR_LEFT
...
#endif
#endif
```
includes `remix_globals.h`, `layer_ids.h`, `layers.h` (BEFORE THE ABOVE DEF)

##### layer_ids.h -> defines numeric values for aliases eg:
```c
#define LAYER_ID_GLOBAL -1
#define LAYER_ID_BASE 0
#define LAYER_ID_NUMBERS 1
#define LAYER_ID_SYMBOLS 2
#define LAYER_ID_PARENTHETICALS 3
```
includes `remix_layer_ids.h` at the END

##### layers.h -> defines actual layouts with keys (handed-specific) eg: 
```c
#ifndef ARDUX_STD_LAYER_PAR_LEFT
#define ARDUX_STD_LAYER_PAR_LEFT \
STD_LEADING_NONES \
KC_RCBR,          KC_LPRN,          KC_RPRN,          KC_TRNS,          \
STD_BETWEEN_ROW_ONE_TWO_NONES \
KC_LCBR,          KC_LBRC,          KC_RBRC,          KC_NO             \
STD_TRAILING_NONES
#endif
```

##### remix_shared_defines.h -> call the QMK LT() using the var defined by layer_ids.h eg:
```c
#define KEY_T1 LT(LAYER_ID_PARENTHETICALS, KC_S)
```
(OVERWRITES `shared_defines.h`)

##### ardux_thepaintbrush.json -> defines the layers with the names as defined in _layout.h and the numbers corresponding to layer_ids.h eg:
```json
{
    "keyboard": "ardux/thepaintbrush",
    "keymap": "ardux",
    "layout": "LAYOUT_ardux_wrapper",
    "layers": [
        [ "ARDUX_STD_LAYER_BASE" ],
        [ "ARDUX_STD_LAYER_NUM" ],
        [ "ARDUX_STD_LAYER_SYM" ],
        [ "ARDUX_STD_LAYER_PAR" ],
        [ "ARDUX_STD_LAYER_NAV" ],
        [ "ARDUX_STD_LAYER_CUS" ],
        [ "ARDUX_STD_LAYER_MSE" ]
    ]
}
```
Therefore the full chain goes:
- `remix_shared_defines.h`      calls for `LT(LAYER_ID_PARENTHETICALS)`
- `layer_ids.h`                 defines this as `3`
- `ardux_thepaintbrush.json`    says layer `3` is `ARDUX_STD_LAYER_PAR`
- `_layout.h`                   says `ARDUX_STD_LAYER_PAR` = `ARDUX_STD_LAYER_PAR_LEFT`
- `layers.h`                    defines the layout of `ARDUX_STD_LAYER_PAR_LEFT`

#### More on remix_layer_ids.h

Does layer order actually matter?
Usually with QMK there is some value to layer order when using KC_TRNS (transparent keys) on multiple layers, and it limits which layers can be accessed from others (eg if you want to toggle a layer on to effectively switch to it, it needs to be above the current layer).

### Setting up custom layers
IDK HOW

### remix_combos.def
Looks like a file where you define extra .def files in /remixes/combos/ - seen in purple_rw repo, haven't found the include for it in the base files yet.

Edit: it is included by `/users/ardux/combos.def`

Also I should define `DISABLE_ALL_DEFAULT_COMBOS` instead of defining all the disables individually, and then just include my combo .defs from `remix_combos.def` instead of using the base ones.

### 📂 combos
Contains .def files - these are created with whatever name you want? so you can organise combos you add by different files.

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

## /users/ardux/oled/oled.c
Sets up OLED behaviour - haven't touched this yet, not sure about remixing it or if you just have to overwrite. Has caused at least one headache by expecting things to be defined which I had overwritten while remixing. Pay attention to layer_ids. 