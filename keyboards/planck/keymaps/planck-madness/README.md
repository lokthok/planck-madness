# Planck Madness Keymap

A professional, highly optimized keymap for the Planck Rev6 Drop keyboard, designed for Python development on macOS.

## Features

### 🐍 Python Development Macros
- **PY_INIT**: `def __init__(self, ):`
- **PY_MAIN**: `if __name__ == "__main__":`
- **PY_FOR**: `for  in :`
- **PY_WHILE**: `while :`
- **PY_TRY**: Full try/except block
- **PY_FUNC**: `def (self):`
- **PY_LIST_COMP**: List comprehension skeleton
- **PY_CLASS**: `class :`

### 🌍 International Characters
Full support for German/European characters:
- é, ü, ö, ä, ß, €, §

### 🎮 Gaming Layer
Optimized layout for gaming with easy access to numbers and movement keys.

### ⌨️ Smart Symbol Handling
- `/` and `\` on a single key with shift modifier
- `=` and `+` on a single key with shift modifier
- Proper shift state management (no sticky modifiers)

### 🙂 Text Emoticons
Quick access to text-based emoticons for communication.

## Layer Overview

1. **BASE**: Standard QWERTY with custom symbol keys
2. **GAMING**: Optimized for gaming
3. **SYMBOL**: Special characters and international symbols
4. **FN**: Function keys, media controls, and layer switching
5. **MACROS**: Python development macros
6. **EMOJIS**: Text emoticons

## Combos

- **` + Q**: Escape
- **N + 1**: Escape (Gaming layer)
- **U + I + O + P**: Reset keyboard (BASE layer only)

## Building

```bash
qmk compile -kb planck/rev6_drop -km planck-madness
```

## Flashing

```bash
qmk flash -kb planck/rev6_drop -km planck-madness
```

## Code Quality

This keymap follows QMK best practices:
- ✅ Proper copyright headers (GPL-2.0-or-later)
- ✅ Modular code structure with separate files for macros and emojis
- ✅ Comprehensive documentation and comments
- ✅ Proper shift modifier handling (no state leakage)
- ✅ Use of `QK_USER` for custom keycodes (modern QMK standard)
- ✅ Helper functions for repetitive operations
- ✅ Defensive programming (check `pressed` state)
- ✅ Clean, readable layer definitions with visual guides

## Requirements

- QMK Firmware 0.18.0 or later
- ARM GCC toolchain
- macOS for full Unicode support

## Author

lokthok (@lokthok) - 2025

## License

GPL-2.0-or-later
