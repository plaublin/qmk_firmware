#include <locale.h>
#include QMK_KEYBOARD_H

/* ------------------- LAYERS ------------------- */

enum planck_layers {
    _FOCAL,
    _QWERTY,
    _SYMBOLS,
    _NUMBERS,
    _MOUSE,
    _FUNCTION,
};

#define LT_SYMTAB LT(_SYMBOLS, KC_TAB)
#define LT_NUMENT LT(_NUMBERS, KC_ENT)
#define MT_SPCSFT MT(MOD_LSFT, KC_SPC)
#define MT_BSPSFT MT(MOD_LSFT, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_FOCAL] = LAYOUT_ortho_4x12(
       KC_TAB , KC_V   , KC_L   , KC_H , KC_G     , KC_K     , KC_Q     , KC_F     , KC_O   , KC_U   , KC_J   , MO(_FUNCTION),
       QK_GESC, KC_S   , KC_R   , KC_N , KC_T     , KC_B     , KC_Y     , KC_C     , KC_E   , KC_A   , KC_I   , KC_SLSH      ,
       KC_LSFT, KC_Z   , KC_X   , KC_M , KC_D     , KC_P     , KC_QUOT  , KC_W     , KC_DOT , KC_SCLN, KC_COMM, KC_UP        ,
       KC_LGUI, KC_LALT, KC_LCTL, KC_NO, LT_SYMTAB, MT_SPCSFT, MT_BSPSFT, LT_NUMENT, KC_RALT, KC_LEFT, KC_RGHT, KC_DOWN
    ),

    [_QWERTY] = LAYOUT_ortho_4x12(
       KC_TAB , KC_Q   , KC_W   , KC_E , KC_R     , KC_T     , KC_Y     , KC_U     , KC_I   , KC_O   , KC_P   , MO(_FUNCTION),
       QK_GESC, KC_A   , KC_S   , KC_D , KC_F     , KC_G     , KC_H     , KC_J     , KC_K   , KC_L   , KC_SCLN, KC_QUOT      ,
       KC_LSFT, KC_Z   , KC_X   , KC_C , KC_V     , KC_B     , KC_N     , KC_M     , KC_COMM, KC_DOT , KC_SLSH, KC_UP        ,
       KC_LGUI, KC_LALT, KC_LCTL, KC_NO, LT_SYMTAB, MT_SPCSFT, MT_BSPSFT, LT_NUMENT, KC_RALT, KC_LEFT, KC_RGHT, KC_DOWN
    ),

    [_SYMBOLS] = LAYOUT_ortho_4x12(
       _______, KC_GRV,RALT(KC_E),RALT(KC_GRV),RALT(KC_COMM),RALT(KC_6),RSA(KC_QUOT),KC_LCBR,KC_RCBR,KC_AMPR,KC_NO ,_______,
       _______, KC_CIRC,KC_EXLM,KC_AT,KC_HASH,KC_PERC,RSA(KC_0),KC_LPRN,KC_RPRN,KC_SLSH,KC_DLR                               ,_______,
       _______, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_LBRC,KC_RBRC,KC_BSLS,KC_NO                                            ,_______,
       _______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______                              ,_______
    ),

    [_MOUSE] = LAYOUT_ortho_4x12(
       _______,KC_NO,KC_BTN3,KC_WH_U,QK_GESC,KC_NO,KC_BTN3,KC_BTN1,KC_MS_U,KC_BTN2,TG(_MOUSE)                              ,_______,
       _______,KC_NO,KC_BTN1,KC_WH_D,KC_BTN2,KC_NO,KC_NO,KC_MS_L,KC_MS_D,KC_MS_R,OSM(MOD_RSFT)                             ,_______,
       _______,OSM(MOD_LGUI),OSM(MOD_LALT),OSM(MOD_LCTL),KC_NO,KC_NO,KC_NO,KC_NO,OSM(MOD_RCTL),OSM(MOD_RALT),OSM(MOD_RGUI) ,_______,
       _______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______                            ,_______
    ),

    [_NUMBERS] = LAYOUT_ortho_4x12(
       _______,KC_INS,KC_HOME,KC_UP,KC_END,KC_DEL,KC_SLSH,KC_7,KC_8,KC_9,KC_ASTR                      ,_______,
       _______,QK_GESC,KC_LEFT,KC_DOWN,KC_RGHT,KC_PGUP,KC_0,KC_1,KC_2,KC_3,KC_MINS                    ,_______,
       _______,OSM(MOD_LGUI),OSM(MOD_LALT),OSM(MOD_LCTL),KC_PSCR,KC_PGDN,KC_EQL,KC_4,KC_5,KC_6,KC_DOT ,_______,
       _______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______       ,_______
    ),

    [_FUNCTION] = LAYOUT_ortho_4x12(
       _______, KC_DEL , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_MPLY, KC_VOLU , DF(_FOCAL), DF(_QWERTY)  , TT(_MOUSE), _______,
       _______, QK_GESC, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_MSTP, KC_VOLD , KC_NO     , KC_NO        , KC_NO     , _______,
       _______, KC_NO  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_NO  , KC_MUTE , KC_NO     , OSM(MOD_RALT), QK_BOOT   , _______,
       _______, _______, _______, _______,_______ ,_______ ,_______ , _______ ,_______    ,_______       ,_______    , _______
    ),
};


