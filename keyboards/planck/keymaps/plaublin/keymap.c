#include <locale.h>
#include QMK_KEYBOARD_H

/* ------------------- LAYERS ------------------- */

enum planck_layers {
    _DVORAK,
    _RECURVA,
    _QWERTY,
    _NUMBERS,
    _SYMBOLS,
    _MOUSE,
    _FUNCTION,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_DVORAK] = LAYOUT_ortho_4x12(
    //|--------+---------+---------+---------+---------+--------+--------+--------+---------+---------+---------+---------------|
       KC_TAB  , KC_QUOT , KC_COMM , KC_DOT  , KC_P    , KC_Y   , KC_F   , KC_G   , KC_C    , KC_R    , KC_L    , MO(_NUMBERS)  ,
    //|--------+---------+---------+---------+---------+--------+--------+--------+---------+---------+---------+---------------|
       KC_LSFT , KC_A    , KC_O    , KC_E    , KC_U    , KC_I   , KC_D   , KC_H   , KC_T    , KC_N    , KC_S    , MO(_SYMBOLS)  ,
    //|--------+---------+---------+---------+---------+--------+--------+--------+---------+---------+---------+---------------|
       QK_GESC , KC_SLSH , KC_Q    , KC_J    , KC_K    , KC_X   , KC_B   , KC_M   , KC_W    , KC_V    , KC_Z    , KC_UP         ,
    //|--------+---------+---------+---------+---------+--------+--------+--------+---------+---------+---------+---------------|
       KC_LCTL , KC_LGUI , KC_LALT , KC_SCLN , KC_BSPC , KC_SPC , KC_SPC , KC_ENT , KC_RALT , KC_LEFT , KC_RGHT , KC_DOWN
    //|--------+---------+---------+---------+---------+--------+--------+--------+---------+---------+---------+---------------|
    ),

    [_RECURVA] = LAYOUT_ortho_4x12(
    //|--------+---------+---------+---------+---------+--------+--------+--------+---------+---------+---------+---------------|
       KC_TAB  , KC_F    , KC_R    , KC_D    , KC_P    , KC_V   , KC_Q   , KC_M   , KC_U    , KC_O    , KC_Y    , MO(_NUMBERS)  ,
    //|--------+---------+---------+---------+---------+--------+--------+--------+---------+---------+---------+---------------|
       KC_LSFT , KC_S    , KC_N    , KC_T    , KC_C    , KC_B   , KC_DOT , KC_H   , KC_E    , KC_A    , KC_I    , MO(_SYMBOLS)  ,
    //|--------+---------+---------+---------+---------+--------+--------+--------+---------+---------+---------+---------------|
       QK_GESC , KC_Z    , KC_X    , KC_K    , KC_G    , KC_W   , KC_J   , KC_L   , KC_SCLN , KC_QUOT , KC_COMM , KC_UP         ,
    //|--------+---------+---------+---------+---------+--------+--------+--------+---------+---------+---------+---------------|
       KC_LCTL , KC_LGUI , KC_LALT , KC_SLSH , KC_BSPC , KC_SPC , KC_SPC , KC_ENT , KC_RALT , KC_LEFT , KC_RGHT , KC_DOWN
    //|--------+---------+---------+---------+---------+--------+--------+--------+---------+---------+---------+---------------|
    ),

    [_QWERTY] = LAYOUT_ortho_4x12(
    //|--------+---------+---------+---------+---------+--------+--------+--------+---------+---------+---------+---------------|
       KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T   , KC_Y   , KC_U   , KC_I    , KC_O    , KC_P    , MO(_NUMBERS)  ,
    //|--------+---------+---------+---------+---------+--------+--------+--------+---------+---------+---------+---------------|
       KC_LSFT , KC_A    , KC_S    , KC_D    , KC_F    , KC_G   , KC_H   , KC_J   , KC_K    , KC_L    , KC_SLSH , MO(_SYMBOLS)  ,
    //|--------+---------+---------+---------+---------+--------+--------+--------+---------+---------+---------+---------------|
       QK_GESC , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B   , KC_N   , KC_M   , KC_COMM , KC_DOT  , KC_QUOT , KC_UP         ,
    //|--------+---------+---------+---------+---------+--------+--------+--------+---------+---------+---------+---------------|
       KC_LCTL , KC_LGUI , KC_LALT , KC_SCLN , KC_BSPC , KC_SPC , KC_SPC , KC_ENT , KC_RALT , KC_LEFT , KC_RGHT , KC_DOWN
    //|--------+---------+---------+---------+---------+--------+--------+--------+---------+---------+---------+---------------|
    ),

    [_NUMBERS] = LAYOUT_ortho_4x12(
    //|--------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+--------------|
       _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_SLSH , KC_7    , KC_8    , KC_9    , KC_ASTR , _______      ,
    //|--------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+--------------|
       _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_0    , KC_1    , KC_2    , KC_3    , KC_MINS , _______      ,
    //|--------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+--------------|
       _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_DOT  , KC_4    , KC_5    , KC_6    , KC_EQL  , KC_UP        ,
    //|--------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+--------------|
       _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_LEFT , KC_RGHT , KC_DOWN
    //|--------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+--------------|
    ),

    [_SYMBOLS] = LAYOUT_ortho_4x12(
    //|--------+---------+------------+--------------+---------------+---------+---------+------------+--------------+-----------+---------+--------------|
       _______ , KC_GRV  , RALT(KC_E) , RALT(KC_GRV) , RALT(KC_COMM) , KC_LBRC , KC_RBRC , RALT(KC_6) , RSA(KC_QUOT) , RSA(KC_0) , KC_ASTR , _______      ,
    //|--------+---------+------------+--------------+---------------+---------+---------+------------+--------------+-----------+---------+--------------|
       _______ , KC_CIRC , KC_EXLM    , KC_AT        , KC_HASH       , KC_LPRN , KC_RPRN , KC_UNDS    , KC_NO        , KC_NO     , KC_DLR  , _______      ,
    //|--------+---------+------------+--------------+---------------+---------+---------+------------+--------------+-----------+---------+--------------|
       _______ , KC_PIPE , KC_AMPR    , KC_NO        , KC_PERC       , KC_SLSH , KC_BSLS , KC_MINS    , KC_NO        , KC_NO     , KC_EQL  , KC_UP        ,
    //|--------+---------+------------+--------------+---------------+---------+---------+------------+--------------+-----------+---------+--------------|
       _______ , _______ , _______    , KC_DOT       , _______       , _______ , _______ , _______    , _______      , KC_LEFT   , KC_RGHT , KC_DOWN
    //|--------+---------+------------+--------------+---------------+---------+---------+------------+--------------+-----------+---------+--------------|
    ),

    /* very compact symbols + numbers layer */
    //[_SYMBOLS] = LAYOUT_ortho_4x12(
    //   _______ , KC_GRV  , RALT(KC_6) , RSA(KC_QUOT) , RSA(KC_0) , KC_LBRC , KC_RBRC , KC_7    , KC_8      , KC_9    , KC_0    , _______      ,
    //   _______ , KC_CIRC , KC_EXLM    , KC_AT        , KC_HASH   , KC_LPRN , KC_RPRN , KC_1    , KC_2      , KC_3    , KC_DLR  , TG(_SYMBOLS) ,
    //   _______ , KC_ASTR , KC_PERC    , KC_MINS      , KC_AMPR   , KC_SLSH , KC_BSLS , KC_4    , KC_5      , KC_6    , KC_DOT  , KC_UP        ,
    //   _______ , _______ , _______    , KC_EQL       , _______   , _______ , _______ , _______ , _______   , KC_LEFT , KC_RGHT , KC_DOWN
    //),

    [_MOUSE] = LAYOUT_ortho_4x12(
    //|--------+---------+---------+---------+---------+---------+---------+------------+---------+---------+---------+---------|
       _______ , KC_NO   , KC_WH_U , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO      , KC_BTN1 , KC_MS_U , KC_BTN2 , _______ ,
    //|--------+---------+---------+---------+---------+---------+---------+------------+---------+---------+---------+---------|
       _______ , KC_BTN1 , KC_WH_D , KC_BTN2 , KC_NO   , KC_NO   , KC_NO   , KC_NO      , KC_MS_L , KC_MS_D , KC_MS_R , _______ ,
    //|--------+---------+---------+---------+---------+---------+---------+------------+---------+---------+---------+---------|
       _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , TG(_MOUSE) , KC_NO   , KC_NO   , KC_NO   , KC_UP   ,
    //|--------+---------+---------+---------+---------+---------+---------+------------+---------+---------+---------+---------|
       _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______    , _______ , KC_LEFT , KC_RGHT , KC_DOWN
    //|--------+---------+---------+---------+---------+---------+---------+------------+---------+---------+---------+---------|
    ),

    [_FUNCTION] = LAYOUT_ortho_4x12(
    //|--------+---------+---------+---------+---------+---------+---------+-----------+---------+-------------+-------------+------------|
       _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_NO   , KC_NO   , KC_MPLY   , KC_VOLU , DF(_DVORAK) , DF(_RECURVA), _______    ,
    //|--------+---------+---------+---------+---------+---------+---------+-----------+---------+-------------+-------------+------------|
       _______ , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_NO   , KC_NO   , KC_MSTP   , KC_VOLD , DF(_QWERTY) , KC_NO       , _______    ,
    //|--------+---------+---------+---------+---------+---------+---------+-----------+---------+-------------+-------------+------------|
       _______ , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_NO   , QK_BOOT , TG(_MOUSE), KC_MUTE , KC_INS      , KC_DEL      , KC_PGUP    ,
    //|--------+---------+---------+---------+---------+---------+---------+-----------+---------+-------------+-------------+------------|
       _______ , _______ , _______ , KC_RALT , _______ , _______ , _______ , _______   , KC_PSCR , KC_HOME     , KC_END      , KC_PGDN
    //|--------+---------+---------+---------+---------+---------+---------+-----------+---------+-------------+-------------+------------|
    ),
};


