#define RIGHT_ANSI_SIX_THREE KC_QUOT,

// Disabling default combos
#define DISABLE_DEFAULT_NUMBER_COMBOS
#define DISABLE_DEFAULT_ALPHA_COMBOS
#define DISABLE_DEFAULT_CONTROL_COMBOS
#define DISABLE_DEFAULT_MOD_COMBOS
#define DISABLE_DEFAULT_SYMBOL_COMBOS
#define DISABLE_DEFAULT_LAYER_COMBOS

// Colemak base keys
#undef KEY_T1
#undef KEY_T2
#undef KEY_T3
#undef KEY_T4
#undef KEY_B1
#undef KEY_B2
#undef KEY_B3
#undef KEY_B4
#define KEY_B4 LT(LAYER_ID_AKEYS, KC_SPACE)
#define KEY_B3 LT(LAYER_ID_CTRL, KC_R)
#define KEY_B2 KC_E
#define KEY_B1 LT(LAYER_ID_SYMBOLS, KC_T)
#define KEY_T1 LT(LAYER_ID_PARENTHETICALS, KC_S)
#define KEY_T2 KC_I
#define KEY_T3 KC_N
#define KEY_T4 LT(LAYER_ID_NUMBERS, KC_O)

// Ten-key number keys (Left Hand Based)
#undef KNUM_T1
#undef KNUM_T2
#undef KNUM_T3
#undef KNUM_T4
#undef KNUM_B1
#undef KNUM_B2
#undef KNUM_B3
#undef KNUM_B4
#define KNUM_T4 KC_0
#define KNUM_B4 KC_TRNS
#define KNUM_B3 KC_1
#define KNUM_B2 KC_2
#define KNUM_B1 KC_3
#define KNUM_T3 KC_4
#define KNUM_T2 KC_5
#define KNUM_T1 KC_6

// Numlock Layer (replaces nav layer index)
// Undefine Nav for fun just in case
#undef KNAV_B4
#undef KNAV_B3
#undef KNAV_B2
#undef KNAV_B1
#undef KNAV_T1
#undef KNAV_T2
#undef KNAV_T3
#undef KNAV_T4
// Define my NUMLOCK layer keys
#define KNMLK_B4 MO(LAYER_ID_AKEYS)
#define KNMLK_B3 KC_1
#define KNMLK_B2 KC_2
#define KNMLK_B1 KC_3
#define KNMLK_T1 KC_6
#define KNMLK_T2 KC_5
#define KNMLK_T3 KC_4
#define KNMLK_T4 KC_ENT


// Defining my AKEYS layer keys
#define AKEYS_B4 KC_TRNS
#define AKEYS_B3 KC_LEFT
#define AKEYS_B2 KC_DOWN
#define AKEYS_B1 KC_RIGHT
#define AKEYS_T1 LALT(KC_TAB)
#define AKEYS_T2 KC_UP
#define AKEYS_T3 KC_ESC
#define AKEYS_T4 KC_PSCR

// Defining my CTRL layer keys
#define KCTRL_B4 MT(KC_LSFT, LCTL(KC_Y))
#define KCTRL_B3 KC_TRNS
#define KCTRL_B2 LCTL(KC_Z)
#define KCTRL_B1 LCTL(KC_X)
#define KCTRL_T1 LCTL(KC_C)
#define KCTRL_T2 LCTL(KC_V)
#define KCTRL_T3 KC_F2
#define KCTRL_T4 KC_LCTL