/* ------------------ KEY OVERRIDE ------------------- */

const key_override_t bkspc_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t numdot_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_COMM, 1 << _NUMBERS);
const key_override_t up_key_override = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, KC_UP, KC_PGUP, ~0, MOD_MASK_GUI);
const key_override_t dn_key_override = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, KC_DOWN, KC_PGDN, ~0, MOD_MASK_GUI);
const key_override_t left_key_override = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, KC_LEFT, KC_HOME, ~0, MOD_MASK_GUI);
const key_override_t right_key_override = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, KC_RGHT, KC_END, ~0, MOD_MASK_GUI);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &bkspc_key_override,
    &numdot_key_override,
    &up_key_override,
    &dn_key_override,
    &left_key_override,

    &right_key_override,
    NULL // Null terminate the array of overrides!
};


/* -------------------- COMBOS --------------------- */

const uint16_t PROGMEM semi_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM semi_combo2[] = {RCTL_T(KC_COMM), KC_DOT, COMBO_END};

combo_t key_combos[] = {
    COMBO(semi_combo, KC_SCLN),
    COMBO(semi_combo2, KC_SCLN),
};


/* ------------------- RGB LIGHT ------------------- */

// Define lighting layers
const rgblight_segment_t PROGMEM all_leds_red[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 1, HSV_OFF},
        {1, 8, HSV_RED}
        );

const rgblight_segment_t PROGMEM my_focal_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 3, HSV_OFF},
        {3, 1, HSV_TURQUOISE},
        {4, 5, HSV_OFF}
        );

const rgblight_segment_t PROGMEM my_maya_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 3, HSV_OFF},
        {3, 1, HSV_SPRINGGREEN},
        {4, 5, HSV_OFF}
        );

const rgblight_segment_t PROGMEM my_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 3, HSV_OFF},
        {3, 1, HSV_BLUE},
        {4, 5, HSV_OFF}
        );

const rgblight_segment_t PROGMEM my_numbers_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 4, HSV_OFF},
        {4, 1, HSV_GOLD},
        {5, 4, HSV_OFF}
        );

const rgblight_segment_t PROGMEM my_symbols_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 5, HSV_OFF},
        {5, 1, HSV_MAGENTA},
        {6, 3, HSV_OFF}
        );

const rgblight_segment_t PROGMEM my_mouse_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 6, HSV_OFF},
        {6, 1, HSV_TEAL},
        {7, 2, HSV_OFF}
        );

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
        my_focal_layer,
        my_qwerty_layer,
        my_symbols_layer,
        my_numbers_layer,
        my_mouse_layer,
        all_leds_red,
        my_maya_layer
        );

// Set up
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _FOCAL));
    rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTY));

    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _SYMBOLS));
    rgblight_set_layer_state(3, layer_state_cmp(state, _NUMBERS));
    rgblight_set_layer_state(4, layer_state_cmp(state, _MOUSE));
    rgblight_set_layer_state(5, layer_state_cmp(state, _FUNCTION));

    return state;
}


/* ------------------- ENCODER ------------------- */

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

