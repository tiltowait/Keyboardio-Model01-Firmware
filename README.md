# Keyboardio Model 01 Firmware

A reasonably lightweight [Keyboardio Model 01](http://keyboard.io) firmware configuration package used by me. It has a number of shortcut keys particular to my system, but it could theoretically be used as a starting point for someone else.

## Installation

You can clone all necessary [Kaleidoscope](https://github.com/keyboardio/Kaleidoscope) code by invoking `make setup`. Additionally, `make update` will do just what it says on the tin.

This functionality is shamelessly stolen from [algernon's sketch](https://github.com/keyboardio/Kaleidoscope).

## Plugins Used

* MouseKeys
* LEDControl
* NumPad
* LEDEffect-Rainbow
* Qukeys
* ProperShifting
* TapDance

## Special Keys

"Special keys" are keys with modifiers applied to them. For instance: `LCTRL(Key_Spacebar)`. Below is a list of such keys, plus an explanation. All are intended for a (specific) Mac.

### `KEY_EMDASH`

A simple shortcut to produce an em-dash on a Mac.

### `KEY_LAUNCHBAR`

A simple shortcut to invoke LaunchBar via keyboard shortcut (Ctrl+Space, on my system).

### `KEY_DEL_LINE`

A simple shortcut to delete the contents of the line left of the cursor. Also deletes selected files, items, etc. that respond to Cmd+Delete.

### `KEY_1PASSWORD`

A simple shortcut to invoke 1Password Mini (Cmd+\ on my system.).

### `KEY_VS_TERM`

Invokes the built-in terminal for VS Code (custom keyboard shortcut, `Ctrl+Alt+\``).

### `TD_BACK` and `TD_FORWARD`

TapDance keys that send left- and right-control when held or browser back and forward (respectively). If TapDance isn't included, then these keys revert to the appropriate control keys.

This functionality was originally implemented in Qukeys, but I kept accidentally triggering them and losing a lot of work.

## Notes

Some of the plugins are arguably removable, namely NumPad and MouseKeys.

Qukeys is currently used for only a single key (tap Alt for Enter, or hold for Alt). A simpler solution may be possible.

[`Kaleidoscope-HostPowerManagement`](https://github.com/keyboardio/Kaleidoscope-HostPowerManagement) is currently disabled because of a bug in upstream. I will be revisiting it sometime in the future.

[`Kaleidoscope-ProperShifting`](https://github.com/tiltowait/Kaleidoscope-ProperShifting) is my own, custom plugin.

[`Kaleidoscope-AutoShift`](https://github.com/tiltowait/Kaleidoscope-AutoShift) is another plugin written by me. I have it disabled by default, but it's included for development purposes.

## Special Thanks

Thanks to algernon not only for the `Makefile` and builder, but also for inspiration for the structure of this repo.