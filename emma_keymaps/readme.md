# QMK Corne (crkbd/rev4_1/standard) custom keymap

This is a custom keymaps for corne keyboard v4.1 that is compatible with windows.

## Requirement

- **QMK CLI**: download cli, follow https://docs.qmk.fm/cli

## Layer overview:

- **Layer 0 (BASE)** : White
- **Layer 1 (NUMS)** : Red
- **Layer 2 (NAV)** : Orange
- **Layer 3 (SYSTEM)**: Blue

### Layer 0 (BASE)

```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│ ESC │  Q  │  W  │  E  │  R  │  T  │PGUP │   │ APP │  Y  │  U  │  I  │  O  │  P  │MSB4 │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│SF/TB│  A  │  S  │  D  │  F  │  G  │PGDN │   │BSPC │  H  │  J  │  K  │  L  │  ;: │ '"  │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│MO(2)│  Z  │  X  │  C  │  V  │  B  │     │   │LSFT/│  N  │  M  │  ,< │  .> │  /? │SFT|C│
└─────┴─────┴─────┴─────┼─────┼─────┤ SPC │   │ ENT ├─────┼─────┼─────┴─────┴─────┴─────┘
                        │ ALT │CTRL │     │   │     │MO(1)│MO(3)│
                        └─────┴─────┴─────┘   └─────┴─────┴─────┘
```

### Layer 1 (NUMS)

```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │     │  -_ │ =+  │HOME │   │ APP │     │  7& │  8* │  9( │  `~ │MSB5 │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│ TAB │     │     │     │  [{ │  }] │END  │   │BSPC │     │  4$ │  5% │  6^ │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│MO(2)│     │     │     │     │     │     │   │LSFT/│  _  │  1! │  2@ │  3# │  \| │SFT|C│
└─────┴─────┴─────┴─────┼─────┼─────┤ SPC │   │ ENT ├─────┼─────┼─────┴─────┴─────┴─────┘
                        │ ALT │CTRL │     │   │     │     │  0) │
                        └─────┴─────┴─────┘   └─────┴─────┴─────┘
```

### Layer 2 (NAV)

```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │     │     │     │     │   │     │WIN ←│WIN ↓│WIN ↑│WIN →│     │     │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│ TAB │     │     │ EMJ │ CLB │     │     │   │BSPC │  ←  │  ↓  │  ↑  │  →  │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │     │   │LSFT/│     │     │     │     │     │     │
└─────┴─────┴─────┴─────┼─────┼─────┤ SPC │   │ ENT ├─────┼─────┼─────┴─────┴─────┴─────┘
                        │ ALT │CTRL │     │   │     │MO(1)│ APP │
                        └─────┴─────┴─────┘   └─────┴─────┴─────┘
```

### Layer 3 (SYSTEM)

```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │MUTE │VOL- │VOL+ │     │     │     │   │     │     │DSKCL│LOCK │FEXP │SNIP │     │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │RGB  │RGB- │RGB+ │     │     │     │   │     │     │DSKNW│DSKPV│DSKNX│     │     │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │BRI- │BRI+ │     │     │     │   │     │     │CLSPC│NWTAB│CYTAB│     │     │
└─────┴─────┴─────┴─────┼─────┼─────┤MPLY │   │     ├─────┼─────┼─────┴─────┴─────┴─────┘
                        │ RW  │ FF  │     │   │     │     │     │
                        └─────┴─────┴─────┘   └─────┴─────┴─────┘
```

**Layer Navigation:**

- **MO(2)**: Hold to momentarily access NUMS layer
- **MO(3)**: Hold to momentarily access NAV layer
- **MO(4)**: Hold to momentarily access SYSTEM layer
- **LLCK**: Lock into current layer

**Key Functions:**

- **`LOCK`**: Windows lock command (WIN + L)
- **`DSKCL`**: Windows close current desktop (WIN + CTRL + F4)
- **`DSKCL`**: Windows create new desktop (WIN + CTRL + D)
- **`DSKPV`**: Windows previous opened desktop (WIN + CTRL + ←)
- **`DSKNX`**: Windows next opened desktop (WIN + CTRL + →)
- **`MSB4`**: mouse click no. 4, back
- **`MSB5`**: mouse click no. 5, forward
- **`MPLY`**: media play button.
- **`SF/TB`**: hold for shift, tap for tab
- **`LSFT/ENT`**: hold for shift, tap for enter
- **`SFT|C`**: hold for Shift, tap Caps Lock
- **`EMJ`**: emoji board (windows) (WIN + .)
- **`CLB`**: clipboard (windows) (WIN + V)
- **`SNIP`**: shortcut for windows snipping tool.
- **`FEXP`**: shortcut for windows file explorer.
- **`WIN ←`**: place current window left.
- **`WIN ↓`**: place current window down.
- **`WIN ↑`**: place current window up.
- **`WIN →`**: place current window right.

**Override Keys:**

- **`ALT + NUM1`**: F1
- **`ALT + NUM2`**: F2
- **`ALT + NUM3`**: F3
- **`ALT + NUM4`**: F4
- **`ALT + NUM5`**: F5
- **`ALT + NUM6`**: F6
- **`ALT + NUM7`**: F7
- **`ALT + NUM8`**: F8
- **`ALT + NUM9`**: F9
- **`ALT + NUM10`**: F10
- **`ALT + ADD`**: F11
- **`ALT + MINUS`**: F12
- **`SFT + BSPC`**: DEL

## Flashing

1. Clone qmk_firmware:
   - https://github.com/qmk/qmk_firmware.git

2. Copy the _following_ files to _qmk_firmware/keyboards/crkbd/your_keymap_name/_
   - .hammerspoon
   - keymaps.c
   - config.h
   - rules.mk

3. Connect one side of the keyboard (do not connect both keyboard via TRRS when flashing) and enter its boot mode, usually double-tap on the lower part of the keyboard. _Left-side might be under key X_ while _right-side might be under the key DOT_.

4. Flash to keyboard:

```
qmk flash -kb crkbd/rev4_1/standard -km your_keymap_name
```

NOTE: alternatively you can run the compile command first then flash later if your keyboard's availability is still "on-cart".

```
qmk compile -kb crkbd/rev4_1/standard -km your_keymap_name
```
