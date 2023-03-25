/* Copyright 2023 @ Keychron (https://www.keychron.com)
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
enum layers{
  OFFICE_BASE,
  OFFICE_FN,
  GAME_BASE,
  GAME_FN,
  L4,
  L5,
//  L6,
};

//Tap Dance Declarations
enum {
  TD_NUMLK_EQL = 0,
  TD_PMNS_BKPC,
  TD_CAP_FNO,
  TD_CAP_FNG,
  TD_DEF_L4,
  TD_GRV_L4,
  TD_ESC_L4,
  TD_SLS_WDS,
  TD_PST_WDP,
  TD_F1_WDS,
  TD_F2_WDP,
};
#if(VIA_PROTOCOL_VERSION >= 0x000C)
#   define qk_tap_dance_state_t tap_dance_state_t
#   define qk_tap_dance_action_t tap_dance_action_t
#endif
// Declare the functions to be used with your tap dance key(s)
// Function associated with all tap dances
uint8_t cur_dance(qk_tap_dance_state_t *state);
// Functions associated with individual tap dances
void ql_finished(qk_tap_dance_state_t *state, void *user_data);
void ql_reset(qk_tap_dance_state_t *state, void *user_data);

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_NUMLK_EQL]  = ACTION_TAP_DANCE_DOUBLE(KC_NUM, KC_EQL),
  [TD_PMNS_BKPC] = ACTION_TAP_DANCE_DOUBLE(KC_PMNS, KC_BSPC),
  [TD_CAP_FNO] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset),
  [TD_CAP_FNG] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset),
  [TD_DEF_L4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset),
  [TD_GRV_L4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset),
  [TD_ESC_L4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset),
  [TD_SLS_WDS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset),
  [TD_PST_WDP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset),
  [TD_F1_WDS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset),
  [TD_F2_WDP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset),
};

#define TDNUMEQ TD(TD_NUMLK_EQL)
#define TDMNSBK TD(TD_PMNS_BKPC)
#define TDCAPFO TD(TD_CAP_FNO)
#define TDCAPFG TD(TD_CAP_FNG)
#define TDETGL4 TD(TD_DEF_L4)
#define TDGRVL4 TD(TD_GRV_L4)
#define TDESCL4 TD(TD_ESC_L4)
#define TDSLSWS TD(TD_SLS_WDS)
#define TDPSTWP TD(TD_PST_WDP)
#define TDF1WDS TD(TD_F1_WDS)
#define TDF2WDP TD(TD_F2_WDP)

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(L4, KC_A):
        return 260;
    case TDETGL4:
        return 260;
    case LT(L4, KC_ESC):
        return 2000;
    case TDNUMEQ:
        return 195;
    case TDMNSBK:
        return 195;
    case TDCAPFO:
    case TDCAPFG:
        return 250;
    case TDGRVL4:
        return 260;
    case TDESCL4:
        return 260;
    case TDSLSWS:
    case TDPSTWP:
    case TDF1WDS:
    case TDF2WDP:
        return 190;
    default:
      return TAPPING_TERM;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [OFFICE_BASE] = LAYOUT_ansi_108(
        TDESCL4,         TDF1WDS,  TDF2WDP,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,      KC_F10,  KC_F11,     KC_F12,   KC_PSCR,  KC_SCRL,  KC_PAUS,  KC_MUTE,  KC_VOLD,  KC_VOLU,  TDETGL4,
        TDGRVL4,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,  TDNUMEQ,  TDSLSWS,  TDPSTWP,  TDMNSBK,
         KC_TAB,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
        TDCAPFO,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,LT(L4,KC_SCLN),KC_QUOT,              KC_ENT,                                 KC_P4,    KC_P5,    KC_P6,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,              KC_P1,    KC_P2,    KC_P3,    KC_PENT,
        KC_LCTL,  KC_LWIN,  KC_LALT,               LT(OFFICE_FN,KC_SPC),                                 KC_RALT,KC_RWIN,LT(OFFICE_FN,KC_APP),KC_RCTL,KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT         ),
    [OFFICE_FN] = LAYOUT_ansi_108(
        _______,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,RGB_TOG, RGB_RMOD, RGB_MOD,  KC_MPLY,  KC_MPRV,  KC_MNXT,  _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  RGB_VAI,  RGB_HUI,  RGB_SAI,  KC_ESC,  TDSLSWS,  TDPSTWP,  KC_BSPC,
        RGB_TOG,  _______,  KC_PGUP,  KC_UP,    KC_PGDN,  _______,  _______,  KC_PGUP,  KC_UP,    KC_PGDN,  _______,  _______,  _______,    _______,  RGB_VAD,  RGB_HUD,  RGB_SAD,  KC_MS_WH_UP,KC_MS_UP,KC_MS_WH_DOWN,  _______,
        _______,  KC_ENT,   KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_BSPC,  KC_BSPC,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,              _______,                                KC_MS_LEFT,KC_MS_BTN1,KC_MS_RIGHT,
        _______,             KC_ESC,  KC_HOME,   KC_DEL,   KC_END,  BAT_LVL,   KC_ESC,  KC_HOME,  KC_DEL,    KC_END,  _______,              _______,            _______,            KC_MS_WH_LEFT,KC_MS_DOWN,KC_MS_WH_RIGHT,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______,  KC_MS_BTN2,            KC_MS_BTN3   ),
    [GAME_BASE] = LAYOUT_ansi_108(
        KC_ESC,          TDF1WDS,  TDF2WDP,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,      KC_F10,  KC_F11,     KC_F12,   KC_PSCR,  KC_SCRL,  KC_PAUS,  KC_MUTE,  KC_VOLD,  KC_VOLU,  TDETGL4,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,  TDNUMEQ,  TDSLSWS,  TDPSTWP,  TDMNSBK,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
        TDCAPFG,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                 KC_P4,    KC_P5,    KC_P6,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,              KC_P1,    KC_P2,    KC_P3,    KC_PENT,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                              KC_RALT,KC_RWIN,       MO(GAME_FN),KC_RCTL,KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT         ),
    [GAME_FN] = LAYOUT_ansi_108(
        _______,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,RGB_TOG, RGB_RMOD, RGB_MOD,  KC_MPLY,  KC_MPRV,  KC_MNXT,  _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  RGB_VAI,  RGB_HUI,  RGB_SAI,  KC_ESC,  TDSLSWS,  TDPSTWP,  KC_BSPC,
        RGB_TOG,  _______,  KC_PGUP,  KC_UP,    KC_PGDN,  _______,  _______,  KC_PGUP,  KC_UP,    KC_PGDN,  _______,  _______,  _______,    _______,  RGB_VAD,  RGB_HUD,  RGB_SAD,  KC_MS_WH_UP,KC_MS_UP,KC_MS_WH_DOWN,  _______,
        _______,  KC_ENT,   KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_BSPC,  KC_BSPC,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,              _______,                                KC_MS_LEFT,KC_MS_BTN1,KC_MS_RIGHT,
        _______,             KC_ESC,  KC_HOME,   KC_DEL,   KC_END,  BAT_LVL,   KC_ESC,  KC_HOME,  KC_DEL,    KC_END,  _______,              _______,            _______,            KC_MS_WH_LEFT,KC_MS_DOWN,KC_MS_WH_RIGHT,  _______,
        _______,  _______,  _______,                                _______,                               _______,  _______,   _______,    _______,  _______,  _______,  _______,  KC_MS_BTN2,            KC_MS_BTN3   ),
    [L4] = LAYOUT_ansi_108(
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______, RGB_TOG, RGB_RMOD, RGB_MOD,  KC_MPLY,  KC_MPRV,  KC_MNXT,  _______,
        _______,  _______,    KC_P7,    KC_P8,    KC_P9,  KC_PAST,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  RGB_VAI,  RGB_HUI,  RGB_SAI,  KC_ESC,  TDSLSWS,  TDPSTWP,  KC_BSPC,
        _______,  _______,    KC_P4,    KC_P5,    KC_P6,  KC_PMNS,  KC_PSLS,    KC_P4,    KC_P5,    KC_P6,  _______,  _______,  _______,    _______,  RGB_VAD,  RGB_HUD,  RGB_SAD,  KC_MS_WH_UP,KC_MS_UP,KC_MS_WH_DOWN,  _______,
        _______,  _______,    KC_P1,    KC_P2,    KC_P3,  KC_PPLS,  KC_BSPC,    KC_P1,    KC_P2,    KC_P3,  _______,  _______,              _______,                                KC_MS_LEFT,KC_MS_BTN1,KC_MS_RIGHT,
        _______,             KC_ESC,    KC_P0,  KC_PDOT,   KC_EQL,  KC_PENT,   KC_ESC,    KC_P0,  _______,  _______,  _______,              _______,            _______,             KC_MS_WH_LEFT,KC_MS_DOWN,KC_MS_WH_RIGHT,  _______,
        _______,  _______,  _______,                                _______,                               _______,  _______,   _______,    _______,  _______,  _______,  _______,  KC_MS_BTN2,            KC_MS_BTN3   ),
    [L5] = LAYOUT_ansi_108(
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                               _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,           _______,            _______,  _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______, _______,  _______, _______,  _______,             _______),
/*    [L6] = LAYOUT_ansi_108(
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                               _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,           _______,            _______,  _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______, _______,  _______, _______,  _______,             _______)
*/
};

