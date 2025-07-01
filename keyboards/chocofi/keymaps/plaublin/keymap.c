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

/* ------------------- LAYERS ------------------- */

enum planck_layers {
    _GALLIUM,
    _QWERTY,
    _SYMBOLS,
    _NUMBERS,
    _MOUSE,
    _FUNCTION,
};

#define LT_SYMESC LT(_SYMBOLS, KC_ESC)
#define LT_NUMBSP LT(_NUMBERS, KC_BSPC)
#define MT_SFTSPC MT(MOD_LSFT, KC_SPC)
#define MT_SFTENT MT(MOD_LSFT, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_GALLIUM] = LAYOUT_split_3x5_3(
            KC_B, KC_L, KC_D , KC_C     , KC_V     ,        KC_J , KC_F , KC_O    , KC_U    , KC_COMM ,
            KC_N, KC_R, KC_T , KC_S     , KC_G     ,        KC_Y , KC_H , KC_A    , KC_E    , KC_I    ,
            KC_X, KC_Q, KC_M , KC_W     , KC_Z     ,        KC_K , KC_P , KC_QUOT , KC_SCLN , KC_DOT  ,
                        KC_NO, LT_SYMESC, MT_SFTSPC,        MT_SFTENT, LT_NUMBSP, KC_NO
                        KC_NO, LT_SYMESC, MT_SFTSPC,        MT_SFTENT, LT_NUMBSP, KC_NO
            ),

    [_QWERTY] = LAYOUT_split_3x5_3(
            KC_Q, KC_W, KC_E , KC_R     , KC_T     ,        KC_Y     , KC_U     , KC_I   , KC_O  , KC_P   ,
            KC_A, KC_S, KC_D , KC_F     , KC_G     ,        KC_H     , KC_J     , KC_K   , KC_L  , KC_SCLN,
            KC_Z, KC_X, KC_C , KC_V     , KC_B     ,        KC_N     , KC_M     , KC_COMM, KC_DOT, KC_QUOT,
                        KC_NO, LT_SYMESC, MT_SFTSPC,        MT_SFTENT, LT_NUMBSP, KC_NO
            ),

    //Top row contains everything for the French accentued letters:
    // " then press a letter for the 2 dots accent (ï, ü, ë)
    // ^ then press a letter for the circonflexe accent (ê, ô, â, î, û)
    // ç
    // é
    // ` then press a letter for the grave accent (è, à, ù)
    // frequence order: é ` ç ^ "
    [_SYMBOLS] = LAYOUT_split_3x5_3(
            KC_GRV       , RALT(KC_QUOT), RALT(KC_6)   , RALT(KC_COMM), RALT(KC_E),         RSA(KC_GRV) , KC_LCBR, KC_RCBR, KC_AMPR, KC_LT,
            KC_CIRC      , KC_EXLM      , KC_AT        , KC_HASH      , KC_PERC   ,         RSA(KC_0)   , KC_LPRN, KC_RPRN, KC_SLSH, KC_DLR,
            OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), KC_TAB       , TT(_MOUSE),         KC_NO       , KC_LBRC, KC_RBRC, KC_BSLS, KC_GT,
                                          _______      , _______      , _______   ,         _______     , _______, _______
            ),

    [_MOUSE] = LAYOUT_split_3x5_3(
            KC_NO  , KC_BTN3, KC_WH_U, QK_GESC, KC_NO     ,         KC_BTN3, KC_BTN1, KC_MS_U, KC_BTN2, KC_NO  ,
            KC_NO  , KC_BTN1, KC_WH_D, KC_BTN2, KC_NO     ,         KC_NO  , KC_MS_L, KC_MS_D, KC_MS_R, KC_NO  ,
            KC_LGUI, KC_LALT, KC_LCTL, KC_TAB , TG(_MOUSE),         KC_NO  , KC_NO  , KC_RCTL, KC_RALT, KC_RGUI,
                              _______, _______, _______   ,         _______, _______, _______
            ),

    [_NUMBERS] = LAYOUT_split_3x5_3(
            KC_INS       , KC_HOME      , KC_UP        , KC_END , KC_DEL  ,         KC_SLSH, KC_7   , KC_8   , KC_9, KC_ASTR,
            QK_GESC      , KC_LEFT      , KC_DOWN      , KC_RGHT, KC_PGUP ,         KC_0   , KC_1   , KC_2   , KC_3, KC_MINS,
            OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), KC_TAB , KC_PGDN ,         KC_EQL , KC_4   , KC_5   , KC_6, KC_DOT ,
                                          _______      , _______, _______ ,         _______, _______, _______
            ),

    [_FUNCTION] = LAYOUT_split_3x5_3(
            KC_DEL , KC_F1, KC_F2  , KC_F3  , KC_F4  , KC_MPLY, KC_VOLU, DF(_GALLIUM) , DF(_QWERTY)   , TT(_MOUSE),
            QK_GESC, KC_F5, KC_F6  , KC_F7  , KC_F8  , KC_MSTP, KC_VOLD, KC_NO        , KC_NO         , KC_NO     ,
            KC_PSCR, KC_F9, KC_F10 , KC_F11 , KC_F12 , KC_NO  , KC_MUTE, KC_NO        , OSM(MOD_RALT) , QK_BOOT   ,
                            _______, _______, _______, _______, _______, _______
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


/* ------------------- TRI LAYER ------------------- */

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _SYMBOLS, _NUMBERS, _FUNCTION);
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

