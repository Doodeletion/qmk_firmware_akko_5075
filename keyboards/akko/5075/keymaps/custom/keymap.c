/* Copyright (C) 2023 jonylee@hfd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
// clang-format off
enum __layers {
    L_BASE,
    L_EMACS,
    L_FN,
    L_EXTRA,
    L_5,
    L_6
};


enum custom_keycodes {
    M_EURO = SAFE_RANGE,
    M_SHARP_S,
    M_UE,
    M_OE,
    M_AE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [L_BASE] = LAYOUT(
        KC_ESC,              KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,     KC_F10,       KC_F11, KC_F12,  KC_DEL,           KC_MPLY,
        KC_GRV,              KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,      KC_0,         KC_MINS,KC_EQL,  KC_BSPC,          KC_HOME,
        LT(L_EXTRA, KC_TAB), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,      KC_P,         KC_LBRC,KC_RBRC, KC_BSLS,          KC_PGUP,
        OSL(L_FN),           KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,      KC_SCLN,      KC_QUOT,         KC_ENT,           KC_PGDN,
        KC_LSFT,             KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,    KC_SLSH,                       KC_RSFT, KC_UP,   KC_END,
        KC_LCTL,             KC_LGUI, KC_LALT,                   KC_SPC,                             OSL(L_FN), OSL(L_EXTRA), KC_RCTL,         KC_LEFT, KC_DOWN, KC_RGHT),

    [L_EMACS] = LAYOUT(
        _______, _______, _______,   _______, _______, _______, _______, _______, _______,  _______,   _______, _______, _______, _______,          _______,
        _______, _______, _______,   _______, _______,  _______, _______, _______, _______, _______,   _______, _______, _______, _______,          _______,
        _______, _______, _______,   _______, _______, _______, _______, _______, _______,  _______,   _______, _______, _______, _______,          _______,
        _______, _______, _______,   _______, _______, _______, _______, _______, _______,  _______,   _______, _______,          _______,          _______,
        _______, _______, _______,   _______, _______, _______, _______, _______, _______,  _______,   _______,                   _______, _______, _______,
        _______, _______, _______,                     _______,                             _______,   _______, _______,          _______, _______, _______),

    [L_FN] = LAYOUT( /* media keys on fn keys. german umlaute for us int. layout. */
        _______, KC_MPRV, KC_MNXT,   KC_MRWD, KC_MFFD, KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE, KC_APP,      KC_PSCR, KC_LSCR, KC_PAUS, _______,          _______,
        _______, _______, _______,   _______, M_EURO,  _______, _______, _______, _______, _______,     _______, _______, _______, _______,          _______,
        _______, _______, _______,   _______, _______, _______, _______, M_UE,    _______,    M_OE,     _______,    _______, _______, _______,          _______,
        _______, M_AE,    M_SHARP_S, _______, _______, _______, _______, _______, _______, _______,     _______, _______,          _______,          _______,
        _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,     _______,                   _______, KC_W,    _______,
        _______, _______, _______,                     _______,                            TG(L_EMACS), OSL(L_EXTRA), _______,       KC_A,    KC_S,    KC_D),

    [L_EXTRA] = LAYOUT( /* extra shortcut keys: f13-24 and numblock keys */
        _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,      KC_F22,  KC_F23,  KC_F24,  KC_PSLS,           _______,
        KC_NUM,  KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,   KC_P6,   KC_P7,   KC_P8,   KC_P9,       KC_P0,   KC_PAST, KC_PMNS, KC_PENT,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______,          _______,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,                   _______,  _______, _______,
        _______, _______, _______,                   _______,                            TG(L_EMACS), _______, _______,          _______,  _______, _______),

    [L_5] = LAYOUT( /* unused */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, KC_W,    _______,
        _______, _______, _______,                   _______,                            _______, MO(L_6), _______,       KC_A,    KC_S,    KC_D),

    [L_6] = LAYOUT( /* unused */
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,           RM_NEXT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RM_SPDD, RM_SPDU, _______,           _______,
        _______, _______,TG(L_5),_______, _______, _______, _______, _______, KC_INS,  _______, KC_PSCR,_______, _______,    RM_NEXT,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, RM_TOGG, _______, _______,          RM_HUEU,           _______,
        _______, _______, _______, KC_CALC, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,                   _______,  RM_VALU, _______,
        _______, _______, _______,                   _______,                            _______, _______, _______,          RM_SATD,  RM_VALD, RM_SATU),
};
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [L_BASE] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [L_EMACS] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [L_FN] = { ENCODER_CCW_CW(RM_VALU, RM_VALD) },
    [L_EXTRA] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [L_5] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [L_6] = { ENCODER_CCW_CW(RM_VALU, RM_VALD) }
};
#endif