//------------------------------------------------------------------------------
// Tap Dance function

// Tap Dance state
enum {
    SINGLE_TAP = 1,
    DOUBLE_TAP,
    TRIPLE_TAP,
    TAP_HOLD,
};

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

// Determine the current tap dance state
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) {
            return SINGLE_TAP;
        } else {
            return TAP_HOLD;
        }
    } else if (state->count == 2) {
        if (!state->pressed) {
            return DOUBLE_TAP;
        } else {
            return TAP_HOLD;
        }
    } else if (state->count == 3) {
        if (!state->pressed) {
            return TRIPLE_TAP;
        } else {
            return TAP_HOLD;
        }
    } else {
        return 8; // Magic number. At some point this method will expand to work for more presses
    }
}

// Initialize tap structure associated with example tap dance key
static tap ql_tap_state = {
    .is_press_action = true,
    .state = 0
};

extern bool g_layer1_led_on;
extern bool g_layer4_led_on;

void updateLED1(bool b) {
    g_layer1_led_on = b;
    led_t led_state = {};
    led_update_user(led_state);
}

void updateLED4(bool b) {
    g_layer4_led_on = b;
    led_t led_state = {};
    led_update_user(led_state);
}

// Functions that control what our tap dance key does
void ql_finished(qk_tap_dance_state_t *state, void *user_data) {
    int tkeycode = TAP_DANCE_KEYCODE(state);
    ql_tap_state.state = cur_dance(state);
    int Fn = GAME_FN;
    switch(tkeycode) {
        case TDETGL4:
        case TDGRVL4:
        case TDESCL4:
            switch (ql_tap_state.state) {
                case SINGLE_TAP:
                    if(tkeycode == TDGRVL4)
                        tap_code(KC_GRV);
                    else
                        tap_code(KC_ESC);
                    break;
                case DOUBLE_TAP:
                    //tap_code(KC_CALC);
                    if(tkeycode == TDETGL4) {
                        register_code(KC_LCTL);
                        register_code(KC_LALT);
                        register_code(KC_N);
                    } else if(tkeycode == TDGRVL4) {
                        register_code(KC_LSFT);
                        register_code(KC_LALT);
                        register_code(KC_Q);
                    } else if(tkeycode == TDESCL4) {
                        register_code(KC_LSFT);
                        register_code(KC_LALT);
                        register_code(KC_W);
                    }
                    break;
                case TAP_HOLD:
                    // temporal layer changell
                    layer_on(L4);
                    updateLED4(true);
                    break;
                case TRIPLE_TAP:
                    // toggle layer
                    // Check to see if the layer is already set
                    if (layer_state_is(L4)) {
                        // If already set, then switch it off
                        layer_off(L4);
                        updateLED4(false);
                    } else {
                        // If not already set, then switch the layer on
                        layer_on(L4);
                        updateLED4(true);
                    }
                    break;
            }
            break;
        case TDCAPFO:
            Fn = OFFICE_FN;
        case TDCAPFG:
            switch (ql_tap_state.state) {
                case SINGLE_TAP:
                    tap_code(KC_CAPS);
                    break;
                case DOUBLE_TAP:
                    tap_code(KC_ESC);
                    break;
                case TAP_HOLD:
                    // temporal layer change
                    layer_on(Fn);
                    updateLED1(true);
                    break;
                case TRIPLE_TAP:
                    // toggle layer
                    // Check to see if the layer is already set
                    if (layer_state_is(Fn)) {
                        // If already set, then switch it off
                        layer_off(Fn);
                        updateLED1(false);
                    } else {
                        // If not already set, then switch the layer on
                        layer_on(Fn);
                        updateLED1(true);
                    }
                    break;
            }
            break;
        case TDSLSWS:
        case TDPSTWP:
        case TDF1WDS:
        case TDF2WDP:
            switch (ql_tap_state.state) {
                case SINGLE_TAP:
                    if (tkeycode == TDSLSWS)
                        tap_code(KC_PSLS);
                    else if (tkeycode == TDPSTWP)
                        tap_code(KC_PAST);
                    else if (tkeycode == TDF1WDS)
                        tap_code(KC_F1);
                    else if (tkeycode == TDF2WDP)
                        tap_code(KC_F2);
                    break;
                case DOUBLE_TAP:
                case TRIPLE_TAP:
                    if((tkeycode == TDSLSWS) || (tkeycode == TDF1WDS)) {
                        register_code(KC_LCTL);
                        register_code(KC_LWIN);
                        register_code(KC_LEFT);
                    } else if ((tkeycode == TDPSTWP) || (tkeycode == TDF2WDP)) {
                        register_code(KC_LCTL);
                        register_code(KC_LWIN);
                        register_code(KC_RGHT);
                    }
                    break;
                case TAP_HOLD:
                    if (tkeycode == TDSLSWS)
                        register_code(KC_PSLS);
                    else if (tkeycode == TDPSTWP)
                        register_code(KC_PAST);
                    else if (tkeycode == TDF1WDS)
                        register_code(KC_F1);
                    else if (tkeycode == TDF2WDP)
                        register_code(KC_F2);
                    break;
            }
            break;
    }
}

