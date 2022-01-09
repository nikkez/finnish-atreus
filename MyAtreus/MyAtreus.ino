/* -*- mode: c++ -*-
 * Atreus -- Chrysalis-enabled Sketch for the Keyboardio Atreus
 * Copyright (C) 2018, 2019  Keyboard.io, Inc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

#include "Kaleidoscope.h"
#include "Kaleidoscope-FocusSerial.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-OneShot.h"
#include "Kaleidoscope-Qukeys.h"
#include "Kaleidoscope-SpaceCadet.h"
#include "kaleidoscope/keyswitch_state.h"

#define MO(n) ShiftToLayer(n)
#define ML(n) MoveToLayer(n)
#define TG(n) LockLayer(n)

enum {
  MACRO_VERSION_INFO,
  M_BACKTICK_AND_TILDE,
  M_SEMICOLON_AND_COLON,
  M_BACKSLASH_AND_PIPE,
  M_COMMA_AND_LESS_THAN,
  M_PERIOD_AND_GREATER_THAN,
  M_SLASH_AND_QUESTIONMARK,
  M_QUOTE_AND_DOUBLEQUOTE,
  M_CARET,
  M_PARENTHESIS,
  M_ANGLES,
  M_ALT_1,
  M_ALT_2,
  M_ALT_3,
  M_ALT_4,
  M_ALT_5,
  M_ALT_6,
  M_ALT_7,
  M_ALT_8,
  M_ALT_9,
  M_ALT_0,
};

#define Key_Exclamation LSHIFT(Key_1)
#define Key_At LSHIFT(Key_2)
#define Key_Hash LSHIFT(Key_3)
#define Key_Dollar LSHIFT(Key_4)
#define Key_Percent LSHIFT(Key_5)
#define Key_Caret LSHIFT(Key_6)
#define Key_And LSHIFT(Key_7)
#define Key_Star LSHIFT(Key_8)
#define Key_Plus LSHIFT(Key_Equals)

#define FI_Key_Semicolon LSHIFT(Key_Comma)
#define FI_Key_Colon LSHIFT(Key_Period)
#define FI_Key_Dollar RALT(Key_4)
#define FI_Key_At RALT(Key_2)
#define FI_Key_ouml Key_Semicolon
#define FI_Key_auml Key_Quote
#define FI_Key_aring Key_LeftBracket
#define FI_Key_Plus Key_Minus
#define FI_Key_Minus Key_Minus
#define FI_Key_Quote Key_Backslash
#define FI_Key_Doublequote LSHIFT(Key_2)
#define FI_Key_LeftParen LSHIFT(Key_8)
#define FI_Key_RightParen LSHIFT(Key_9)
#define FI_Key_LeftCurlyBrace RALT(Key_7)
#define FI_Key_RightCurlyBrace RALT(Key_0)
#define FI_Key_LeftBracket RALT(Key_8)
#define FI_Key_RightBracket RALT(Key_9)
#define FI_Key_Equals LSHIFT(Key_0)
#define FI_Key_LessThan Key_NonUsBackslashAndPipe
#define FI_Key_GreaterThan LSHIFT(Key_NonUsBackslashAndPipe)
#define FI_Key_Minus Key_Slash
#define FI_Key_Pipe RALT(Key_NonUsBackslashAndPipe)
#define FI_Key_And LSHIFT(Key_6)
#define FI_Key_Star LSHIFT(Key_Backslash)

enum {
  QWERTY,
  LAYER_1,
  FUN,
  UPPER,
  SCAND_AND_F_KEYS,
};

/* *INDENT-OFF* */
KEYMAPS(
  [QWERTY] = KEYMAP_STACKED
  (
       Key_Q                   ,Key_W       ,Key_E        ,Key_R                    ,Key_T
      ,LT(SCAND_AND_F_KEYS, A) ,Key_S       ,Key_D        ,Key_F                    ,Key_G
      ,Key_Z                   ,Key_X       ,Key_C        ,Key_V                    ,Key_B                        ,M(M_BACKTICK_AND_TILDE)
      ,Key_Tab                 ,Key_LeftGui ,Key_LeftAlt  ,Key_LeftShift            ,Key_Backspace                ,CTL_T(Escape)
      

                               ,Key_Y       ,Key_U        ,Key_I                    ,Key_O                        ,Key_P
                               ,Key_H       ,Key_J        ,Key_K                    ,Key_L                        ,M(M_SEMICOLON_AND_COLON)
      ,M(M_BACKSLASH_AND_PIPE) ,Key_N       ,Key_M        ,M(M_COMMA_AND_LESS_THAN) ,M(M_PERIOD_AND_GREATER_THAN) ,M(M_SLASH_AND_QUESTIONMARK)
      ,___                     ,Key_Space   ,MO(FUN)      ,FI_Key_Minus             ,M(M_QUOTE_AND_DOUBLEQUOTE)   ,Key_Enter
  ),
  [LAYER_1] = KEYMAP_STACKED
  (
       Key_1  ,Key_2 ,Key_3 ,Key_4  ,Key_5
      ,___    ,___   ,___   ,___    ,___
      ,___    ,___   ,___   ,___    ,___    ,___
      ,___    ,___   ,___   ,___    ,___    ,___

              ,Key_6         ,Key_7         ,Key_8             ,Key_9          ,Key_0
              ,Key_LeftArrow ,Key_DownArrow ,Key_UpArrow       ,Key_RightArrow ,___
      ,___    ,___           ,___           ,___               ,___            ,___
      ,___    ,ML(QWERTY)    ,___           ,___               ,___            ,___
   ),
  [FUN] = KEYMAP_STACKED
  (
       Key_Exclamation    ,FI_Key_At           ,Key_UpArrow   ,FI_Key_Dollar         ,Key_Percent
      ,FI_Key_LeftParen   ,Key_LeftArrow       ,Key_DownArrow ,Key_RightArrow        ,FI_Key_RightParen
      ,FI_Key_LeftBracket ,FI_Key_RightBracket ,Key_Hash      ,FI_Key_LeftCurlyBrace ,FI_Key_RightCurlyBrace ,M(M_CARET)
      ,TG(UPPER)          ,___                 ,___           ,___                   ,___                    ,___

                          ,Key_PageUp          ,Key_7         ,Key_8                 ,Key_9                  ,Key_Percent
                          ,Key_PageDown        ,Key_4         ,Key_5                 ,Key_6                  ,___
      ,FI_Key_And         ,FI_Key_Star         ,Key_1         ,Key_2                 ,Key_3                  ,FI_Key_Plus
      ,___                ,___                 ,___           ,___                   ,Key_0                  ,FI_Key_Equals
   ),
      /*
  [FUN] = KEYMAP_STACKED
  (
        ___  ,___ ,___ ,___  ,___
       ,___  ,___ ,___ ,___  ,___
       ,___  ,___ ,___ ,___  ,___  ,___
       ,___  ,___ ,___ ,___  ,___  ,___

             ,___ ,___ ,___  ,___  ,___
             ,___ ,___ ,___  ,___  ,___
       ,___  ,___ ,___ ,___  ,___  ,___
       ,___  ,___ ,___ ,___  ,___  ,___
   ),
   */
  /*
  [FUN] = KEYMAP_STACKED
  (
       ___  ,___ ,___ ,___  ,___
      ,___  ,___ ,___ ,___  ,___
      ,___  ,___ ,___ ,___  ,___ ,___
      ,___  ,___ ,___ ,___  ,___ ,___

            ,___ ,___ ,___  ,___ ,___
            ,___ ,___ ,___  ,___ ,___
      ,___  ,___ ,___ ,___  ,___ ,___
      ,___  ,___ ,___ ,___  ,___ ,___
   ),
   */
  [UPPER] = KEYMAP_STACKED
  (
       Key_Insert            ,Key_Home                 ,Key_UpArrow         ,Key_End         ,Key_PageUp
      ,Key_Delete            ,Key_LeftArrow            ,Key_DownArrow       ,Key_RightArrow  ,Key_PageDown
      ,M(MACRO_VERSION_INFO) ,Consumer_VolumeIncrement ,XXX                 ,XXX             ,___            ,___
      ,MoveToLayer(QWERTY)   ,Consumer_VolumeDecrement ,___                 ,___             ,___            ,___

                             ,Key_UpArrow              ,Key_F7              ,Key_F8          ,Key_F9         ,Key_F10
                             ,Key_DownArrow            ,Key_F4              ,Key_F5          ,Key_F6         ,Key_F11
      ,___                   ,XXX                      ,Key_F1              ,Key_F2          ,Key_F3         ,Key_F12
      ,___                   ,___                      ,MoveToLayer(QWERTY) ,Key_PrintScreen ,Key_ScrollLock ,Consumer_PlaySlashPause
   ),

  [SCAND_AND_F_KEYS] = KEYMAP_STACKED
  (
       Key_mouseScrollUp ,___           ,Key_mouseUp        ,___           ,___
      ,Key_mouseScrollDn ,Key_mouseL    ,Key_mouseDn        ,Key_mouseR    ,___
      ,___               ,Key_mouseBtnL ,Key_mouseBtnM      ,Key_mouseBtnR ,___         ,___
      ,___               ,___           ,___                ,___           ,___         ,___

                         ,Key_F1        ,Key_F2             ,Key_F3        ,___         ,FI_Key_aring
                         ,Key_F4        ,Key_F5             ,Key_F6        ,FI_Key_ouml ,FI_Key_auml
      ,___               ,Key_F7        ,Key_F8             ,Key_F9        ,Key_Keypad3 ,___
      ,___               ,Key_F10       ,Key_F11            ,Key_F12       ,___         ,Key_KeypadEnter
   ),

)
/* *INDENT-ON* */

