#include QMK_KEYBOARD_H

/* ------------------- TAP DANCE ------------------- */

// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Our custom tap dance key; add any other tap dance keys to this enum
enum {
    // TESYM pressed once: TAB
    // TESYM pressed twice: ESC
    // TESYM hold: go to SYM layer
    TESYM,
};

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(tap_dance_state_t *state, void *user_data);
void ql_reset(tap_dance_state_t *state, void *user_data);


/* ------------------- LAYERS ------------------- */

// Go to NUM layer while hold, send enter if pressed one
#define NUMENT LT(_NUMBERS_34, KC_ENT)

enum planck_layers {
    _DVORAK_34,
    _MAYA_34,
    _QWERTY_34,
    _SYMBOLS_34,
    _NUMBERS_34,
    _MOUSE_34,
    _FUNCTION_34,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /********************** 34 KEYS LAYOUT COLUMN STAGGER **********************/

    /* Dvorak
     * ,-----------------------------------------------------------------------------------.
     * |      |   ,  |   .  |   P  |   Y  |      |      |   F  |   G  |   C  |   R  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   '  |   O  |   E  |   U  |   I  |      |      |   D  |   H  |   T  |   N  |   L  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |LSFT A|LCRL Q|LMTA J|LALT K|   X  |      |      |   B  |RALT M|RMTA W|RCTL V|RSFT S|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |MOS ; |      |      |TESYM | Bksp |             |Space |NUMENT|      |      |   Z  |
     * `-----------------------------------------------------------------------------------'
     */
    [_DVORAK_34] = LAYOUT_ortho_4x12(
            KC_NO                  , KC_COMM      , KC_DOT       , KC_P         , KC_Y    , KC_NO , KC_NO , KC_F   , KC_G         , KC_C         , KC_R         , KC_NO         ,
            KC_QUOT                , KC_O         , KC_E         , KC_U         , KC_I    , KC_NO , KC_NO , KC_D   , KC_H         , KC_T         , KC_N         , KC_L         ,
            LSFT_T(KC_A)           , LCTL_T(KC_Q) , LGUI_T(KC_J) , LALT_T(KC_K) , KC_X    , KC_NO , KC_NO , KC_B   , RALT_T(KC_M) , RGUI_T(KC_W) , RCTL_T(KC_V) , RSFT_T(KC_S) ,
            LT(_MOUSE_34, KC_SCLN) , KC_NO        , KC_NO        , TD(TESYM)    , KC_BSPC , KC_NO , KC_NO , KC_SPC , NUMENT       , KC_NO        , KC_NO        , KC_Z
            ),