// implements macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // skip if FN layer is not active
    if (!layer_state_is(L_FN)) {
        return true;
    }

    switch (keycode) {
    case M_EURO:
        if (record->event.pressed) {
            // key pressed
            register_code(KC_RALT);
            tap_code(KC_5);
            unregister_code(KC_RALT);
        } // else {
          //     // key released
          //     // remember that switch is skipped if not in FN layer
          //     // so this might not be triggered if the layer was changed while holding down the macro key
          // }
        break;
    case M_AE:
        if (record->event.pressed) {
            // key pressed
            register_code(KC_RALT);
            tap_code(KC_Q);
            unregister_code(KC_RALT);
        }
        break;
    case M_SHARP_S:
        if (record->event.pressed) {
            // key pressed
            register_code(KC_RALT);
            tap_code(KC_S);
            unregister_code(KC_RALT);
        }
        break;
    case M_UE:
        if (record->event.pressed) {
            // key pressed
            register_code(KC_RALT);
            tap_code(KC_Y);
            unregister_code(KC_RALT);
        }
        break;
    case M_OE:
        if (record->event.pressed) {
            // key pressed
            register_code(KC_RALT);
            tap_code(KC_P);
            unregister_code(KC_RALT);
        }
        break;
    }
    return true;
};

void set_home_row_mod_color_rgb(uint8_t red, uint8_t green, uint8_t blue) {
    // a - f
    rgb_matrix_set_color(45 , red, green, blue);
    rgb_matrix_set_color(46 , red, green, blue);
    rgb_matrix_set_color(47 , red, green, blue);
    rgb_matrix_set_color(48 , red, green, blue);

    // // j - ;
    rgb_matrix_set_color(51 , red, green, blue);
    rgb_matrix_set_color(52 , red, green, blue);
    rgb_matrix_set_color(53 , red, green, blue);
    rgb_matrix_set_color(54 , red, green, blue);
}

void set_decor_color_rgb(uint8_t red, uint8_t green, uint8_t blue) {
    // decor
    for (int i = 0; i < 13; i++) {
        rgb_matrix_set_color(i , red, green, blue);
    }

    rgb_matrix_set_color(14 , red, green, blue);

    for (int i = 18; i < 29; i++) {
        rgb_matrix_set_color(i , red, green, blue);
    }

    for (int i = 35; i < 42; i++) {
        rgb_matrix_set_color(i , red, green, blue);
    }

    rgb_matrix_set_color(43 , red, green, blue);

    for (int i = 47; i < 57; i++) {
        rgb_matrix_set_color(i , red, green, blue);
    }

    rgb_matrix_set_color(58 , red, green, blue);

    for (int i = 63; i < 69; i++) {
        rgb_matrix_set_color(i , red, green, blue);
    }

    rgb_matrix_set_color(72 , red, green, blue);
    rgb_matrix_set_color(73 , red, green, blue);
}

void set_home_row_mod_color_hsv(uint8_t hue, uint8_t saturation, uint8_t brightness) {
    hsv_t hsv = {hue, saturation, brightness};
    rgb_t rgb = hsv_to_rgb(hsv);
    set_home_row_mod_color_rgb(rgb.r, rgb.g, rgb.b);
}

void set_decor_color_hsv(uint8_t hue, uint8_t saturation, uint8_t brightness) {
    hsv_t hsv = {hue, saturation, brightness};
    rgb_t rgb = hsv_to_rgb(hsv);
    set_decor_color_rgb(rgb.r, rgb.g, rgb.b);
}

// hsv hue 0-360 is mapped to 0-255
// hue-value/360 * 255
bool rgb_matrix_indicators_user() {
    switch (get_highest_layer(layer_state)) {
        case L_BASE:
            rgb_matrix_sethsv_noeeprom (0, 0, 80);
            set_decor_color_hsv(148, 180, 70);
            break;
        case L_EMACS:
            rgb_matrix_sethsv_noeeprom (0, 0, 80);
            set_home_row_mod_color_hsv(148, 225, 135);
            break;
        case L_FN:
            rgb_matrix_sethsv_noeeprom(0,  255, 125);
            break;
        case L_EXTRA:
            rgb_matrix_sethsv_noeeprom(176,  255, 125);
            break;
    }
    return true;
}
