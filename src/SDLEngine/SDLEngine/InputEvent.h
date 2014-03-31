/*
 * Copyright (C) 2006-2014 Christopho, Solarus - http://www.solarus-games.org
 * 
 * Solarus is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Solarus is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SOLARUS_INPUT_EVENT_H
#define SOLARUS_INPUT_EVENT_H

#include <SDL_events.h>
#include <string>
#include <map>

typedef struct _SDL_Joystick SDL_Joystick;

/**
 * \brief Represents a low-level event.
 *
 * This low-level class provides an API for input events (keyboard, joypad and window events).
 * It encapsulates the library-dependent events.
 */
class InputEvent {

  public:

    /**
     * Enumeration of keyboard keys.
     * This is a Solarus dedicated enumeration.
     * To make the SDL encapsulation easier, this enumeration is compatible
     * with the SDLKey enumeration from SDL.
     * If you intend to replace SDL by another library one day, the API of the
     * Input class will not have to change
     * (only its implementation will).
     * The numeric values of the enumeration can be changed without breaking
     * savegames because savegames use a string name to store the commands.
     */
    enum KeyboardKey {
      KEY_NONE                     = SDLK_UNKNOWN,
      KEY_BACKSPACE                = SDLK_BACKSPACE,
      KEY_TABULATION               = SDLK_TAB,
      KEY_CLEAR                    = SDLK_CLEAR,
      KEY_RETURN                   = SDLK_RETURN,
      KEY_PAUSE                    = SDLK_PAUSE,
      KEY_ESCAPE                   = SDLK_ESCAPE,
      KEY_SPACE                    = SDLK_SPACE,
      KEY_EXCLAMATION_MARK         = SDLK_EXCLAIM,
      KEY_DOULE_QUOTE              = SDLK_QUOTEDBL,
      KEY_HASH                     = SDLK_HASH,
      KEY_DOLLAR                   = SDLK_DOLLAR,
      KEY_AMPERSAND                = SDLK_AMPERSAND,
      KEY_SINGLE_QUOTE             = SDLK_QUOTE,
      KEY_LEFT_PARENTHESIS         = SDLK_LEFTPAREN,
      KEY_RIGHT_PARENTHESIS        = SDLK_RIGHTPAREN,
      KEY_ASTERISK                 = SDLK_ASTERISK,
      KEY_PLUS                     = SDLK_PLUS,
      KEY_COMMA                    = SDLK_COMMA,
      KEY_MINUS                    = SDLK_MINUS,
      KEY_PERIOD                   = SDLK_PERIOD,
      KEY_SLASH                    = SDLK_SLASH,
      KEY_0                        = SDLK_0,
      KEY_1                        = SDLK_1,
      KEY_2                        = SDLK_2,
      KEY_3                        = SDLK_3,
      KEY_4                        = SDLK_4,
      KEY_5                        = SDLK_5,
      KEY_6                        = SDLK_6,
      KEY_7                        = SDLK_7,
      KEY_8                        = SDLK_8,
      KEY_9                        = SDLK_9,
      KEY_COLON                    = SDLK_COLON,
      KEY_SEMICOLON                = SDLK_SEMICOLON,
      KEY_LESS                     = SDLK_LESS,
      KEY_EQUALS                   = SDLK_EQUALS,
      KEY_GREATER                  = SDLK_GREATER,
      KEY_QUESTION_MARK            = SDLK_QUESTION,
      KEY_AT                       = SDLK_AT,
      KEY_LEFT_BRACKET             = SDLK_LEFTBRACKET,
      KEY_BACKSLASH                = SDLK_BACKSLASH,
      KEY_RIGHT_BRACKET            = SDLK_RIGHTBRACKET,
      KEY_CARET                    = SDLK_CARET,
      KEY_UNDERSCORE               = SDLK_UNDERSCORE,
      KEY_BACKQUOTE                = SDLK_BACKQUOTE,
      KEY_a                        = SDLK_a,
      KEY_b                        = SDLK_b,
      KEY_c                        = SDLK_c,
      KEY_d                        = SDLK_d,
      KEY_e                        = SDLK_e,
      KEY_f                        = SDLK_f,
      KEY_g                        = SDLK_g,
      KEY_h                        = SDLK_h,
      KEY_i                        = SDLK_i,
      KEY_j                        = SDLK_j,
      KEY_k                        = SDLK_k,
      KEY_l                        = SDLK_l,
      KEY_m                        = SDLK_m,
      KEY_n                        = SDLK_n,
      KEY_o                        = SDLK_o,
      KEY_p                        = SDLK_p,
      KEY_q                        = SDLK_q,
      KEY_r                        = SDLK_r,
      KEY_s                        = SDLK_s,
      KEY_t                        = SDLK_t,
      KEY_u                        = SDLK_u,
      KEY_v                        = SDLK_v,
      KEY_w                        = SDLK_w,
      KEY_x                        = SDLK_x,
      KEY_y                        = SDLK_y,
      KEY_z                        = SDLK_z,
      KEY_DELETE                   = SDLK_DELETE,

      KEY_KP0                      = SDLK_KP_0,
      KEY_KP1                      = SDLK_KP_1,
      KEY_KP2                      = SDLK_KP_2,
      KEY_KP3                      = SDLK_KP_3,
      KEY_KP4                      = SDLK_KP_4,
      KEY_KP5                      = SDLK_KP_5,
      KEY_KP6                      = SDLK_KP_6,
      KEY_KP7                      = SDLK_KP_7,
      KEY_KP8                      = SDLK_KP_8,
      KEY_KP9                      = SDLK_KP_9,
      KEY_KP_PERIOD                = SDLK_KP_PERIOD,
      KEY_KP_DIVIDE                = SDLK_KP_DIVIDE,
      KEY_KP_MULTIPLY              = SDLK_KP_MULTIPLY,
      KEY_KP_MINUS                 = SDLK_KP_MINUS,
      KEY_KP_PLUS                  = SDLK_KP_PLUS,
      KEY_KP_ENTER                 = SDLK_KP_ENTER,
      KEY_KP_EQUALS                = SDLK_KP_EQUALS,

