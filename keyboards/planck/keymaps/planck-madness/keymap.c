// Copyright 2026 lokthok (@lokthok)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "macros.h"
#include "emojis.h"

// ============================================================================
// Layer Definitions
// ============================================================================

enum planck_layers {
    _BASE,
    _GAMING,
    _SYMBOL,
    _FN,
    _MACROS,
    _EMOJIS,
};

// ============================================================================
// Combo Definitions
// ============================================================================

enum combo_events {
    COMBO_ESC,
    COMBO_ESC_GAMING,
    COMBO_RESET,
};

const uint16_t PROGMEM combo_esc[]        = {KC_GRV, KC_Q, COMBO_END};
const uint16_t PROGMEM combo_esc_gaming[] = {KC_N, KC_1, COMBO_END};
const uint16_t PROGMEM combo_reset[]      = {KC_U, KC_I, KC_O, KC_P, COMBO_END};

combo_t key_combos[] = {
    [COMBO_ESC]        = COMBO(combo_esc, KC_ESC),
    [COMBO_ESC_GAMING] = COMBO(combo_esc_gaming, KC_ESC),
    [COMBO_RESET]      = COMBO_ACTION(combo_reset),
};

// ============================================================================
// Keymaps
// ============================================================================

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base Layer (QWERTY)
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │  `~  │  Q   │  W   │  E   │  R   │  T   │  Y   │  U   │  I   │  O   │  P   │  '"  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │  A   │  S   │  D   │  F   │  G   │  H   │  J   │  K   │  L   │  /\  │ Bksp │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │Shift │  Z   │  X   │  C   │  V   │  B   │  N   │  M   │  ,;  │  .:  │  ▲   │Enter │
 * ├──────┼──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Ctrl │ Opt  │ Cmd  │  FN  │Symbol│    Space    │  =+  │  -_  │  ◀︎   │  ▼   │  ►   │
 * └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
 */
[_BASE] = LAYOUT_planck_grid(
    KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,        KC_T,   KC_Y,   KC_U,   KC_I,      KC_O,      KC_P,      KC_QUOT,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,        KC_G,   KC_H,   KC_J,   KC_K,      KC_L,      SLSH_BSLS, KC_BSPC,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,        KC_B,   KC_N,   KC_M,   COMM_SEMI, DOT_COLON, KC_UP,     KC_ENT,
    KC_LCTL, KC_LOPT, KC_LCMD, MO(_FN), MO(_SYMBOL), KC_SPC, KC_SPC, KC_EQL, KC_MINS,   KC_LEFT,   KC_DOWN,   KC_RGHT
),

/* Gaming Layer
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │  N   │  1   │  2   │  3   │  4   │  5   │  6   │  7   │  8   │  9   │  0   │ Base │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │  Q   │  W   │  E   │  R   │  T   │  Y   │  U   │  I   │  O   │  P   │ Bksp │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │Shift │  A   │  S   │  D   │  F   │  G   │  H   │  J   │  K   │  L   │  ▲   │Enter │
 * ├──────┼──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Ctrl │  Z   │  X   │  C   │ Opt  │    Space    │  V   │  B   │  ◀︎   │  ▼   │  ►   │
 * └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
 */
[_GAMING] = LAYOUT_planck_grid(
    KC_N,    KC_1, KC_2, KC_3, KC_4,    KC_5,   KC_6,   KC_7, KC_8, KC_9,    KC_0,    TO(_BASE),
    KC_TAB,  KC_Q, KC_W, KC_E, KC_R,    KC_T,   KC_Y,   KC_U, KC_I, KC_O,    KC_P,    KC_BSPC,
    KC_LSFT, KC_A, KC_S, KC_D, KC_F,    KC_G,   KC_H,   KC_J, KC_K, KC_L,    KC_UP,   KC_ENT,
    KC_LCTL, KC_Z, KC_X, KC_C, KC_LOPT, KC_SPC, KC_SPC, KC_V, KC_B, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Symbol Layer
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │ Del  │      │      │  é   │      │  $   │  §   │  ü   │      │  ö   │  !   │  ?   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │  ä   │  ß   │      │  @   │  #   │  *   │  (   │  [   │  {   │  <   │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │  €   │  %   │  &   │  )   │  ]   │  }   │  >   │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │EMOJI_│      │             │  |   │      │      │      │      │
 * └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
 */
[_SYMBOL] = LAYOUT_planck_grid(
    KC_DEL,  XXXXXXX, XXXXXXX, E_ACUTE,      XXXXXXX, KC_DLR,  SECTION, U_UML,   XXXXXXX, O_UML,   KC_EXLM, KC_QUES,
    XXXXXXX, A_UML,   S_SHARP, XXXXXXX,      KC_AT,   KC_HASH, KC_ASTR, KC_LPRN, KC_LBRC, KC_LCBR, KC_LT,   XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      EURO,    KC_PERC, KC_AMPR, KC_RPRN, KC_RBRC, KC_RCBR, KC_GT,   XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, EMOJI_PICKER, XXXXXXX, XXXXXXX, XXXXXXX, PIPE,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Function Layer
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │  F1  │  F2  │  F3  │  F4  │  F5  │  F6  │  F7  │  F8  │  F9  │ F10  │ F11  │ F12  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │      │      │      │      │PrtScr│ Mute │Gaming│      │  1   │  2   │  3   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │Shift │      │      │      │      │ Vol- │ Vol+ │      │      │  4   │  5   │  6   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Ctrl │ Opt  │ Cmd  │      │Macros│             │Emojis│  0   │  7   │  8   │  9   │
 * └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
 */
[_FN] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,       KC_F9,   KC_F10, KC_F11, KC_F12,
    KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_PSCR, KC_MUTE, TO(_GAMING), XXXXXXX, KC_1,   KC_2,   KC_3,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_VOLD, KC_VOLU, XXXXXXX,     XXXXXXX, KC_4,   KC_5,   KC_6,
    KC_LCTL, KC_LOPT, KC_LCMD, XXXXXXX, OSL(_MACROS), XXXXXXX, XXXXXXX, TO(_EMOJIS), KC_0,    KC_7,   KC_8,   KC_9
),

/* Macros Layer (Python)
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │ Init │ Main │ For  │While │ Try  │ Func │LstCmp│Class │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │             │      │      │      │      │      │
 * └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
 */
[_MACROS] = LAYOUT_planck_grid(
    PY_INIT, PY_MAIN, PY_FOR,  PY_WHILE, PY_TRY,  PY_FUNC, PY_LIST_COMP, PY_CLASS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Emoji Layer
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │(._.) │(._. )│ ó.Ô  │ Ô.ò  │      │      │      │      │      │      │      │ Base │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │      │      │      │  ▲   │Enter │
 * ├──────┼──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │    Space    │      │      │  ◀︎   │  ▼   │  ►   │
 * └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
 */
[_EMOJIS] = LAYOUT_planck_grid(
    EMOJI_1, EMOJI_2, EMOJI_3, EMOJI_4, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(_BASE),
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   KC_ENT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT
),

};

// ============================================================================
// Custom Keycode Processing
// ============================================================================

/**
 * @brief Handle custom keycodes with shift-aware behavior
 */
static bool process_shift_aware_keycode(uint16_t base_keycode, uint16_t shift_keycode) {
    uint8_t mods = get_mods();
    clear_mods();
    
    if (mods & MOD_MASK_SHIFT) {
        tap_code16(shift_keycode);
    } else {
        tap_code(base_keycode);
    }
    
    set_mods(mods);
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Delegate to external processors first
    if (!process_macros(keycode, record)) return false;
    if (!process_emojis(keycode, record)) return false;

    // Only process on key press
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case SLSH_BSLS:
            return process_shift_aware_keycode(KC_SLSH, KC_BSLS);

        case COMM_SEMI:
            return process_shift_aware_keycode(KC_COMM, KC_SCLN);

        case DOT_COLON:
            return process_shift_aware_keycode(KC_DOT, KC_COLN);

        case PIPE:
            tap_code16(S(KC_BSLS));  // Shift+Backslash = |
            return false;

        // macOS native shortcuts for German/European characters
        case E_ACUTE:
            tap_code16(A(KC_E));
            tap_code(KC_E);
            return false;

        case U_UML:
            tap_code16(A(KC_U));
            tap_code(KC_U);
            return false;

        case O_UML:
            tap_code16(A(KC_U));
            tap_code(KC_O);
            return false;

        case A_UML:
            tap_code16(A(KC_U));
            tap_code(KC_A);
            return false;

        case S_SHARP:
            tap_code16(A(KC_S));
            return false;

        case EURO:
            tap_code16(S(A(KC_2)));
            return false;

        case SECTION:
            tap_code16(A(KC_6));
            return false;

        default:
            return true;
    }
}

// ============================================================================
// Keyboard Initialization
// ============================================================================

void keyboard_post_init_user(void) {
    // No Unicode input mode needed - using macOS native shortcuts
}

// ============================================================================
// Combo Event Handler
// ============================================================================

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case COMBO_RESET:
            if (pressed && biton32(layer_state) == _BASE) {
                reset_keyboard();
            }
            break;
    }
}