    /* Maya
     * ,-----------------------------------------------------------------------------------.
     * |      |   L  |   D  |   C  |   Z  |      |      |   V  |   F  |   O  |   U  |     |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   M  |   R  |   T  |   S  |   B  |      |      |   Y  |   H  |   A  |  E   |  .   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |LSFT N|LCRL K|LMTA G|LALT W|   Q  |      |      |   J  |RALT P|RMTA '|RCTL ;|RSFT I|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |MOS X |      |      |TESYM | Bksp |             |Space |NUMENT|      |      |  ,   |
     * `-----------------------------------------------------------------------------------'
     */
    [_MAYA_34] = LAYOUT_ortho_4x12(
            KC_NO               , KC_L         , KC_D         , KC_C         , KC_Z    , KC_NO , KC_NO , KC_V   , KC_F         , KC_O            , KC_U            , KC_NO        ,
            KC_M                , KC_R         , KC_T         , KC_S         , KC_B    , KC_NO , KC_NO , KC_Y   , KC_H         , KC_A            , KC_E            , KC_DOT       ,
            LSFT_T(KC_N)        , LCTL_T(KC_K) , LGUI_T(KC_G) , LALT_T(KC_W) , KC_Q    , KC_NO , KC_NO , KC_J   , RALT_T(KC_P) , RGUI_T(KC_QUOT) , RCTL_T(KC_SCLN) , RSFT_T(KC_I) ,
            LT(_MOUSE_34, KC_X) , KC_NO        , KC_NO        , TD(TESYM)    , KC_BSPC , KC_NO , KC_NO , KC_SPC , NUMENT       , KC_NO           , KC_NO           , KC_COMM
            ),

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * |      |   W  |   E  |   R  |   T  |      |      |   Y  |   U  |   I  |   O  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   Q  |   S  |   D  |   F  |   G  |      |      |   H  |   J  |   K  |   L  |   P  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |LSFT A|LCRL X|LMTA C|LALT V|   B  |      |      |   N  |RALT M|RMTA ,|RCTL .|RSFT ;|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |MON Z |      |      |TESYM | Bksp |             |Space |NUMENT|      |      |  '   |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY_34] = LAYOUT_ortho_4x12(
            KC_NO                , KC_W         , KC_E         , KC_R         , KC_T    , KC_NO, KC_NO , KC_Y   , KC_U         , KC_I            , KC_O           , KC_NO           ,
            KC_Q                 , KC_S         , KC_D         , KC_F         , KC_G    , KC_NO, KC_NO , KC_H   , KC_J         , KC_K            , KC_L           , KC_P            ,
            LSFT_T(KC_A)         , LCTL_T(KC_X) , LGUI_T(KC_C) , LALT_T(KC_V) , KC_B    , KC_NO, KC_NO , KC_N   , RALT_T(KC_M) , RGUI_T(KC_COMM) , RCTL_T(KC_DOT) , RSFT_T(KC_SCLN) ,
            LT(_MOUSE_34, KC_Z)  , KC_NO        , KC_NO        , TD(TESYM)    , KC_BSPC , KC_NO, KC_NO , KC_SPC , NUMENT       , KC_NO           , KC_NO          , KC_QUOT
            ),

    /* Symbols
     * ,-----------------------------------------------------------------------------------.
     * |      |   !  |   @  |   #  |   (  |      |      |  { [ |  | \ |  _ - |  + = |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TAB  |   ^  |   &  |   *  |   )  |      |      |  } ] |  ? / |   %  |   $  |  °   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |LCRL_T|LMTA_T|LALT_T|      |      |      |      |RALT_T|RMTA_T|RCTL_T| RSFT |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ESC~`|      |      |TESYM | Bksp |             |Space |NUMENT|      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_SYMBOLS_34] = LAYOUT_ortho_4x12(
            KC_NO   , KC_EXLM , KC_AT   , KC_HASH , KC_LPRN , KC_NO, KC_NO , KC_LBRC , KC_BSLS , KC_MINS  , KC_EQL  , KC_NO     ,
            KC_TAB  , KC_CIRC , KC_AMPR , KC_ASTR , KC_RPRN , KC_NO, KC_NO , KC_RBRC , KC_SLSH , KC_PERC  , KC_DLR  , RSA(KC_0) ,
            KC_LSFT , _______ , _______ , _______ , KC_NO   , KC_NO, KC_NO , KC_NO   , _______ , _______  , _______ , KC_RSFT   ,
            QK_GESC , KC_NO   , KC_NO   , _______ , _______ , KC_NO, KC_NO , _______ , _______ , KC_NO    , KC_NO   , KC_NO
            ),

    /* Mouse
     * ,-----------------------------------------------------------------------------------.
     * |      |      |WHELUP|      |      |      |      |      |LFTCLK|MOSEUP|RGTCLK|      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |LFTCLK|WHELDN|RGTCLK|      |      |      |      |MOSLFT|MOSEDN|MOSRGT|TG MOS|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |LCRL_T|LMTA_T|LALT_T|      |      |      |      |RALT_T|RMTA_T|RCTL_T| RSFT |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ESC~`|      |      |TESYM | Bksp |             |Space |NUMENT|      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_MOUSE_34] = LAYOUT_ortho_4x12(
            KC_NO   , KC_NO   , KC_WH_U , KC_NO   , KC_NO   , KC_NO , KC_NO , KC_NO   , KC_BTN1 , KC_MS_U , KC_BTN2 , KC_NO         ,
            KC_NO   , KC_BTN1 , KC_WH_D , KC_BTN2 , KC_NO   , KC_NO , KC_NO , KC_NO   , KC_MS_L , KC_MS_D , KC_MS_R , TG(_MOUSE_34) ,
            _______ , _______ , _______ , _______ , KC_NO   , KC_NO , KC_NO , KC_NO   , _______ , _______ , _______ , _______       ,
            _______ , KC_NO   , KC_NO   , _______ , _______ , KC_NO , KC_NO , _______ , _______ , KC_NO   , KC_NO   , KC_NO
            ),

    /* Navigation/Numbers
     * ,-----------------------------------------------------------------------------------.
     * | INS  | HOME |  UP  |  END | PGUP |      |      |  ? / |  & 7 |  * 8 |  ( 9 |  +   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT | LEFT | DOWN | RGHT | PGDN |      |      |  ) 0 |  ! 1 |  @ 2 |  # 3 |  _ - |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | DEL  |LCRL_T|LMTA_T|LALT_T| RALT |      |      |   *  |  $ 4 |  % 5 |  ^ 6 |  + = |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |TESYM | Bksp |             |Space |NUMENT|      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_NUMBERS_34] = LAYOUT_ortho_4x12(
            KC_NO   , KC_HOME , KC_UP   , KC_END  , KC_PGUP , KC_NO, KC_NO , KC_SLSH , KC_7    , KC_8  , KC_9  , KC_PPLS ,
            KC_INS  , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGDN , KC_NO, KC_NO , KC_0    , KC_1    , KC_2  , KC_3  , KC_PPLS ,
            KC_LSFT , _______ , _______ , _______ , KC_RALT , KC_NO, KC_NO , KC_ASTR , KC_4    , KC_5  , KC_6  , KC_MINS ,
            KC_DEL  , KC_NO   , KC_NO   , _______ , _______ , KC_NO, KC_NO , _______ , _______ , KC_NO , KC_NO , KC_EQL
            ),


    /* Functions
     * ,-----------------------------------------------------------------------------------.
     * |      |DVORAK| MAYA |QWERTY| VOL+ |      |      |  F1  |  F2  |  F3  |  F4  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | RESET|      |      |      | VOL- |      |      |  F5  |  F6  |  F7  |  F8  |TG MOS|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |LCRL_T|LMTA_T|LALT_T| MUTE |      |      |  F9  | F10  | F11  | F12  | RSFT |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |TESYM | Bksp |             |Space |NUMENT|      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_FUNCTION_34] = LAYOUT_ortho_4x12(
            KC_NO   , DF(_DVORAK_34) , DF(_MAYA_34)   , DF(_QWERTY_34) , KC_VOLU , KC_NO , KC_NO , KC_F1   , KC_F2   , KC_F3  , KC_F4  , KC_NO         ,
            QK_BOOT , KC_NO          , KC_NO          , KC_NO          , KC_VOLD , KC_NO , KC_NO , KC_F5   , KC_F6   , KC_F7  , KC_F8  , TG(_MOUSE_34) ,
            _______ , _______        , _______        , _______        , KC_MUTE , KC_NO , KC_NO , KC_F9   , KC_F10  , KC_F11 , KC_F12 , KC_RSFT       ,
            KC_NO   , KC_NO          , KC_NO          , _______        , _______ , KC_NO , KC_NO , _______ , _______ , KC_NO  , KC_NO  , KC_NO
            ),
};


/* ------------------ KEY OVERRIDE ------------------- */

