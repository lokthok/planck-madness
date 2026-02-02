// Copyright 2026 lokthok (@lokthok)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "emojis.h"
#include "keycodes.h"

// Typing speed for emojis
#define EMOJI_TYPING_DELAY 30  // milliseconds between each character/action

bool process_emojis(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;  // Only process on key press
    }

    switch (keycode) {
        case EMOJI_PICKER:
            tap_code16(C(G(KC_SPC)));  // Ctrl+Cmd+Space
            return false;
            
        case EMOJI_1:
            send_string_with_delay_P(PSTR("( ._.)"), EMOJI_TYPING_DELAY);
            return false;

        case EMOJI_2:
            send_string_with_delay_P(PSTR("(._. )"), EMOJI_TYPING_DELAY);
            return false;

        case EMOJI_3:
            // ó.Ô using macOS native shortcuts
            // ó = Option+e, o
            tap_code16(A(KC_E));
            wait_ms(EMOJI_TYPING_DELAY);
            tap_code(KC_O);
            wait_ms(EMOJI_TYPING_DELAY);
            send_string_with_delay_P(PSTR("."), EMOJI_TYPING_DELAY);
            wait_ms(EMOJI_TYPING_DELAY);
            // Ô = Option+i, Shift+o  
            tap_code16(A(KC_I));
            wait_ms(EMOJI_TYPING_DELAY);
            tap_code16(S(KC_O));
            return false;

        case EMOJI_4:
            // Ô.ò using macOS native shortcuts
            // Ô = Option+i, Shift+o
            tap_code16(A(KC_I));
            wait_ms(EMOJI_TYPING_DELAY);
            tap_code16(S(KC_O));
            wait_ms(EMOJI_TYPING_DELAY);
            send_string_with_delay_P(PSTR("."), EMOJI_TYPING_DELAY);
            wait_ms(EMOJI_TYPING_DELAY);
            // ò = Option+`, o
            tap_code16(A(KC_GRV));
            wait_ms(EMOJI_TYPING_DELAY);
            tap_code(KC_O);
            return false;

        default:
            return true;  // Not our keycode, continue processing
    }
}
