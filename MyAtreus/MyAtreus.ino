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
#include "Kaleidoscope-Qukeys.h"
#include "kaleidoscope/keyswitch_state.h"
#include "Kaleidoscope-CharShift.h"

#define MO(n) ShiftToLayer(n)
#define ML(n) MoveToLayer(n)
#define TG(n) LockLayer(n)

enum {
  MACRO_VERSION_INFO,
  M_BACKTICK_AND_TILDE,
  M_BACKSLASH_AND_PIPE,
  M_CARET,
  M_PARENTHESIS,
  M_ANGLES,
  M_DOUBLE_EQUALS,
  M_ALT_SHIFT_COMMA,
  M_ALT_SHIFT_X_T,
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
#define FI_Key_QuestionMark LSHIFT(Key_Minus)
#define FI_Key_Slash LSHIFT(Key_7)
#define Key_PA2 LALT(Key_Home)

enum {
  QWERTY,
  OMEGA,
  FUN,
  UPPER,
  SCAND_AND_F_KEYS,
};

enum CS_FI {
  COMMA_AND_LESS_THAN,
  PERIOD_AND_GREATER_THAN,
  SLASH_AND_QUESTION_MARK,
  QUOTE_AND_DOUBLE_QUOTE,
  COLON_AND_SEMICOLON,
};

/* *INDENT-OFF* */
KEYMAPS(
  [QWERTY] = KEYMAP_STACKED
  (
       Key_Q                   ,Key_W       ,Key_E        ,Key_R             ,Key_T
      ,LT(SCAND_AND_F_KEYS, A) ,Key_S       ,Key_D        ,Key_F             ,Key_G
      ,Key_Z                   ,Key_X       ,Key_C        ,Key_V             ,Key_B                       ,M(M_BACKTICK_AND_TILDE)
      ,Key_LeftControl         ,Key_LeftGui ,Key_Tab      ,Key_LeftShift     ,Key_Backspace               ,Key_LeftAlt
      

                               ,Key_Y       ,Key_U        ,Key_I                           ,Key_O                              ,Key_P
                               ,Key_H       ,Key_J        ,Key_K                           ,Key_L                              ,CS(CS_FI::COLON_AND_SEMICOLON)
      ,M(M_BACKSLASH_AND_PIPE) ,Key_N       ,Key_M        ,CS(CS_FI::COMMA_AND_LESS_THAN)  ,CS(CS_FI::PERIOD_AND_GREATER_THAN) ,CS(CS_FI::SLASH_AND_QUESTION_MARK)
      ,MO(OMEGA)               ,Key_Space   ,MO(FUN)      ,FI_Key_Minus                    ,CS(CS_FI::QUOTE_AND_DOUBLE_QUOTE)  ,Key_Enter
  ),
  [OMEGA] = KEYMAP_STACKED
  (
       LALT(Key_1)          ,LALT(Key_2)         ,LALT(Key_3)               ,LALT(Key_4)    ,LALT(Key_5)
      ,XXX                  ,XXX                 ,LCTRL(LALT(Key_Delete))   ,XXX            ,Key_Insert
      ,XXX                  ,M(M_ALT_SHIFT_X_T)  ,XXX                       ,XXX            ,Key_Delete   ,XXX
      ,XXX                  ,XXX                 ,XXX                       ,XXX            ,XXX          ,XXX

             ,LALT(Key_6) ,LALT(Key_7)  ,LALT(Key_8)      ,LALT(Key_9)       ,LALT(Key_0)
             ,XXX         ,XXX          ,XXX              ,XXX               ,XXX
       ,XXX  ,XXX         ,LALT(Key_F5) ,XXX              ,XXX               ,XXX
       ,XXX  ,XXX         ,XXX          ,XXX              ,XXX               ,XXX
  ),
  [FUN] = KEYMAP_STACKED
  (
       Key_Exclamation    ,FI_Key_At           ,Key_UpArrow   ,FI_Key_Dollar         ,Key_Percent
      ,FI_Key_LeftParen   ,Key_LeftArrow       ,Key_DownArrow ,Key_RightArrow        ,FI_Key_RightParen
      ,FI_Key_LeftBracket ,FI_Key_RightBracket ,Key_Hash      ,FI_Key_LeftCurlyBrace ,FI_Key_RightCurlyBrace ,M(M_CARET)
      ,TG(UPPER)          ,Key_PageUp          ,Key_PageDown  ,___                   ,___                    ,___

                          ,Key_PageUp          ,Key_7         ,Key_8                 ,Key_9                  ,Key_Percent
                          ,Key_PageDown        ,Key_4         ,Key_5                 ,Key_6                  ,___
      ,FI_Key_And         ,FI_Key_Star         ,Key_1         ,Key_2                 ,Key_3                  ,FI_Key_Plus
      ,___                ,___                 ,___           ,Key_LeftShift         ,Key_0                  ,FI_Key_Equals
   ),
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
       XXX               ,XXX           ,XXX                ,XXX           ,XXX
      ,XXX               ,XXX           ,XXX                ,XXX           ,XXX
      ,XXX               ,XXX           ,XXX                ,XXX           ,XXX             ,XXX
      ,XXX               ,XXX           ,XXX                ,Key_LeftShift ,XXX             ,Key_Escape

                         ,Key_F1        ,Key_F2             ,Key_F3        ,XXX             ,FI_Key_aring
                         ,Key_F4        ,Key_F5             ,Key_F6        ,FI_Key_ouml     ,FI_Key_auml
      ,XXX               ,Key_F7        ,Key_F8             ,Key_F9        ,Key_PA2         ,XXX
      ,Key_RightControl  ,Key_F10       ,Key_F11            ,Key_F12       ,XXX             ,Key_KeypadEnter
   ),

)
/* *INDENT-ON* */