const key_override_t bkspc_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &bkspc_key_override,
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
        my_dvorak_layer,
        my_maya_layer,
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
    rgblight_set_layer_state(0, layer_state_cmp(state, _DVORAK_34));
    rgblight_set_layer_state(1, layer_state_cmp(state, _MAYA_34));
    rgblight_set_layer_state(2, layer_state_cmp(state, _QWERTY_34));

    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _SYMBOLS_34, _NUMBERS_34, _FUNCTION_34);

    rgblight_set_layer_state(3, layer_state_cmp(state, _SYMBOLS_34));
    rgblight_set_layer_state(4, layer_state_cmp(state, _NUMBERS_34));
    rgblight_set_layer_state(5, layer_state_cmp(state, _MOUSE_34));
    rgblight_set_layer_state(6,  layer_state_cmp(state, _FUNCTION_34));

    return state;
}


/* ------------------- TAP DANCE ------------------- */

// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t tesym_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void tesym_finished(tap_dance_state_t *state, void *user_data) {
    tesym_tap_state.state = cur_dance(state);
    switch (tesym_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_TAB);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_SYMBOLS_34);
            break;
        case TD_DOUBLE_TAP:
            tap_code(KC_ESC);
            break;
        default:
            break;
    }
}

void tesym_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (tesym_tap_state.state == TD_SINGLE_HOLD) {
            layer_off(_SYMBOLS_34);
    }
    tesym_tap_state.state = TD_NONE;
}

// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
    [TESYM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tesym_finished, tesym_reset)
};


/* ------------------- ENCODER ------------------- */

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