      KEY_UP                       = SDLK_UP,
      KEY_DOWN                     = SDLK_DOWN,
      KEY_RIGHT                    = SDLK_RIGHT,
      KEY_LEFT                     = SDLK_LEFT,
      KEY_INSERT                   = SDLK_INSERT,
      KEY_HOME                     = SDLK_HOME,
      KEY_END                      = SDLK_END,
      KEY_PAGE_UP                  = SDLK_PAGEUP,
      KEY_PAGE_DOWN                = SDLK_PAGEDOWN,

      KEY_F1                       = SDLK_F1,
      KEY_F2                       = SDLK_F2,
      KEY_F3                       = SDLK_F3,
      KEY_F4                       = SDLK_F4,
      KEY_F5                       = SDLK_F5,
      KEY_F6                       = SDLK_F6,
      KEY_F7                       = SDLK_F7,
      KEY_F8                       = SDLK_F8,
      KEY_F9                       = SDLK_F9,
      KEY_F10                      = SDLK_F10,
      KEY_F11                      = SDLK_F11,
      KEY_F12                      = SDLK_F12,
      KEY_F13                      = SDLK_F13,
      KEY_F14                      = SDLK_F14,
      KEY_F15                      = SDLK_F15,

      KEY_NUMLOCK                  = SDLK_NUMLOCKCLEAR,
      KEY_CAPSLOCK                 = SDLK_CAPSLOCK,
      KEY_SCROLLOCK                = SDLK_SCROLLLOCK,
      KEY_RIGHT_SHIFT              = SDLK_RSHIFT,
      KEY_LEFT_SHIFT               = SDLK_LSHIFT,
      KEY_RIGHT_CONTROL            = SDLK_RCTRL,
      KEY_LEFT_CONTROL             = SDLK_LCTRL,
      KEY_RIGHT_ALT                = SDLK_RALT,
      KEY_LEFT_ALT                 = SDLK_LALT,
      KEY_RIGHT_META               = SDLK_RGUI,
      KEY_LEFT_META                = SDLK_LGUI
    };

    static void initialize();
    static void quit();

    ~InputEvent();

    // retrieve the current event
    static InputEvent* get_event();

    // global information
    static void set_key_repeat(bool repeat);
    static bool is_shift_down();
    static bool is_control_down();
    static bool is_alt_down();
    static bool is_caps_lock_on();
    static bool is_num_lock_on();
    static bool is_key_down(KeyboardKey key);
    static bool is_joypad_button_down(int button);
    static int get_joypad_axis_state(int axis);
    static int get_joypad_hat_direction(int hat);

    // event type
    bool is_keyboard_event() const;
    bool is_joypad_event() const;
    bool is_window_event() const;

    // keyboard
    bool is_keyboard_key_pressed() const;
    bool is_keyboard_key_pressed(KeyboardKey key) const;
    bool is_keyboard_key_pressed(const KeyboardKey* keys) const;
    bool is_keyboard_direction_key_pressed() const;
    bool is_keyboard_non_direction_key_pressed() const;

    bool is_keyboard_key_released() const;
    bool is_keyboard_key_released(KeyboardKey key) const;
    bool is_keyboard_key_released(const KeyboardKey* keys) const;
    bool is_keyboard_direction_key_released() const;
    bool is_keyboard_non_direction_key_released() const;

    bool is_with_shift() const;
    bool is_with_control() const;
    bool is_with_alt() const;

    KeyboardKey get_keyboard_key() const;
    static const std::string& get_keyboard_key_name(InputEvent::KeyboardKey key);
    static InputEvent::KeyboardKey get_keyboard_key_by_name(const std::string& keyboard_key_name);

    bool is_character_pressed() const;
    const std::string get_character() const;

    // joypad
    static bool is_joypad_enabled();
    static void set_joypad_enabled(bool joypad_enabled);

    bool is_joypad_button_pressed() const;
    bool is_joypad_button_released() const;
    int get_joypad_button() const;
    bool is_joypad_axis_moved() const;
    int get_joypad_axis() const;
    int get_joypad_axis_state() const;
    bool is_joypad_axis_centered() const;
    bool is_joypad_hat_moved() const;
    int get_joypad_hat() const;
    int get_joypad_hat_direction() const;
    bool is_joypad_hat_centered() const;

    // functions common to keyboard and joypad
    int get_direction() const;
    bool is_pressed() const;
    bool is_direction_pressed() const;
    bool is_non_direction_pressed() const;
    bool is_released() const;

    // window event
    bool is_window_closing() const;

  private:

    InputEvent(const SDL_Event& event);

    static const KeyboardKey directional_keys[];  /**< array of the keyboard directional keys */
    static bool joypad_enabled;                   /**< true if joypad support is enabled
                                                   * (may be true even without joypad plugged) */
    static SDL_Joystick* joystick;                /**< the joystick object if enabled and plugged */
    static std::map<KeyboardKey, std::string>
      keyboard_key_names;                         /**< Names of all existing keyboard keys. */
    static bool repeat_keyboard;                  /**< True to handle repeat KEYDOWN and KEYUP events. */

    const SDL_Event internal_event;               /**< the internal event encapsulated */

};

#endif