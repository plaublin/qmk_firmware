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
  //|----------------+----------------+----------------+----------------+----------------|      |----------------+----------------+----------------+----------------+----------------|
     KC_B            , KC_L           , KC_D           , KC_G           , KC_Q           ,       KC_K            , KC_F           , KC_O           , KC_U           , KC_SLSH        ,
  //|----------------+----------------+----------------+----------------+----------------|      |----------------+----------------+----------------+----------------+----------------|
     LSFT_T(KC_N)    , KC_R           , KC_T           , KC_S           , KC_V           ,       KC_Y            , KC_H           , KC_A           , KC_E           , RSFT_T(KC_I)   ,
  //|----------------+----------------+----------------+----------------+----------------|      |----------------+----------------+----------------+----------------+----------------|
     LT(_MOUSE, KC_Z), LCTL_T(KC_X)   , LGUI_T(KC_M)   , LALT_T(KC_C)   , KC_W           ,       KC_J            , RALT_T(KC_P)   , RGUI_T(KC_QUOT), RCTL_T(KC_COMM), KC_DOT         ,
  //|----------------+----------------+----------------+----------------+----------------|      |----------------+----------------+----------------+----------------+----------------|
                                       KC_NO           , TD(TESYM)      , KC_BSPC        ,       KC_SPC          , NUMENT         , KC_NO
                                    //`--------------------------------------------------'      `-----------------------------------------------'
  ),

  [_QWERTY] = LAYOUT_split_3x5_3(
  //|----------------+----------------+----------------+----------------+----------------|      |----------------+----------------+----------------+----------------+----------------|
     KC_Q            , KC_W           , KC_E           , KC_R           , KC_T           ,       KC_Y            , KC_U           , KC_I           , KC_O           , KC_P           ,
  //|----------------+----------------+----------------+----------------+----------------|      |----------------+----------------+----------------+----------------+----------------|
     LSFT_T(KC_A)    , KC_S           , KC_D           , KC_F           , KC_G           ,       KC_H            , KC_J           , KC_K           , KC_L           , RSFT_T(KC_SCLN),
  //|----------------+----------------+----------------+----------------+----------------|      |----------------+----------------+----------------+----------------+----------------|
     LT(_MOUSE, KC_A), LCTL_T(KC_X)   , LGUI_T(KC_C)   , LALT_T(KC_V)   , KC_B           ,       KC_N            , RALT_T(KC_M)   , RGUI_T(KC_COMM), RCTL_T(KC_DOT) , KC_QUOT        ,
  //|----------------+----------------+----------------+----------------+----------------|      |----------------+----------------+----------------+----------------+----------------|
                                       KC_NO           , TD(TESYM)      , KC_BSPC        ,       KC_SPC          , NUMENT         , KC_NO
                                    //`--------------------------------------------------'      `-----------------------------------------------'
  ),

  //TODO we could add the accents in this layer, replacing the L*_T with new ones
  [_SYMBOLS] = LAYOUT_split_3x5_3(
  //|----------------+----------------+----------------+----------------+----------------|      |----------------+----------------+----------------+----------------+----------------|
     KC_TAB          , KC_EXLM        , KC_AT          , KC_HASH        , KC_LPRN        ,       KC_LBRC         , KC_BSLS        , KC_MINS        , KC_EQL         , RSA(KC_0)      ,
  //|----------------+----------------+----------------+----------------+----------------|      |----------------+----------------+----------------+----------------+----------------|
     KC_LSFT         , KC_CIRC        , KC_AMPR        , KC_ASTR        , KC_RPRN        ,       KC_RBRC         , KC_SLSH        , KC_PERC        , KC_DLR         , KC_RSFT        ,
  //|----------------+----------------+----------------+----------------+----------------|      |----------------+----------------+----------------+----------------+----------------|
     QK_GESC         , _______        , _______        , _______        , KC_NO          ,       KC_NO           , _______        , _______        , _______        , KC_NO          ,
  //|----------------+----------------+----------------+----------------+----------------|      |----------------+----------------+----------------+----------------+----------------|
                                       KC_NO           , _______        , _______        ,       _______         , _______        , KC_NO
                                    //`--------------------------------------------------'      `-----------------------------------------------'
  ),

  [_MOUSE] = LAYOUT_split_3x5_3(
  //|----------------+----------------+----------------+----------------+----------------|      |----------------+----------------+----------------+----------------+----------------|
     KC_NO           , KC_BTN3        , KC_WH_U        , KC_NO          , KC_NO          ,       KC_BTN3         , KC_BTN1        , KC_MS_U        , KC_BTN2        , TG(_MOUSE)     ,
  //|----------------+----------------+----------------+----------------+----------------|      |----------------+----------------+----------------+----------------+----------------|
     KC_LSFT         , KC_BTN1        , KC_WH_D        , KC_BTN2        , KC_NO          ,       KC_NO           , KC_MS_L        , KC_MS_D        , KC_MS_R        , _______        ,
  //|----------------+----------------+----------------+----------------+----------------|      |----------------+----------------+----------------+----------------+----------------|
     _______         , _______        , _______        , _______        , KC_NO          ,       KC_NO           , _______        , _______        , _______        , KC_NO          ,
  //|----------------+----------------+----------------+----------------+----------------|      |----------------+----------------+----------------+----------------+----------------|
                                       KC_NO           , _______        , _______        ,       _______         , _______        , KC_NO
                                    //`--------------------------------------------------'      `-----------------------------------------------'
  ),

  [_NUMBERS] = LAYOUT_split_3x5_3(
  //|----------------+----------------+----------------+----------------+----------------|      |----------------+----------------+----------------+----------------+----------------|
     KC_INS          , KC_HOME        , KC_UP          , KC_END         , KC_PGUP        ,       KC_SLSH         , KC_7           , KC_8           , KC_9           , KC_ASTR        ,
  //|----------------+----------------+----------------+----------------+----------------|      |----------------+----------------+----------------+----------------+----------------|
     _______         , KC_LEFT        , KC_DOWN        , KC_RGHT        , KC_PGDN        ,       KC_0            , KC_1           , KC_2           , KC_3           , KC_MINS        ,
  //|----------------+----------------+----------------+----------------+----------------|      |----------------+----------------+----------------+----------------+----------------|
     KC_DEL          , _______        , _______        , _______        , KC_RALT        ,       KC_DOT          , KC_4           , KC_5           , KC_6           , KC_EQL         ,
  //|----------------+----------------+----------------+----------------+----------------|      |----------------+----------------+----------------+----------------+----------------|
                                       KC_NO           , _______        , _______        ,       _______         , _______        , KC_NO
                                    //`--------------------------------------------------'      `-----------------------------------------------'
  ),

  [_FUNCTION] = LAYOUT_split_3x5_3(
  //|----------------+----------------+----------------+----------------+----------------|      |----------------+----------------+----------------+----------------+----------------|
     DF(_QWERTY)     , KC_NO          , KC_NO          , KC_MPLY        , KC_VOLU        ,       KC_F1           , KC_F2          , KC_F3          , KC_F4          , TG(_MOUSE)     ,
  //|----------------+----------------+----------------+----------------+----------------|      |----------------+----------------+----------------+----------------+----------------|
     DF(_MAYA)       , KC_NO          , KC_NO          , KC_MSTP        , KC_VOLD        ,       KC_F5           , KC_F6          , KC_F7          , KC_F8          , KC_NO          ,
  //|----------------+----------------+----------------+----------------+----------------|      |----------------+----------------+----------------+----------------+----------------|
     QK_BOOT         , _______        , _______        , _______        , KC_MUTE        ,       KC_F9           , KC_F10         , KC_F11         , KC_F12         , KC_NO          ,
  //|----------------+----------------+----------------+----------------+----------------|      |----------------+----------------+----------------+----------------+----------------|
                                       KC_NO           , _______        , _______        ,       _______         , _______        , KC_NO
                                    //`--------------------------------------------------'      `-----------------------------------------------'
  ),
};


/* ------------------ KEY OVERRIDE ------------------- */

const key_override_t bkspc_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t numdot_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_COMM, _NUMBERS);
const key_override_t up_key_override     = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, KC_UP, KC_PGUP, ~0, MOD_MASK_GUI);
const key_override_t dn_key_override     = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, KC_DOWN, KC_PGDN, ~0, MOD_MASK_GUI);
const key_override_t left_key_override   = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, KC_LEFT, KC_HOME, ~0, MOD_MASK_GUI);
const key_override_t right_key_override  = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, KC_RGHT, KC_END, ~0, MOD_MASK_GUI);

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

const uint16_t PROGMEM semi_combo[]  = {KC_COMM, KC_DOT, COMBO_END};
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

