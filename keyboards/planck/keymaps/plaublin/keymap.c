#include QMK_KEYBOARD_H

/* ------------------- LAYERS ------------------- */

enum planck_layers {
    _DVORAK,
    _QWERTY,
    _NUMBERS,
    _SPECIAL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Dvorak
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |TT Num|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |MO Spe|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc~`|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |  Up  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | Meta | LAlt  | RAlt| Bksp |    Space    |Enter |   /  | Left | Right| Down |
     * `-----------------------------------------------------------------------------------'
     */
    [_DVORAK] = LAYOUT_ortho_4x12(
            KC_TAB  , KC_QUOT , KC_COMM , KC_DOT  , KC_P    , KC_Y    , KC_F    , KC_G    , KC_C    , KC_R    , KC_L    , TT(_NUMBERS) ,
            KC_LSFT , KC_A    , KC_O    , KC_E    , KC_U    , KC_I    , KC_D    , KC_H    , KC_T    , KC_N    , KC_S    , MO(_SPECIAL) ,
            QK_GESC , KC_SCLN , KC_Q    , KC_J    , KC_K    , KC_X    , KC_B    , KC_M    , KC_W    , KC_V    , KC_Z    , KC_UP        ,
            KC_LCTL , KC_LGUI , KC_LALT , KC_RALT , KC_BSPC , KC_SPC  , KC_SPC  , KC_ENT  , KC_SLSH , KC_LEFT , KC_RGHT , KC_DOWN
            ),

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |TT Num|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |MO Spe|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc~`|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   '  |  Up  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | Meta | LAlt  | RAlt| Bksp |    Space    |Enter |   /  | Left | Right| Down |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_ortho_4x12(
            KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , TT(_NUMBERS) ,
            KC_LSFT , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , MO(_SPECIAL) ,
            QK_GESC , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_QUOT , KC_UP        ,
            KC_LCTL , KC_LGUI , KC_LALT , KC_RALT , KC_BSPC , KC_SPC  , KC_SPC  , KC_ENT  , KC_SLSH , KC_LEFT , KC_RGHT , KC_DOWN
            ),

    /* Numbers
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |  ` ~ |      |      |      |      |      |      |      |  - _ |  = + |TG Num|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|  1 ! |  2 @ |  3 # |  4 $ |  5 % |  6 ^ |  7 & |  8 * |  9 ( |  0 ) |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc~`|      |      |   {  |   [  |   (  |   )  |   ]  |   }  |      |      |  Up  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | Meta | LAlt  | RAlt| Bksp |    Space    |Enter |  \ | | Left | Right| Down |
     * `-----------------------------------------------------------------------------------'
     */
    [_NUMBERS] = LAYOUT_ortho_4x12(
            _______ , KC_GRV  , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_MINS , KC_EQL  , TG(_NUMBERS) ,
            _______ , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , _______ ,
            _______ , KC_NO   , KC_NO   , KC_LCBR , KC_LBRC , KC_LPRN , KC_RPRN , KC_RBRC , KC_RCBR , KC_NO   , KC_NO   , _______ ,
            _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_BSLS , _______ , _______ , _______
            ),

    /* Special
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |  F1  |  F2  |  F3  |  F4  |      |      |BRIGH+| VOL+ |DVORAK|QWERTY|      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|  F5  |  F6  |  F7  |  F8  |      |      |BRIGH-| VOL- |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc~`|  F9  |  F10 | F11  | F12  |      |      |RBGTOG| MUTE |  INS | DEL  |  Up  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | Meta | LAlt  | RAlt| Bksp |    Space    |Enter |  /   | Left | Right| Down |
     * `-----------------------------------------------------------------------------------'
     */
    [_SPECIAL] = LAYOUT_ortho_4x12(
            _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_NO   , KC_NO   , RGB_VAI , KC_VOLU , DF(_DVORAK) , DF(_QWERTY) , _______ ,
            _______ , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_NO   , KC_NO   , RGB_VAD , KC_VOLD , KC_NO       , KC_NO       , _______ ,
            _______ , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_NO   , KC_NO   , RGB_TOG , KC_MUTE , KC_INS      , KC_DEL      , _______ ,
            _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______     , _______     , _______
            ),

};


/* ------------------- KEY OVERRIDE ------------------- */

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t pgup_key_override = ko_make_basic(MOD_MASK_CTRL, KC_UP, KC_PGUP);
const key_override_t pgdn_key_override = ko_make_basic(MOD_MASK_CTRL, KC_DOWN, KC_PGDN);
const key_override_t home_key_override = ko_make_basic(MOD_MASK_CTRL, KC_LEFT, KC_HOME);
const key_override_t end_key_override = ko_make_basic(MOD_MASK_CTRL, KC_RGHT, KC_END);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
        &pgup_key_override,
        &pgdn_key_override,
        &home_key_override,
        &end_key_override,
        NULL // Null terminate the array of overrides!
};


/* ------------------- RGB LIGHT ------------------- */

// Define lighting layers
const rgblight_segment_t PROGMEM my_dvorak_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {1, 8, HSV_TURQUOISE},
        {0, 1, HSV_OFF}
        );

const rgblight_segment_t PROGMEM my_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {1, 8, HSV_TEAL},
        {0, 1, HSV_OFF}
        );

const rgblight_segment_t PROGMEM my_numbers_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {1, 8, HSV_SPRINGGREEN},
        {0, 1, HSV_OFF}
        );

const rgblight_segment_t PROGMEM my_special_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {1, 8, HSV_RED},
        {0, 1, HSV_OFF}
        );

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
        my_dvorak_layer,
        my_qwerty_layer,
        my_numbers_layer,
        my_special_layer
        );

// Set up
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _DVORAK));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(2, layer_state_cmp(state, _NUMBERS));
    rgblight_set_layer_state(3, layer_state_cmp(state, _SPECIAL));
    return state;
}


/* ------------------- ENCODER ------------------- */

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)