/* ------------------ KEY OVERRIDE ------------------- */

const key_override_t bkspc_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t up_key_override = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, KC_UP, KC_PGUP, ~0, MOD_MASK_GUI);
const key_override_t dn_key_override = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, KC_DOWN, KC_PGDN, ~0, MOD_MASK_GUI);
const key_override_t left_key_override = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, KC_LEFT, KC_HOME, ~0, MOD_MASK_GUI);
const key_override_t right_key_override = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, KC_RGHT, KC_END, ~0, MOD_MASK_GUI);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &bkspc_key_override,
    &up_key_override,
    &dn_key_override,
    &left_key_override,
    &right_key_override,
    NULL // Null terminate the array of overrides!
};


/* ------------------- RGB LIGHT ------------------- */

// Define lighting layers
const rgblight_segment_t PROGMEM all_leds_red[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 1, HSV_OFF},
        {1, 8, HSV_RED}
        );

const rgblight_segment_t PROGMEM my_dvorak_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 3, HSV_OFF},
        {3, 1, HSV_TURQUOISE},
        {4, 5, HSV_OFF}
        );

const rgblight_segment_t PROGMEM my_recurva_layer[] = RGBLIGHT_LAYER_SEGMENTS(
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
        my_dvorak_layer,
        my_recurva_layer,
        my_qwerty_layer,
        my_numbers_layer,
        my_symbols_layer,
        my_mouse_layer,
        all_leds_red
        );

// Set up
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _DVORAK));
    rgblight_set_layer_state(1, layer_state_cmp(state, _RECURVA));
    rgblight_set_layer_state(2, layer_state_cmp(state, _QWERTY));

    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _SYMBOLS, _NUMBERS , _FUNCTION);

    rgblight_set_layer_state(3, layer_state_cmp(state, _NUMBERS));
    rgblight_set_layer_state(4, layer_state_cmp(state, _SYMBOLS));
    rgblight_set_layer_state(5, layer_state_cmp(state, _MOUSE));
    rgblight_set_layer_state(6, layer_state_cmp(state, _FUNCTION));

    return state;
}


/* -------------------- COMBOS --------------------- */

const uint16_t PROGMEM semi_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM semi_combo2[] = {RCTL_T(KC_COMM), KC_DOT, COMBO_END};

combo_t key_combos[] = {
    COMBO(semi_combo, KC_SCLN),
    COMBO(semi_combo2, KC_SCLN),
};

/* ------------------- ENCODER ------------------- */

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