KALEIDOSCOPE_INIT_PLUGINS(
  Qukeys,
  SpaceCadet,
  OneShot,
  Macros,
  MouseKeys
);

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  bool left_shift = kaleidoscope::Runtime.hid().keyboard().isModifierKeyActive(Key_LeftShift);
  switch (macroIndex) {
  case MACRO_VERSION_INFO:
    if (keyToggledOn(keyState)) {
      Macros.type(PSTR("Keyboardio Atreus - Kaleidoscope "));
      Macros.type(PSTR(BUILD_INFORMATION));
    }
    break;
  case M_BACKTICK_AND_TILDE:
    if (keyToggledOn(keyState)) {
      if (left_shift) {
        kaleidoscope::Runtime.hid().keyboard().releaseRawKey(Key_LeftShift);
        kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_RightAlt);
        kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_RightCurlyBracket);
        kaleidoscope::Runtime.hid().keyboard().sendReport();
        kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_Space);
      } else {
        kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_LeftShift);
        kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_Equals);
        kaleidoscope::Runtime.hid().keyboard().sendReport();
        kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_Space);
      }
    }
    break;
  case M_SEMICOLON_AND_COLON:
    if (keyToggledOn(keyState)) {
      if (left_shift) {
        kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_Period);
      } else {
        kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_LeftShift);
        kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_Comma);
      }
    }
    break;
  case M_BACKSLASH_AND_PIPE:
    if (keyToggledOn(keyState)) {
      if (left_shift) {
        kaleidoscope::Runtime.hid().keyboard().releaseRawKey(Key_LeftShift);
        kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_RightAlt);
        kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_NonUsBackslashAndPipe);
      } else {
        kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_RightAlt);
        kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_Minus);
      }
    }
    break;
  case M_COMMA_AND_LESS_THAN:
    if (keyToggledOn(keyState)) {
      if (left_shift) {
        kaleidoscope::Runtime.hid().keyboard().releaseRawKey(Key_LeftShift);
        kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_NonUsBackslashAndPipe);
      } else {
        kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_Comma);
      }
    }
    break;
  case M_PERIOD_AND_GREATER_THAN:
    if (keyToggledOn(keyState)) {
      if (left_shift) {
        kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_NonUsBackslashAndPipe);
      } else {
        kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_Period);
      }
    }
    break;
  case M_SLASH_AND_QUESTIONMARK:
    if (keyToggledOn(keyState)) {
      if (left_shift) {
        kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_Minus);
      } else {
        kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_LeftShift);
        kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_7);
      }
    }
    break;
  case M_QUOTE_AND_DOUBLEQUOTE:
    if (keyToggledOn(keyState)) {
      if (left_shift) {
        return MACRO(T(2));
        //kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_2);
      } else {
        return MACRO(T(Backslash));
        //kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_Backslash);
      }
    }
    break;
  case M_CARET:
    if (keyToggledOn(keyState)) {
      if (!left_shift) {
        kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_LeftShift);
      }
      kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_RightBracket);
      kaleidoscope::Runtime.hid().keyboard().sendReport();
      kaleidoscope::Runtime.hid().keyboard().pressRawKey(Key_Space);
    }
    break;
  case M_PARENTHESIS:
    if (keyToggledOn(keyState)) {
      return MACRO(D(LeftShift), T(8), T(9), U(LeftShift), T(LeftArrow));
    }
  case M_ANGLES:
    if (keyToggledOn(keyState)) {
      return MACRO(T(NonUsBackslashAndPipe), D(LeftShift), T(NonUsBackslashAndPipe), U(LeftShift), T(LeftArrow));
    }
    break;
    break;
  case M_ALT_1:
    if (keyToggledOn(keyState)) {
      return MACRO(D(LeftAlt), T(1));
    }
    break;
  case M_ALT_2:
    if (keyToggledOn(keyState)) {
      return MACRO(D(LeftAlt), T(2));
    }
    break;
  case M_ALT_3:
    if (keyToggledOn(keyState)) {
      return MACRO(D(LeftAlt), T(3));
    }
    break;
  case M_ALT_4:
    if (keyToggledOn(keyState)) {
      return MACRO(D(LeftAlt), T(4));
    }
    break;
  case M_ALT_5:
    if (keyToggledOn(keyState)) {
      return MACRO(D(LeftAlt), T(5));
    }
    break;
  case M_ALT_6:
    if (keyToggledOn(keyState)) {
      return MACRO(D(LeftAlt), T(6));
    }
    break;
  case M_ALT_7:
    if (keyToggledOn(keyState)) {
      return MACRO(D(LeftAlt), T(7));
    }
    break;
  case M_ALT_8:
    if (keyToggledOn(keyState)) {
      return MACRO(D(LeftAlt), T(8));
    }
    break;
  case M_ALT_9:
    if (keyToggledOn(keyState)) {
      return MACRO(D(LeftAlt), T(9));
    }
    break;
  case M_ALT_0:
    if (keyToggledOn(keyState)) {
      return MACRO(D(LeftAlt), T(0));
    }
    break;
  default:
    break;
  }

  return MACRO_NONE;
}

