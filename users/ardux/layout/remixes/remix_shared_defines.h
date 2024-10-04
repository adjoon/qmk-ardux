#define RIGHT_ANSI_SIX_THREE KC_QUOT,

// Disabling default combos
#define DISABLE_DEFAULT_NUMBER_COMBOS
#define DISABLE_DEFAULT_ALPHA_COMBOS
#define DISABLE_DEFAULT_CONTROL_COMBOS
#define DISABLE_DEFAULT_MOD_COMBOS

// Colemak base keys
#undef KEY_T1
#undef KEY_T2
#undef KEY_T3
#undef KEY_T4
#undef KEY_B1
#undef KEY_B2
#undef KEY_B3
#undef KEY_B4
#define KEY_B4 LT(LAYER_ID_CUSTOM, KC_A)
#define KEY_B3 KC_R
#define KEY_B2 KC_S
#define KEY_B1 LT(LAYER_ID_SYMBOLS, KC_T)
#define KEY_T1 LT(LAYER_ID_PARENTHETICALS, KC_N)
#define KEY_T2 KC_E
#define KEY_T3 KC_I
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