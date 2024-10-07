// Copyright (c) 2022 purple-rw
// SPDX-License-Identifier: Apache-2.0

// Undefine base layer IDs
#undef LAYER_ID_BASE
#undef LAYER_ID_NUMBERS
#undef LAYER_ID_SYMBOLS
#undef LAYER_ID_PARENTHETICALS
#undef LAYER_ID_NAVIGATION
#undef LAYER_ID_CUSTOM
#undef LAYER_ID_MOUSE
#undef LAYER_ID_BIG_SYM
#undef LAYER_ID_BIG_FUN

// Define my own IDs
#define LAYER_ID_BASE 0
#define LAYER_ID_NUMBERS 1
#define LAYER_ID_SYMBOLS 2
#define LAYER_ID_PARENTHETICALS 3
#define LAYER_ID_NUMLOCK 4
#define LAYER_ID_AKEYS 5
#define LAYER_ID_MOUSE 6
#define LAYER_ID_CTRL 7

// redefine missing base IDs at the end to make oled happy :)
#define LAYER_ID_NAVIGATION 8
#define LAYER_ID_CUSTOM 9


// Additional custom layers
// #define LAYER_ID_CTRL (LAYER_ID_MOUSE + 1)