void setup() {
  Kaleidoscope.setup();
  SpaceCadet.disable();
  QUKEYS(
      kaleidoscope::plugin::Qukey(QWERTY, KeyAddr(0, 0), M(M_ALT_1)),
      kaleidoscope::plugin::Qukey(QWERTY, KeyAddr(0, 1), M(M_ALT_2)),
      kaleidoscope::plugin::Qukey(QWERTY, KeyAddr(0, 2), M(M_ALT_3)),
      kaleidoscope::plugin::Qukey(QWERTY, KeyAddr(0, 3), M(M_ALT_4)),
      kaleidoscope::plugin::Qukey(QWERTY, KeyAddr(0, 4), M(M_ALT_5)),
      kaleidoscope::plugin::Qukey(QWERTY, KeyAddr(0, 7), M(M_ALT_6)),
      kaleidoscope::plugin::Qukey(QWERTY, KeyAddr(0, 8), M(M_ALT_7)),
      kaleidoscope::plugin::Qukey(QWERTY, KeyAddr(0, 9), M(M_ALT_8)),
      kaleidoscope::plugin::Qukey(QWERTY, KeyAddr(0, 10), M(M_ALT_9)),
      kaleidoscope::plugin::Qukey(QWERTY, KeyAddr(0, 11), M(M_ALT_0)),
      kaleidoscope::plugin::Qukey(QWERTY, KeyAddr(2, 2), LSHIFT(Key_8)),
      kaleidoscope::plugin::Qukey(QWERTY, KeyAddr(2, 9), LSHIFT(Key_9)),
      kaleidoscope::plugin::Qukey(QWERTY, KeyAddr(2, 3), Key_NonUsBackslashAndPipe),
      kaleidoscope::plugin::Qukey(QWERTY, KeyAddr(2, 8), LSHIFT(Key_NonUsBackslashAndPipe)),
      kaleidoscope::plugin::Qukey(QWERTY, KeyAddr(2, 1), RALT(Key_7)),
      kaleidoscope::plugin::Qukey(QWERTY, KeyAddr(2, 10), RALT(Key_0)),
      );
  /*
      */
}

void loop() {
  Kaleidoscope.loop();
}
