#include QMK_KEYBOARD_H

enum planck_layers {
    _GRAPHITE,
    _QWERTY,
    _SYMBOLS,
    _FUNCTION,
};

#define LT_SYMESC LT(_SYMBOLS, KC_ESC)
#define LT_FNBSPC LT(_FUNCTION, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* GRAPHITE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ` ~  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | = +  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   B  |   L  |   D  |   W  |   Z  |                    | ' "  |   F  |   O  |   U  |   J  | ; :  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   N  |   R  |   T  |   S  |   G  |-------.    ,-------|   Y  |   H  |   A  |   E  |   I  | , <  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Q  |   X  |   M  |   C  |   V  |-------|    |-------|   K  |   P  | . <  | - _  | / ?  | \ |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |SYMESC| / SPACE /       \ENTER \  |FNBSPC| RALT | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_GRAPHITE] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                   KC_6     , KC_7   , KC_8   , KC_9,    KC_0,    KC_EQL ,
  KC_TAB,   KC_B,   KC_L,    KC_D,    KC_W,    KC_Z,                   KC_QUOT  , KC_F   , KC_O   , KC_U,    KC_J,    KC_SCLN,
  KC_LCTL,  KC_N,   KC_R,    KC_T,    KC_S,    KC_G,                   KC_Y     , KC_H   , KC_A   , KC_E,    KC_I,    KC_COMM,
  KC_LSFT,  KC_Q,   KC_X,    KC_M,    KC_C,    KC_V, KC_LBRC, KC_RBRC, KC_K     , KC_P   , KC_DOT , KC_MINS, KC_SLSH, KC_BSLS,
                        KC_LGUI, KC_LALT, LT_SYMESC, KC_SPC , KC_ENT , LT_FNBSPC, KC_RALT, KC_RGUI
),


/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ` ~  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | = +  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | \ |  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  ; : | ' "  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * | LSFT |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  | , <  | . >  | / ?  | - _  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |SYMESC| / SPACE /       \ENTER \  |FNBSPC| RALT | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                   KC_6     , KC_7   , KC_8   , KC_9  ,  KC_0   , KC_EQL ,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                   KC_Y     , KC_U   , KC_I   , KC_O  ,  KC_P   , KC_BSLS,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                   KC_H     , KC_J   , KC_K   , KC_L  ,  KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC, KC_RBRC, KC_N     , KC_M   , KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                        KC_LGUI, KC_LALT, LT_SYMESC, KC_SPC , KC_ENT , LT_FNBSPC, KC_RALT, KC_RGUI
),


/* SYMBOLS + MOUSE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      |      |  UP  |      | PGUP |                    |      |MsLfBt| MsUp |MsRtBt|      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL | HOME | LEFT | DOWN |RIGHT | PGDN |-------.    ,-------|MsWhBt|MsLft |MsDown|MsRght|  END |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | LSFT |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |SYMESC| / SPACE /       \ENTER \  |FNBSPC| RALT | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_SYMBOLS] = LAYOUT(
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                   KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO , KC_NO,
  _______, KC_NO  , KC_NO  , KC_UP  , KC_NO  , KC_PGUP,                   KC_NO  , KC_BTN1, KC_MS_U, KC_BTN2, KC_NO , KC_NO,
  _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_R, KC_END, KC_NO,
  _______, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO , KC_NO,
                             _______, _______, _______, _______, _______, _______, _______, _______
  ),


/* FUNCTION
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      | GRPH |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  F1  |  F2  |  F3  |  F4  |      |                    |      | PLAY | VOL+ |      |      | QWER |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |  F5  |  F6  |  F7  |  F8  |      |-------|    |-------|      | STOP | VOL- |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | LSFT |  F9  | F10  | F11  | F12  |      |-------|    |-------|      | PSCR | MUTE |      |      | BOOT |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |SYMESC| / SPACE /       \ENTER \  |FNBSPC| RALT | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_FUNCTION] = LAYOUT(
  KC_NO  , KC_NO, KC_NO , KC_NO  , KC_NO  , KC_NO  ,                   KC_NO  , KC_NO  , KC_NO  , KC_NO, KC_NO, DF(_GRAPHITE),
  _______, KC_F1, KC_F2 , KC_F3  , KC_F4  , KC_NO  ,                   KC_NO  , KC_MPLY, KC_VOLU, KC_NO, KC_NO, DF(_QWERTY)  ,
  _______, KC_F5, KC_F6 , KC_F7  , KC_F8  , KC_NO  ,                   KC_NO  , KC_MSTP, KC_VOLD, KC_NO, KC_NO, KC_NO        ,
  _______, KC_F9, KC_F10, KC_F11 , KC_F12 , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_PSCR, KC_MUTE, KC_NO, KC_NO, QK_BOOT      ,
                          _______, _______, _______, _______, _______, _______, _______, _______
  )
};


//layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _SYMBOLS, _NUMBERS, _FUNCTION);
//}

/* -------------------- COMBOS --------------------- */

//const uint16_t PROGMEM semi_combo[]= {KC_COMM, KC_DOT, COMBO_END};
//const uint16_t PROGMEM semi_combo2[] = {RCTL_T(KC_COMM), KC_DOT, COMBO_END};
//
combo_t key_combos[] = {
    //COMBO(semi_combo, KC_SCLN),
    //COMBO(semi_combo2, KC_SCLN),
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

/* ------------------ OLED SCREEN ------------------- */

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}

