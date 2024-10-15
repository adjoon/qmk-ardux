# adjoon's ardux remixing notes

## Directory Structure WIP
```
remixes
│   README.md
│   remix_combos.def
│   remix_globals.h
│   remix_layers.h
│   remix_layer_ids.h
│   remix_shared_defines.h
│
└───combos
        adj_nav.def
        ansi.def
        control.def
        layers.def
        mods.def
        symbols.def
```
### remix_globals.h
Instructed to include in `/layout/_layout.h`.
Earliest to be included remix file that I know of, which makes it useful for defining custom parameters.

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

#### More on remix_layer_ids.h and the .json layer order

Does layer order actually matter?
Usually with QMK there is some value to layer order when using KC_TRNS (transparent keys) on multiple layers, and it limits which layers can be accessed from others (eg if you want to toggle a layer on to effectively switch to it, it needs to be above the current layer).

### Setting up custom layers
See chain explained above, each of the files will have to be changed to match.
- `remix_shared_defines.h` (or elsewhere with combos etc eg `/remixes/combos/layers.def`) - call for the LAYER_ID_\<NAME\> as you have defined in
- `remix_layer_ids.h` which replaces `layer_ids.h` - match the id number to the order of layers in the .json
- `.json` - can change the names and order of layers in here
- use `remix_globals.h` to make the equivalent definitions to those in `_layout.h` - I recommend using your own custom names to avoid variable conflicts
- define your desired layout in `remix_layers.h` with the handed-specific name you defined in `remix_globals.h`

Refer to my files for a working example. This does mean changing one file outside the remix directory, `ardux_thepaintbrush.json` (or whatever your .json is). Probably there is a way to get around this, but I had a go and was unsuccessful, decided just changing the .json was easier.

**⚠ IF YOU DEFINE YOUR OWN CUSTOM LAYER NAMES/ID SYSTEM ⚠**: 

you will first undefine the base set in `remix_layer_ids.h` before you define your own. 

**_HOWEVER,_** make sure that after all your desired layers are defined, you redefine any missing LAYER_ID_\<NAME\>s from the base set, otherwise you will encounter issues from the default oled programming, which is looking for those ID variables.

I have not looked much further into the oled behaviour, as I do not currently have one installed on my board, but it seems to lack remix implementation, so the files would probably have to be changed directly. The key file to look into should be `/users/ardux/oled/oled.c`.

### remix_combos.def
Seems to be intended as the file to include .def files in `/remixes/combos/`. Additional .def files in the remix should be included here. This file is included by `/users/ardux/combos.def`.

If you use `DISABLE_ALL_DEFAULT_COMBOS` instead of defining the disables for each base combo group individually (see section below), then you will need to include the combo .defs based on the base files here as well. (Because the `DISABLE_ALL_DEFAULT_COMBOS` totally prevents the inclusion of the base file, whereas the individual group disables just prevent the definitions withing the base file, which then includes its corresponding remix file after)

### 📂 /combos/
Contains .def files - these are created with whatever name you want, so you can organise combos you add by different files.

However, there are a set of combos files existing in the base ardux, these are:
```
    ansi.def
    control.def
    layers.def
    mods.def
    symbols.def
```
You can open each of these to see the inputs they define. If you want to change these inputs, create a .def file with the same name in /remixes/combos/ directory. You can copy the structure from the base .def file. The base .def specifies to include the equivalent remix .def file if it exists.

In order to replace these successfully, you must define the flag to 'DISABLE_DEFAULT_XXXX_COMBOS' specified in the base .def file. You can do this in your `remix_shared_defines.h` file. (There are probably other places you could define it instead but this makes sense to me)

Alternatively, see below, we can disable all the base combo files at once. In that case we would need to manually include any of our remix combos using `remix_combos.def`. 

## /users/ardux/combos.def
Also (as does `layers.h`) includes `shared_defines.h` and `remix_shared_defines.h`. Includes all the default combo.def files from `/layout/combos/` conditionally, checks if defined 'DISABLE_ALL_DEFAULT_COMBOS' to override this.
This way we could override all the default combos in one go, instead of using 5 different flags. 

Not sure at what point this is included, but it itself includes `remix_shared_defines.h` before checking the default combos, so again that is where I would put the above flag.

## /users/ardux/oled/oled.c
Sets up OLED behaviour - haven't touched this yet, not sure about remixing it or if you just have to overwrite. Has caused at least one headache by expecting things to be defined which I had overwritten while remixing. Pay attention to layer_ids.