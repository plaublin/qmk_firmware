/*
   Copyright 2019 @foostan
   Copyright 2020 Drashna Jaelre <@drashna>

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.If not, see <http://www.gnu.org/licenses/>.
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

enum planck_layers {
    _FOCUS,
    _QWERTY,
    _SYMBOLS,
    _NUM,
    _MOUSE,
    _FUNCTION,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_FOCUS] = LAYOUT_split_3x5_3(
            KC_V, KC_L, KC_H, KC_G, KC_K,KC_Q, KC_F, KC_O, KC_U, KC_J,
            KC_S, KC_R, KC_N, KC_T, KC_B,KC_Y, KC_C, KC_E, KC_A, KC_I,
            KC_Z, KC_X, KC_M, KC_D, KC_P,KC_QUOT, KC_W, KC_DOT, KC_SCLN, KC_COMM,
            KC_LSFT, TD(TESYM), KC_SPC,KC_BSPC, LT(_NUM,KC_ENT KC_NO
            ),

    [_QWERTY] = LAYOUT_split_3x5_3(
            KC_Q, KC_W, KC_E, KC_R, KC_T,KC_Y, KC_U, KC_I, KC_O, KC_P,
            KC_A, KC_S, KC_D, KC_F, KC_G,KC_H, KC_J, KC_K, KC_L, KC_SCLN,
            KC_Z, KC_X, KC_C, KC_V, KC_B,KC_N, KC_M, KC_COMM, KC_DOT , KC_QUOT,
            KC_LSFT, TD(TESYM), KC_SPC ,KC_BSPC ,LT(_NUM,KC_ENT), KC_NO
            ),

    //Top row contains everything for the French accentued letters:
    // é
    // ` then press a letter for the grave accent (è, à, ù)
    // ç
    // ^ then press a letter for the circonflexe accent (ê, ô, â, î, û)
    // " then press a letter for the 2 dots accent (ï, ü, ë)
    [_SYMBOLS] = LAYOUT_split_3x5_3(
            KC_TAB , KC_GRV , RALT(KC_E) , RALT(KC_GRV) , RALT(KC_COMM),RALT(KC_6) , KC_LCBR, KC_RCBR, RSA(KC_QUOT) , RSA(KC_0),
            OSM(MOD_LSFT), KC_CIRC, KC_EXLM, KC_AT, KC_HASH,KC_SLSH, KC_LPRN, KC_RPRN, KC_AMPR, KC_DLR ,
            KC_ESC , OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_RALT),KC_BSLS, KC_LBRC, KC_RBRC, KC_PERC, KC_NO,
            _______, _______, _______,_______, _______, KC_NO
    ),

    [_MOUSE] = LAYOUT_split_3x5_3(
            TG(_MOUSE) , KC_BTN3, KC_WH_U, KC_NO, KC_NO,KC_BTN3, KC_BTN1, KC_MS_U, KC_BTN2, KC_NO,
            OSM(MOD_LSFT), KC_BTN1, KC_WH_D, KC_BTN2, KC_NO,KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, OSM(MOD_RSFT),
            KC_ESC , OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), KC_NO,KC_NO, OSM(MOD_RGUI), OSM(MOD_RALT), OSM(MOD_RCTL), KC_NO,
            _______, _______, _______,_______, _______, KC_NO
    ),

    [_NUM] = LAYOUT_split_3x5_3(
            KC_INS , KC_HOME, KC_UP, KC_END , KC_DEL ,KC_SLSH, KC_7, KC_8, KC_9, KC_ASTR,
            OSM(MOD_LSFT), KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP,KC_0, KC_1, KC_2, KC_3, KC_MINS,
            KC_ESC , OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), KC_PGDN,KC_EQL , KC_4, KC_5, KC_6, KC_DOT ,
            _______, _______, _______,_______, _______, KC_NO
    ),

    [_FUNCTION] = LAYOUT_split_3x5_3(
            TT(_MOUSE) , DF(_FOCUS) , DF(_QWERTY), KC_MPLY, KC_VOLU,KC_F1, KC_F2, KC_F3, KC_F4, KC_DEL ,
            KC_LSFT, QK_BOOT, KC_NO, KC_MSTP, KC_VOLD,KC_F5, KC_F6, KC_F7, KC_F8, KC_NO,
            KC_ESC , KC_LCTL, KC_LALT, KC_LGUI, KC_MUTE,KC_F9, KC_F10 , KC_F11 , KC_F12 , KC_NO,
            _______, _______, _______,_______, _______, KC_NO
    ),
};


/* ------------------ KEY OVERRIDE ------------------- */

const key_override_t bkspc_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t numdot_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_COMM, 1 << _NUM);
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


/* ------------------- TRI LAYER ------------------- */

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _SYMBOLS, _NUM, _FUNCTION);
    return state;
}


/* -------------------- COMBOS --------------------- */

//const uint16_t PROGMEM semi_combo[]= {KC_COMM, KC_DOT, COMBO_END};
//const uint16_t PROGMEM semi_combo2[] = {RCTL_T(KC_COMM), KC_DOT, COMBO_END};
//
combo_t key_combos[] = {
    //COMBO(semi_combo, KC_SCLN),
    //COMBO(semi_combo2, KC_SCLN),
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

