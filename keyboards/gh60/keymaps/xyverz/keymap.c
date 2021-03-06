#include "gh60.h"
#include "action_layer.h"
#include "eeconfig.h"


extern keymap_config_t keymap_config;


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _DV 1
#define _CM 2
#define _FL 3

// Macro name shortcuts
#define QWERTY M(_QW)
#define DVORAK M(_DV)
#define COLEMAK M(_CM)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     *  _QW: Qwerty Layer
     * ,-----------------------------------------------------------.
     * |ESC | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| Backsp|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
     * |-----------------------------------------------------------|
     * |Fn     |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| Return|
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|     Shift|
     * |-----------------------------------------------------------|
     * |Ctrl|Alt |Gui |      Space             |Gui |Alt |Ctrl|  Fn|
     * `-----------------------------------------------------------'
     */
[_QW] = { /* Layer 0: Qwerty */
    {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC},
    {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS},
    {MO(_FL), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX, KC_ENT },
    {KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, KC_RSFT},
    {KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RGUI, KC_RALT, KC_RCTL, MO(_FL)}
  },

    /*
     *  _DV: Dvorak Layer
     * ,-----------------------------------------------------------.
     * |ESC | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  [|  ]| Backsp|
     * |-----------------------------------------------------------|
     * |Tab  |  '|  ,|  .|  P|  Y|  F|  G|  C|  R|  L|  /|  =|    \|
     * |-----------------------------------------------------------|
     * |Fn     |  A|  O|  E|  U|  I|  D|  H|  T|  N|  S|  -| Return|
     * |-----------------------------------------------------------|
     * |Shift   |  ;|  Q|  J|  K|  X|  B|  M|  W|  V|  Z|     Shift|
     * |-----------------------------------------------------------|
     * |Ctrl|Alt |Gui |      Space             |Gui |Alt |Ctrl|  Fn|
     * `-----------------------------------------------------------'
     */
[_DV] = { /* Layer 1: Dvorak */
    {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_BSPC},
    {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,  KC_BSLS},
    {MO(_FL), KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, XXXXXXX, KC_ENT },
    {KC_LSFT, XXXXXXX, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    XXXXXXX, KC_RSFT},
    {KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RGUI, KC_RALT, KC_RCTL, MO(_FL)}
  },

    /*
     *  _CM: Colemak Layer
     * ,-----------------------------------------------------------.
     * |ESC | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| Backsp|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  F|  P|  G|  J|  L|  U|  Y|  ;|  [|  ]|    \|
     * |-----------------------------------------------------------|
     * |Fn     |  A|  R|  S|  T|  D|  H|  N|  E|  I|  O|  '| Return|
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  K|  M|  ,|  .|  /|     Shift|
     * |-----------------------------------------------------------|
     * |Ctrl|Alt |Gui |      Space             |Gui |Alt |Ctrl|  Fn|
     * `-----------------------------------------------------------'
     */
[_CM] = { /* Layer 2: Colemak */
    {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC},
    {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS},
    {MO(_FL), KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, XXXXXXX, KC_ENT },
    {KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, KC_RSFT},
    {KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RGUI, KC_RALT, KC_RCTL, MO(_FL)}
  },

    /*
     *  _FL: Function Layer
     * ,-----------------------------------------------------------.
     * |    |F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|    Del|
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |PgU| Up|PgD|PSc|SLk|Pau|     |
     * |-----------------------------------------------------------|
     * |       |   |MPr|MPl|MNx|   |Hom| Lt| Dn| Rt|   |   |       |
     * |-----------------------------------------------------------|
     * |CAPS    |   |Mut|VlD|VlU|   |End|   |   |   |   |          |
     * |-----------------------------------------------------------|
     * |_QW |_DV |_CM |                        |    |    |    |    |
     * `-----------------------------------------------------------'
     */
[_FL] = { /* Layer 3: Functions */
    {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL },
    {_______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_UP,   KC_PGDN, KC_PSCR, KC_SLCK, KC_PAUS, _______},
    {_______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, XXXXXXX, _______},
    {KC_CAPS, XXXXXXX, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_END,  _______, _______, _______, _______, XXXXXXX, _______},
    {QWERTY,  DVORAK,  COLEMAK, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______}
  },


};

const uint16_t PROGMEM fn_actions[] = {

};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case _DV:
          if (record->event.pressed) {
            persistant_default_layer_set(1UL<<_DV);
          }
          break;
        case _QW:
          if (record->event.pressed) {
            persistant_default_layer_set(1UL<<_QW);
          }
          break;
        case _CM:
          if (record->event.pressed) {
            persistant_default_layer_set(1UL<<_CM);
          }
          break;
      }
    return MACRO_NONE;
};
