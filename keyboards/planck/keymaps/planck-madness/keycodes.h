// Copyright 2026 lokthok (@lokthok)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Custom keycodes for planck-madness keymap
// Using QK_USER as the base following QMK best practices
enum custom_keycodes {
    // Python development macros
    PY_INIT = QK_USER,  // def __init__(self, ):
    PY_MAIN,            // if __name__ == "__main__":
    PY_FOR,             // for  in :
    PY_WHILE,           // while :
    PY_TRY,             // try/except block
    PY_FUNC,            // def (self):
    PY_LIST_COMP,       // [ for  in ]
    PY_CLASS,           // class :
    
    // Text emoticons
    EMOJI_1,            // ( ._.)
    EMOJI_2,            // (._. )
    EMOJI_3,            // ó.Ô
    EMOJI_4,            // Ô.ò
    
    // Symbol layer keycodes with shift behavior
    SLSH_BSLS,          // / on tap, \ on shift
    COMM_SEMI,          // , on tap, ; on shift
    DOT_COLON,          // . on tap, : on shift
    PIPE,               // | (Shift+Backslash on US layout)
    
    // German/European special characters (macOS native)
    E_ACUTE,            // é (Option+e, e)
    U_UML,              // ü (Option+u, u)
    O_UML,              // ö (Option+u, o)
    A_UML,              // ä (Option+u, a)
    S_SHARP,            // ß (Option+s)
    EURO,               // € (Shift+Option+2)
    SECTION,            // § (Option+6)
};
