/* -*- mode: c++ -*-
 * Model01-Sketch -- tiltowait's Model01 Sketch
 * Copyright (C) 2019 Jared Lindsay
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#pragma once

/** The Model 01's key layouts are defined as 'keymaps'. By default, there are three
  * keymaps: The standard QWERTY keymap, the "Function layer" keymap and the "Numpad"
  * keymap.
  *
  * Each keymap is defined as a list using the 'KEYMAP_STACKED' macro, built
  * of first the left hand's layout, followed by the right hand's layout.
  *
  * Keymaps typically consist mostly of `Key_` definitions. There are many, many keys
  * defined as part of the USB HID Keyboard specification. You can find the names
  * (if not yet the explanations) for all the standard `Key_` defintions offered by
  * Kaleidoscope in these files:
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keyboard.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_consumerctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_sysctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keymaps.h
  *
  * Additional things that should be documented here include
  *   using ___ to let keypresses fall through to the previously active layer
  *   using XXX to mark a keyswitch as 'blocked' on this layer
  *   using ShiftToLayer() and LockLayer() keys to change the active keymap.
  *   the special nature of the PROG key
  *   keeping NUM and FN consistent and accessible on all layers
  *
  *
  * The "keymaps" data structure is a list of the keymaps compiled into the firmware.
  * The order of keymaps in the list is important, as the ShiftToLayer(#) and LockLayer(#)
  * macros switch to key layers based on this list.
  *
  *

  * A key defined as 'ShiftToLayer(FUNCTION)' will switch to FUNCTION while held.
  * Similarly, a key defined as 'LockLayer(NUMPAD)' will switch to NUMPAD when tapped.
  */

/**
  * Layers are "0-indexed" -- That is the first one is layer 0. The second one is layer 1.
  * The third one is layer 2.
  * This 'enum' lets us use names like QWERTY, FUNCTION, and NUMPAD in place of
  * the numbers 0, 1 and 2.
  */

enum { QWERTY, FUNCTION, NUMPAD }; // layers

/**
 * Define some special key combos.
 * While we could use macros, this is easier, cheaper, and accomplishes the same thing.
 */
#define KEY_EMDASH      LSHIFT(LALT(Key_Minus))
#define KEY_LAUNCHBAR   LCTRL(Key_Spacebar)
#define KEY_DEL_LINE    LGUI(Key_Backspace)
#define KEY_1PASSWORD   LGUI(Key_Backslash)
#define KEY_THINGS      LCTRL(LALT(Key_Spacebar))
#define KEY_VS_TERM     LCTRL(LALT(Key_Backtick))

/* Temporarily turn off astyle's indent enforcement to make the keymaps better resemble
 * the physical key layout.
 */
// *INDENT-OFF*

KEYMAPS(
  //default layer
  [QWERTY] = KEYMAP_STACKED
  (___,             Key_1,         Key_2,       Key_3,         Key_4, Key_5, KEY_DEL_LINE,
   Key_Backtick,    Key_Q,         Key_W,       Key_E,         Key_R, Key_T, Key_Tab,
   Key_PageUp,      Key_A,         Key_S,       Key_D,         Key_F, Key_G,
   Key_PageDown,    Key_Z,         Key_X,       Key_C,         Key_V, Key_B, Key_Escape,
   LGUI(Key_LeftBracket), Key_Backspace, Key_LeftGui, Key_LeftShift,
   ShiftToLayer(FUNCTION),

   KEY_LAUNCHBAR,  Key_6,     Key_7,        Key_8,            Key_9,      Key_0,         LockLayer(NUMPAD),
   Key_Enter,      Key_Y,     Key_U,        Key_I,            Key_O,      Key_P,         Key_Equals,
                   Key_H,     Key_J,        Key_K,            Key_L,      Key_Semicolon, Key_Quote,
   KEY_EMDASH,     Key_N,     Key_M,        Key_Comma,        Key_Period, Key_Slash,     Key_Minus,
   Key_RightShift, Key_Enter, Key_Spacebar, LGUI(Key_RightBracket),
   ShiftToLayer(FUNCTION)),

  //function layer
  [FUNCTION] =  KEYMAP_STACKED
  (KEY_1PASSWORD, Key_F1,          Key_F2,      Key_F3,     Key_F4,        Key_F5,           Key_LEDEffectNext,
   Key_Tab,       ___,             Key_mouseUp, ___,        Key_mouseBtnR, Key_mouseWarpEnd, Key_mouseWarpNE,
   Key_Home,      Key_mouseL,      Key_mouseDn, Key_mouseR, Key_mouseBtnL, Key_mouseWarpNW,
   Key_End,       Key_PrintScreen, Key_Insert,  ___,        Key_mouseBtnM, Key_mouseWarpSW,  Key_mouseWarpSE,
   KEY_VS_TERM,   Key_Delete,      ___,         ___,
   ___,

   Consumer_ScanPreviousTrack, Key_F6,                 Key_F7,                   Key_F8,                   Key_F9,          Key_F10,          Key_F11,
   Consumer_PlaySlashPause,    Consumer_ScanNextTrack, Key_LeftCurlyBracket,     Key_RightCurlyBracket,    Key_LeftBracket, Key_RightBracket, Key_F12,
                               Key_LeftArrow,          Key_DownArrow,            Key_UpArrow,              Key_RightArrow,  ___,              ___,
   Key_PcApplication,          Key_Mute,               Consumer_VolumeDecrement, Consumer_VolumeIncrement, ___,             Key_Backslash,    Key_Pipe,
   ___, ___, Key_Enter, ___,
   KEY_THINGS),

  //numpad layer
  [NUMPAD] =  KEYMAP_STACKED
  (___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___,
   ___,

   ___,  ___, Key_Keypad7, Key_Keypad8,   Key_Keypad9,        Key_KeypadSubtract, ___,
   ___,                    ___, Key_Keypad4, Key_Keypad5,   Key_Keypad6,        Key_KeypadAdd,      ___,
                           ___, Key_Keypad1, Key_Keypad2,   Key_Keypad3,        Key_Equals,         Key_Quote,
   ___,                    ___, Key_Keypad0, Key_KeypadDot, Key_KeypadMultiply, Key_KeypadDivide,   Key_Enter,
   ___, ___, ___, ___,
   ___)
);

/* Re-enable astyle's indent enforcement */
// *INDENT-ON*