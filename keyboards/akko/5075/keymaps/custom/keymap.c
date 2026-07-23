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
    L_MODS,
    L_FN,
    L_EXTRA,
    L_NOGUI,
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
        KC_ESC,              KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,     KC_F10,       KC_F11,               KC_F12,               KC_DEL,           KC_MPLY,
        KC_GRV,              KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,      KC_0,         KC_MINS,              KC_EQL,               KC_BSPC,          KC_HOME,
        LT(L_EXTRA, KC_TAB), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,      KC_P,         KC_LBRC,              LT(L_EXTRA, KC_RBRC), KC_BSLS,          KC_PGUP,
        OSL(L_FN),           KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,      KC_SCLN,      LT(L_FN, KC_QUOT),                          KC_ENT,           KC_PGDN,
        KC_LSFT,             KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,    KC_SLSH,                                                  KC_RSFT, KC_UP,   KC_END,
        KC_LCTL,             KC_LGUI, KC_LALT,                   KC_SPC,                             OSL(L_FN), OSL(L_EXTRA), KC_RCTL,                                    KC_LEFT, KC_DOWN, KC_RGHT),

    //TODO remove dynamic tapping time keys when done configuring timing (also remove feature switch from rules.mk)
    [L_MODS] = LAYOUT( /* GACS home row mods */
        _______, _______,      _______,        _______,      _______,       _______,        _______,           _______,      _______,     _______,        _______,         _______, _______, _______,          _______,
        _______, _______,      _______,        _______,      _______,       _______,        _______,           _______,      _______,     _______,        _______,         _______, _______, _______,          _______,
        _______, _______,      _______,        _______,      _______,       _______,        _______,           _______,      _______,     _______,        _______,         _______, _______, _______,          _______,
        _______, LGUI_T(KC_A), LALT_T(KC_S),   LCTL_T(KC_D), LSFT_T(KC_F), LT(L_FN, KC_G), LT(L_EXTRA, KC_H), RSFT_T(KC_J), RCTL_T(KC_K), LALT_T(KC_L),   RGUI_T(KC_SCLN), _______, _______,                   _______,
        _______, _______,      _______,        _______,      _______,      _______,        _______,           _______,      _______,      _______,        _______,                           _______, _______, _______,
        _______, _______,      _______,                                    _______,                                                       _______,        _______,         _______,          _______, _______, _______),

    [L_FN] = LAYOUT( /* media keys on fn keys. german umlaute for us int. layout. */
        _______, KC_MPRV, KC_MNXT,   KC_MRWD, KC_MFFD, KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE, KC_APP,     KC_PSCR,         KC_LSCR,      KC_PAUS, _______,          _______,
        _______, _______, _______,   _______, M_EURO,  _______, _______, _______, _______, _______,    _______,         _______,      _______, _______,          _______,
        _______, _______, _______,   _______, _______, _______, _______, M_UE,    _______, M_OE,       _______,         _______,      _______, _______,          _______,
        _______, M_AE,    M_SHARP_S, _______, _______, _______, _______, _______, _______, _______,    _______,         _______,               _______,          _______,
        _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,    _______,                                _______, DT_UP,   _______,
        _______, TG(L_NOGUI), _______,                     _______,                                    TG(L_MODS),      OSL(L_EXTRA), _______, _______, DT_DOWN, DT_PRNT),

    [L_EXTRA] = LAYOUT( /* extra shortcut keys: f13-24 and numblock keys */
        _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,      KC_F22,      KC_F23,  KC_F24,  KC_PSLS,           _______,
        KC_NUM,  KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,   KC_P6,   KC_P7,   KC_P8,   KC_P9,       KC_P0,       KC_PAST, KC_PMNS, KC_PENT,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,     _______, _______, _______,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,     _______,          _______,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,                       _______,  _______, _______,
        _______, _______, _______,                   _______,                            _______,     TG(L_NOGUI), _______,          _______,  _______, _______),

    [L_NOGUI] = LAYOUT( /* replace GUI with a key suitable for shortcuts */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______,
        _______, KC_BSLS, _______,                   _______,                            _______, _______, _______,          _______, _______, _______),

    [L_6] = LAYOUT( /* unused */
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,           RM_NEXT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RM_SPDD, RM_SPDU, _______,           _______,
        _______, _______,TG(L_NOGUI),_______, _______, _______, _______, _______, KC_INS,  _______, KC_PSCR,_______, _______,    RM_NEXT,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, RM_TOGG, _______, _______,          RM_HUEU,           _______,
        _______, _______, _______, KC_CALC, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,                   _______,  RM_VALU, _______,
        _______, _______, _______,                   _______,                            _______, _______, _______,          RM_SATD,  RM_VALD, RM_SATU),
};

//TODO use encoder to skip forward/backward?
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [L_BASE] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [L_MODS] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [L_FN] = { ENCODER_CCW_CW(RM_VALU, RM_VALD) },
    [L_EXTRA] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [L_NOGUI] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
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

//##################
//      RGB
// #################

void set_home_row_mod_color(void) {
    // a - f
    rgb_matrix_set_color(45, 178, 0, 0);
    rgb_matrix_set_color(46, 255, 127, 0);
    rgb_matrix_set_color(47, 229, 191, 0);
    rgb_matrix_set_color(48, 0, 128, 0);
    rgb_matrix_set_color(49, 0, 128, 85);

    // // j - ;
    rgb_matrix_set_color(50, 81, 20, 128);
    rgb_matrix_set_color(51, 0, 128, 0);
    rgb_matrix_set_color(52, 229, 191, 0);
    rgb_matrix_set_color(53, 255, 127, 0);
    rgb_matrix_set_color(54, 178, 0, 0);
}

void set_decor_color_rgb(uint8_t red, uint8_t green, uint8_t blue) {
    // esc - f12
    for (int i = 0; i < 14; i++) {
        rgb_matrix_set_color(i , red, green, blue);
    }

    // ~
    rgb_matrix_set_color(14 , red, green, blue);

    // 4 - home
    for (int i = 18; i < 29; i++) {
        rgb_matrix_set_color(i , red, green, blue);
    }

    // t - ]
    for (int i = 34; i < 42; i++) {
        rgb_matrix_set_color(i , red, green, blue);
    }

    // pageup
    rgb_matrix_set_color(43 , red, green, blue);

    // d - '
    for (int i = 47; i < 57; i++) {
        rgb_matrix_set_color(i , red, green, blue);
    }

    // pagedown
    rgb_matrix_set_color(58 , red, green, blue);

    // c - ,
    for (int i = 63; i < 69; i++) {
        rgb_matrix_set_color(i , red, green, blue);
    }

    // up arrow
    rgb_matrix_set_color(72 , red, green, blue);
    // end
    rgb_matrix_set_color(73 , red, green, blue);
}

// hsv hue 0-360 is mapped to 0-255
// hue-value/360 * 255
bool rgb_matrix_indicators_user() {
    // general key color
    if(layer_state_is(L_NOGUI)) {
        rgb_matrix_sethsv_noeeprom (128, 230, 135);
        return false;
    } else {
        rgb_matrix_sethsv_noeeprom (0, 0, 100);
    }

    // accents
    if (layer_state_is(L_MODS)) {
        set_home_row_mod_color();
        return false;
    }

    if (layer_state_is(L_BASE)) {
        set_decor_color_rgb(21, 46, 70);
        return false;
    }

    // red to signal error if neither L_MODS nor L_BASE matched
    rgb_matrix_sethsv_noeeprom (0, 255, 135);
    return false;
}
