// Copyright 2026 lokthok (@lokthok)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "macros.h"
#include "keycodes.h"

// Typing speed - adjust this value to make typing faster/slower
#define MACRO_TYPING_DELAY 25  // milliseconds between each character

/**
 * @brief Reliable LEFT movement with delays
 */
static void move_left(uint8_t count) {
    for (uint8_t i = 0; i < count; i++) {
        wait_ms(50);
        tap_code(KC_LEFT);
    }
}

/**
 * @brief Reliable UP movement with delays
 */
static void move_up(uint8_t count) {
    for (uint8_t i = 0; i < count; i++) {
        wait_ms(50);
        tap_code(KC_UP);
    }
}

bool process_macros(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;  // Only process on key press
    }

    switch (keycode) {
        case PY_INIT:
            // def __init__(self, |):
            send_string_with_delay_P(PSTR("def __init__(self, ):"), MACRO_TYPING_DELAY);
            wait_ms(100);
            tap_code(KC_ENTER);
            wait_ms(100);
            send_string_with_delay_P(PSTR("    "), MACRO_TYPING_DELAY);
            wait_ms(100);
            tap_code(KC_UP);
            wait_ms(100);
            tap_code(KC_END);
            move_left(2);
            return false;

        case PY_MAIN:
            // if __name__ == "__main__":<newline>    |
            send_string_with_delay_P(PSTR("if __name__ == \"__main__\":"), MACRO_TYPING_DELAY);
            wait_ms(100);
            tap_code(KC_ENTER);
            wait_ms(100);
            send_string_with_delay_P(PSTR("    "), MACRO_TYPING_DELAY);
            return false;

        case PY_FOR:
            // for | in :
            send_string_with_delay_P(PSTR("for  in :"), MACRO_TYPING_DELAY);
            wait_ms(100);
            tap_code(KC_ENTER);
            wait_ms(100);
            send_string_with_delay_P(PSTR("    "), MACRO_TYPING_DELAY);
            wait_ms(100);
            tap_code(KC_UP);
            wait_ms(100);
            tap_code(KC_END);
            move_left(5);
            return false;

        case PY_WHILE:
            // while |:
            send_string_with_delay_P(PSTR("while :"), MACRO_TYPING_DELAY);
            wait_ms(100);
            tap_code(KC_ENTER);
            wait_ms(100);
            send_string_with_delay_P(PSTR("    "), MACRO_TYPING_DELAY);
            wait_ms(100);
            tap_code(KC_UP);
            wait_ms(100);
            tap_code(KC_END);
            move_left(1);
            return false;

        case PY_TRY:
            // try:<newline>    |<newline>except...
            send_string_with_delay_P(PSTR("try:"), MACRO_TYPING_DELAY);
            wait_ms(100);
            tap_code(KC_ENTER);
            wait_ms(100);
            send_string_with_delay_P(PSTR("    "), MACRO_TYPING_DELAY);
            wait_ms(100);
            tap_code(KC_ENTER);
            wait_ms(100);
            send_string_with_delay_P(PSTR("except Exception as e:"), MACRO_TYPING_DELAY);
            wait_ms(100);
            tap_code(KC_ENTER);
            wait_ms(100);
            send_string_with_delay_P(PSTR("    print(f\"Error: {e}\")"), MACRO_TYPING_DELAY);
            wait_ms(100);
            move_up(2);  // Only go up 2 lines, not 3
            wait_ms(100);
            tap_code(KC_END);
            return false;

        case PY_FUNC:
            // def |(self):
            send_string_with_delay_P(PSTR("def (self):"), MACRO_TYPING_DELAY);
            wait_ms(100);
            tap_code(KC_ENTER);
            wait_ms(100);
            send_string_with_delay_P(PSTR("    "), MACRO_TYPING_DELAY);
            wait_ms(100);
            tap_code(KC_UP);
            wait_ms(100);
            tap_code(KC_END);
            move_left(7);
            return false;

        case PY_LIST_COMP:
            // [| for  in ]
            send_string_with_delay_P(PSTR("[ for  in "), MACRO_TYPING_DELAY);
            wait_ms(100);
            tap_code(KC_END);
            move_left(10);
            return false;

        case PY_CLASS:
            // class |:
            send_string_with_delay_P(PSTR("class :"), MACRO_TYPING_DELAY);
            wait_ms(100);
            tap_code(KC_ENTER);
            wait_ms(100);
            send_string_with_delay_P(PSTR("    "), MACRO_TYPING_DELAY);
            wait_ms(100);
            tap_code(KC_UP);
            wait_ms(100);
            tap_code(KC_END);
            move_left(1);
            return false;

        default:
            return true;  // Not our keycode, continue processing
    }
}