void ql_reset(qk_tap_dance_state_t *state, void *user_data) {
    int Fn = GAME_FN;
    int tkeycode = TAP_DANCE_KEYCODE(state);
    switch(tkeycode) {
        case TDETGL4:
        case TDGRVL4:
        case TDESCL4:
            switch (ql_tap_state.state) {
                case SINGLE_TAP:
                    break;
                case DOUBLE_TAP:
                    if(tkeycode == TDETGL4) {
                        unregister_code(KC_LCTL);
                        unregister_code(KC_LALT);
                        unregister_code(KC_N);
                    } else if (tkeycode == TDGRVL4){
                        unregister_code(KC_LSFT);
                        unregister_code(KC_LALT);
                        unregister_code(KC_Q);
                    } else if (tkeycode == TDESCL4){
                        unregister_code(KC_LSFT);
                        unregister_code(KC_LALT);
                        unregister_code(KC_W);
                    }
                    break;
            // If the key was held down and now is released then switch off the layer
                case TAP_HOLD:
                    layer_off(L4);
                    updateLED4(false);
                    break;
            }
            break;
        case TDCAPFO:
            Fn = OFFICE_FN;
        case TDCAPFG:
            if (ql_tap_state.state == TAP_HOLD) {
                layer_off(Fn);
                updateLED1(false);
            }
            break;
        case TDSLSWS:
        case TDPSTWP:
        case TDF1WDS:
        case TDF2WDP:
            switch (ql_tap_state.state) {
                case SINGLE_TAP:
                    break;
                case TAP_HOLD:
                    if (tkeycode == TDSLSWS)
                        unregister_code(KC_PSLS);
                    else if (tkeycode == TDPSTWP)
                        unregister_code(KC_PAST);
                    else if (tkeycode == TDF1WDS)
                        unregister_code(KC_F1);
                    else if (tkeycode == TDF2WDP)
                        unregister_code(KC_F2);
                    break;
                case DOUBLE_TAP:
                case TRIPLE_TAP:
                    if((tkeycode == TDSLSWS) || (tkeycode == TDF1WDS)) {
                        unregister_code(KC_LCTL);
                        unregister_code(KC_LWIN);
                        unregister_code(KC_LEFT);
                    } else if ((tkeycode == TDPSTWP) || (tkeycode == TDF2WDP)) {
                        unregister_code(KC_LCTL);
                        unregister_code(KC_LWIN);
                        unregister_code(KC_RGHT);
                    }
                    break;
            }
            break;
    }
    ql_tap_state.state = 0;
}
