# Keyboardio Model 01 Firmware

My personal Model 01 firmware configuration.

## Plugins Used

* MouseKeys
* Macros
* LEDControl
* NumPad
* LED-Off
* LED-Effect-BootGreeting
* LED-Stalker
* Model01-TestMode
* Qukeys
* BetterShifting (my own personal plugin)

## Macros

All of the following macros are either Mac-only or both Mac-only and specific to my personal machine.

### `MACRO_VERSION_INFO`

Not mapped by default, `MACRO_VERSION_INFO` can be used to make sure the correct firmware is loaded.

### `MACRO_EMDASH`

A simple shortcut to produce an em-dash on a Mac.

### `MACRO_LAUNCHBAR`

A simple shortcut to invoke Launchbar via keyboard shortcut (Ctrl+Space, on my system).

### `MACRO_DEL_LINE`

A simple shortcut to delete the contents of the line left of the cursor. Also deletes selected files, items, etc. that respond to Cmd+Delete.

### `MACRO_1PASSWORD`

A simple shortcut to invoke 1Password Mini (Cmd+\ on my system.).

## Notes

Some of the plugins are arguably removable, namely NumPad, MouseKeys, LED-Stalker, LED-Effect-BootGreeting, and Model01-TestMode.

Qukeys is currently used for only a single key (tap Alt for Enter, or hold for Alt). A simpler solution, such as a macro, might be better.