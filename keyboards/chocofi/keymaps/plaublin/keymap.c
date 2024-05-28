/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
#define NUMENT LT(_NUMBERS, KC_ENT)

enum planck_layers {
    _MAYA,
    _QWERTY,
    _SYMBOLS,
    _NUMBERS,
    _MOUSE,
    _FUNCTION,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAYA] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                     ,--------------------------------------------.
        KC_B,    KC_L,    KC_D,    KC_G,    KC_Q,                          KC_K,    KC_F,    KC_O,    KC_U,  KC_SLSH ,
  //|--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------|
     LSFT_T(KC_N), KC_R, KC_T, KC_S, KC_V,                                 KC_Y,      KC_H,     KC_A,   KC_E, RSFT_T(KC_I),
  //|--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------|
     LT(_MOUSE, KC_Z), LCTL_T(KC_X), LGUI_T(KC_M), LALT_T(KC_C), KC_W, KC_J, RALT_T(KC_P), RGUI_T(KC_QUOT), RCTL_T(KC_COMM), KC_DOT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
                                KC_NO, TD(TESYM),  KC_BSPC,       KC_SPC, NUMENT, KC_NO
                             //`--------------------------'   `--------------------------'
  ),

  [_QWERTY] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                     ,--------------------------------------------.
        KC_B,    KC_L,    KC_D,    KC_G,    KC_Q,                          KC_K,    KC_F,    KC_O,    KC_U,  KC_SLSH ,
  //|--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------|
     LSFT(KC_N), KC_R, KC_T, KC_S, KC_V,                                 KC_Y,      KC_H,     KC_A,   KC_E, RSFT(KC_I),
  //|--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------|
     LT(_MOUSE, KC_Z), LCTL_T(KC_X), LGUI_T(KC_M), LALT_T(KC_C), KC_W, KC_J, RALT_T(KC_P), RGUI_T(KC_QUOT), RCTL_T(KC_COMM), KC_DOT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
                                KC_NO, TD(TESYM),  KC_BSPC,       KC_SPC, NUMENT, KC_NO
                             //`--------------------------'   `--------------------------'
  ),

  [_SYMBOLS] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                     ,--------------------------------------------.
        KC_B,    KC_L,    KC_D,    KC_G,    KC_Q,                          KC_K,    KC_F,    KC_O,    KC_U,  KC_SLSH ,
  //|--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------|
     LSFT(KC_N), KC_R, KC_T, KC_S, KC_V,                                 KC_Y,      KC_H,     KC_A,   KC_E, RSFT(KC_I),
  //|--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------|
     LT(_MOUSE, KC_Z), LCTL_T(KC_X), LGUI_T(KC_M), LALT_T(KC_C), KC_W, KC_J, RALT_T(KC_P), RGUI_T(KC_QUOT), RCTL_T(KC_COMM), KC_DOT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
                                KC_NO, TD(TESYM),  KC_BSPC,       KC_SPC, NUMENT, KC_NO
                             //`--------------------------'   `--------------------------'
  ),

  [_NUMBERS] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                     ,--------------------------------------------.
        KC_B,    KC_L,    KC_D,    KC_G,    KC_Q,                          KC_K,    KC_F,    KC_O,    KC_U,  KC_SLSH ,
  //|--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------|
     LSFT(KC_N), KC_R, KC_T, KC_S, KC_V,                                 KC_Y,      KC_H,     KC_A,   KC_E, RSFT(KC_I),
  //|--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------|
     LT(_MOUSE, KC_Z), LCTL_T(KC_X), LGUI_T(KC_M), LALT_T(KC_C), KC_W, KC_J, RALT_T(KC_P), RGUI_T(KC_QUOT), RCTL_T(KC_COMM), KC_DOT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
                                KC_NO, TD(TESYM),  KC_BSPC,       KC_SPC, NUMENT, KC_NO
                             //`--------------------------'   `--------------------------'
  ),


  [_MOUSE] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                     ,--------------------------------------------.
        KC_B,    KC_L,    KC_D,    KC_G,    KC_Q,                          KC_K,    KC_F,    KC_O,    KC_U,  KC_SLSH ,
  //|--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------|
     LSFT(KC_N), KC_R, KC_T, KC_S, KC_V,                                 KC_Y,      KC_H,     KC_A,   KC_E, RSFT(KC_I),
  //|--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------|
     LT(_MOUSE, KC_Z), LCTL_T(KC_X), LGUI_T(KC_M), LALT_T(KC_C), KC_W, KC_J, RALT_T(KC_P), RGUI_T(KC_QUOT), RCTL_T(KC_COMM), KC_DOT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
                                KC_NO, TD(TESYM),  KC_BSPC,       KC_SPC, NUMENT, KC_NO
                             //`--------------------------'   `--------------------------'
  ),

  [_FUNCTION] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                     ,--------------------------------------------.
        KC_B,    KC_L,    KC_D,    KC_G,    KC_Q,                          KC_K,    KC_F,    KC_O,    KC_U,  KC_SLSH ,
  //|--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------|
     LSFT(KC_N), KC_R, KC_T, KC_S, KC_V,                                 KC_Y,      KC_H,     KC_A,   KC_E, RSFT(KC_I),
  //|--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------|
     LT(_MOUSE, KC_Z), LCTL_T(KC_X), LGUI_T(KC_M), LALT_T(KC_C), KC_W, KC_J, RALT_T(KC_P), RGUI_T(KC_QUOT), RCTL_T(KC_COMM), KC_DOT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
                                KC_NO, TD(TESYM),  KC_BSPC,       KC_SPC, NUMENT, KC_NO
                             //`--------------------------'   `--------------------------'
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
    [_QWERTY] = LAYOUT_ortho_4x12(
            KC_NO                , KC_W         , KC_E         , KC_R         , KC_T    , KC_NO , KC_NO , KC_Y   , KC_U         , KC_I            , KC_O           , KC_NO           ,
            KC_Q                 , KC_S         , KC_D         , KC_F         , KC_G    , KC_NO , KC_NO , KC_H   , KC_J         , KC_K            , KC_L           , KC_P            ,
            LSFT_T(KC_A)         , LCTL_T(KC_X) , LGUI_T(KC_C) , LALT_T(KC_V) , KC_B    , KC_NO , KC_NO , KC_N   , RALT_T(KC_M) , RGUI_T(KC_COMM) , RCTL_T(KC_DOT) , RSFT_T(KC_SCLN) ,
            LT(_MOUSE, KC_Z)  , KC_NO        , KC_NO        , TD(TESYM)    , KC_BSPC , KC_NO , KC_NO , KC_SPC , NUMENT       , KC_NO           , KC_NO          , KC_QUOT
            ),

     * Symbols
     * ,-----------------------------------------------------------------------------------.
     * |      |   !  |   @  |   #  |   (  |      |      |  { [ |  | \ |  _ - |  + = |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TAB  |   ^  |   &  |   *  |   )  |      |      |  } ] |  ? / |   %  |   $  |  °   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |LCRL_T|LMTA_T|LALT_T|      |      |      |      |RALT_T|RMTA_T|RCTL_T| RSFT |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ESC~`|      |      |TESYM | Bksp |             |Space |NUMENT|      |      |      |
     * `-----------------------------------------------------------------------------------'
     *
    [_SYMBOLS] = LAYOUT_ortho_4x12(
            KC_NO   , KC_EXLM , KC_AT   , KC_HASH , KC_LPRN , KC_NO , KC_NO , KC_LBRC , KC_BSLS , KC_MINS  , KC_EQL  , KC_NO     ,
            KC_TAB  , KC_CIRC , KC_AMPR , KC_ASTR , KC_RPRN , KC_NO , KC_NO , KC_RBRC , KC_SLSH , KC_PERC  , KC_DLR  , RSA(KC_0) ,
            KC_LSFT , _______ , _______ , _______ , KC_NO   , KC_NO , KC_NO , KC_NO   , _______ , _______  , _______ , KC_RSFT   ,
            QK_GESC , KC_NO   , KC_NO   , _______ , _______ , KC_NO , KC_NO , _______ , _______ , KC_NO    , KC_NO   , KC_NO
            ),

     * Mouse
     * ,-----------------------------------------------------------------------------------.
     * |      |      |WHELUP|      |      |      |      |      |LFTCLK|MOSEUP|RGTCLK|      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |LFTCLK|WHELDN|RGTCLK|      |      |      |      |MOSLFT|MOSEDN|MOSRGT|TG MOS|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |LCRL_T|LMTA_T|LALT_T|      |      |      |      |RALT_T|RMTA_T|RCTL_T| RSFT |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ESC~`|      |      |TESYM | Bksp |             |Space |NUMENT|      |      |      |
     * `-----------------------------------------------------------------------------------'
     *
    [_MOUSE] = LAYOUT_ortho_4x12(
            KC_NO   , KC_NO   , KC_WH_U , KC_NO   , KC_NO   , KC_NO , KC_NO , KC_NO   , KC_BTN1 , KC_MS_U , KC_BTN2 , KC_NO         ,
            KC_NO   , KC_BTN1 , KC_WH_D , KC_BTN2 , KC_NO   , KC_NO , KC_NO , KC_NO   , KC_MS_L , KC_MS_D , KC_MS_R , TG(_MOUSE) ,
            _______ , _______ , _______ , _______ , KC_NO   , KC_NO , KC_NO , KC_NO   , _______ , _______ , _______ , _______       ,
            _______ , KC_NO   , KC_NO   , _______ , _______ , KC_NO , KC_NO , _______ , _______ , KC_NO   , KC_NO   , KC_NO
            ),

     * Navigation/Numbers
     * ,-----------------------------------------------------------------------------------.
     * | INS  | HOME |  UP  |  END | PGUP |      |      |  ? / |  & 7 |  * 8 |  ( 9 |  +   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT | LEFT | DOWN | RGHT | PGDN |      |      |  ) 0 |  ! 1 |  @ 2 |  # 3 |  _ - |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | DEL  |LCRL_T|LMTA_T|LALT_T| RALT |      |      |   *  |  $ 4 |  % 5 |  ^ 6 |  + = |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |TESYM | Bksp |             |Space |NUMENT|      |      |      |
     * `-----------------------------------------------------------------------------------'
     *
    [_NUMBERS] = LAYOUT_ortho_4x12(
            KC_NO   , KC_HOME , KC_UP   , KC_END  , KC_PGUP , KC_NO , KC_NO , KC_SLSH , KC_7    , KC_8  , KC_9  , KC_PPLS ,
            KC_INS  , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGDN , KC_NO , KC_NO , KC_0    , KC_1    , KC_2  , KC_3  , KC_PPLS ,
            KC_LSFT , _______ , _______ , _______ , KC_RALT , KC_NO , KC_NO , KC_ASTR , KC_4    , KC_5  , KC_6  , KC_MINS ,
            KC_DEL  , KC_NO   , KC_NO   , _______ , _______ , KC_NO , KC_NO , _______ , _______ , KC_NO , KC_NO , KC_EQL
            ),


     * Functions
     * ,-----------------------------------------------------------------------------------.
     * |      | MAYA |QWERTY|MPLAY | VOL+ |      |      |  F1  |  F2  |  F3  |  F4  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |TG MOS|      |MSTOP | VOL- |      |      |  F5  |  F6  |  F7  |  F8  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |LCRL_T|LMTA_T|LALT_T| MUTE |      |      |  F9  | F10  | F11  | F12  | RSFT |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |RESET |      |      |TESYM | Bksp |             |Space |NUMENT|      |      |      |
     * `-----------------------------------------------------------------------------------'
     *
    [_FUNCTION] = LAYOUT_ortho_4x12(
            KC_NO   , DF(_MAYA) , DF(_QWERTY) , KC_MPLY , KC_VOLU , KC_NO , KC_NO , KC_F1   , KC_F2   , KC_F3  , KC_F4  , KC_NO          ,
            KC_NO   , TG(_MOUSE)   , KC_NO          , KC_MSTP , KC_VOLD , KC_NO , KC_NO , KC_F5   , KC_F6   , KC_F7  , KC_F8  , KC_NO  ,
            _______ , _______        , _______        , _______ , KC_MUTE , KC_NO , KC_NO , KC_F9   , KC_F10  , KC_F11 , KC_F12 , KC_RSFT        ,
            QK_BOOT , KC_NO          , KC_NO          , _______ , _______ , KC_NO , KC_NO , _______ , _______ , KC_NO  , KC_NO  , KC_NO
            ),
    */
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

/* -------------------- COMBOS --------------------- */

const uint16_t PROGMEM semi_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM semi_combo2[] = {RCTL_T(KC_COMM), KC_DOT, COMBO_END};

combo_t key_combos[] = {
    COMBO(semi_combo, KC_SCLN),
    COMBO(semi_combo2, KC_SCLN),
};

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
            layer_on(_SYMBOLS);
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
            layer_off(_SYMBOLS);
    }
    tesym_tap_state.state = TD_NONE;
}

// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
    [TESYM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tesym_finished, tesym_reset)
};