namespace kaleidoscope {
namespace plugin {

// When activated, this plugin will suppress any `Shift` key (including modifier
// combos with `Shift`) before it's added to the HID report.
class ShiftBlocker : public Plugin {

 public:
  EventHandlerResult onAddToReport(Key key) {
    if (active_ && key.isKeyboardShift())
      return EventHandlerResult::ABORT;
    return EventHandlerResult::OK;
  }

  void enable() {
    active_ = true;
  }
  void disable() {
    active_ = false;
  }

 private:
  bool active_{false};

};

} // namespace plugin
} // namespace kaleidoscope

kaleidoscope::plugin::ShiftBlocker ShiftBlocker;

KALEIDOSCOPE_INIT_PLUGINS(
  Qukeys,
  Macros,
  CharShift
);

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  bool left_shift = kaleidoscope::Runtime.hid().keyboard().isModifierKeyActive(Key_LeftShift);
  bool left_alt = kaleidoscope::Runtime.hid().keyboard().isModifierKeyActive(Key_LeftAlt);
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
        return MACRO(U(LeftShift), D(RightAlt), T(RightBracket), U(RightAlt), T(Space));
      } else {
        return MACRO(D(LeftShift), T(Equals), U(LeftShift), T(Space));
      }
    }
    break;
  case M_BACKSLASH_AND_PIPE:
    if (keyToggledOn(keyState)) {
      if (left_shift) {
        return MACRO(U(LeftShift), D(RightAlt), T(NonUsBackslashAndPipe));
      } else {
        return MACRO(D(RightAlt), T(Minus));
      }
    }
    break;
  case M_CARET:
    if (keyToggledOn(keyState)) {
      return MACRO(D(LeftShift), T(RightBracket), U(LeftShift), T(Space));
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
  case M_DOUBLE_EQUALS:
    if (keyToggledOn(keyState)) {
      return MACRO(D(LeftShift), T(0), T(0));
    }
    break;
  case M_ALT_SHIFT_COMMA:
    if (keyToggledOn(keyState)) {
      return MACRO(D(LeftShift), D(LeftAlt), T(Comma)); 
    }
    break;
  case M_ALT_SHIFT_X_T:
    if (keyToggledOn(keyState)) {
      return MACRO(D(LeftAlt), D(LeftShift), T(X), U(LeftAlt), U(LeftShift), T(T)); 
    }
    break;
  default:
    break;
  }

  return MACRO_NONE;
}

void setup() {
  Kaleidoscope.serialPort().begin(9600);
  CS_KEYS(
    kaleidoscope::plugin::CharShift::KeyPair(Key_Comma, FI_Key_LessThan),         // CS(0)
    kaleidoscope::plugin::CharShift::KeyPair(Key_Period, FI_Key_GreaterThan),     // CS(1)
    kaleidoscope::plugin::CharShift::KeyPair(FI_Key_Slash, FI_Key_QuestionMark),  // CS(2)
    kaleidoscope::plugin::CharShift::KeyPair(FI_Key_Quote, FI_Key_Doublequote),   // CS(3)
    kaleidoscope::plugin::CharShift::KeyPair(FI_Key_Semicolon, FI_Key_Colon),     // CS(4)
  );
  Kaleidoscope.setup();
}

void loop() {
  Kaleidoscope.loop();
}
