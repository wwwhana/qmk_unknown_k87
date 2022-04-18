#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _MAC,
    _NUM,
    _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*  Row:        0           1           2           3        4           5        6        7           8           9           10          11          12          13          14          15          16          */
    [_BASE]  = { {  KC_ESC,     KC_F1,      KC_F2,      KC_F3,   KC_F4,      KC_F5,   KC_F6,   KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_NO,      KC_PSCR,    KC_SLCK,    KC_PAUSE },
                {   KC_GRV,     KC_1,       KC_2,       KC_3,    KC_4,       KC_5,    KC_6,    KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,    KC_INS,     KC_HOME,    KC_PGUP  },
                {   KC_TAB,     KC_Q,       KC_W,       KC_E,    KC_R,       KC_T,    KC_Y,    KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,    KC_DEL,     KC_END,     KC_PGDN  },
                {   KC_CAPS,    KC_A,       KC_S,       KC_D,    KC_F,       KC_G,    KC_H,    KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_NO,      KC_ENT,     KC_NO,      KC_NO,      KC_NO    },
                {   KC_LSFT,    KC_NO,      KC_Z,       KC_X,    KC_C,       KC_V,    KC_B,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_NO,      KC_RSFT,    KC_NO,      KC_UP,      KC_NO    },
                {   KC_LCTL,    KC_LGUI,    KC_LALT,    KC_NO,   KC_NO,      KC_NO,   KC_SPC,  KC_NO,      KC_NO,      KC_NO,      KC_RALT,    MO(_FN),    KC_APP,     KC_RCTL,    KC_LEFT,    KC_DOWN,    KC_RIGHT }
              },
    [_MAC] = { {    KC_ESC,     KC_F1,      KC_F2,      KC_F3,   KC_F4,      KC_F5,   KC_F6,   KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_NO,      KC_PSCR,    KC_SLCK,    KC_PAUSE },
                {   KC_GRV,     KC_1,       KC_2,       KC_3,    KC_4,       KC_5,    KC_6,    KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,    KC_INS,     KC_HOME,    KC_PGUP  },
                {   KC_TAB,     KC_Q,       KC_W,       KC_E,    KC_R,       KC_T,    KC_Y,    KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,    KC_DEL,     KC_END,     KC_PGDN  },
                {   KC_CAPS,    KC_A,       KC_S,       KC_D,    KC_F,       KC_G,    KC_H,    KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_NO,      KC_ENT,     KC_NO,      KC_NO,      KC_NO    },
                {   KC_LSFT,    KC_NO,      KC_Z,       KC_X,    KC_C,       KC_V,    KC_B,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_NO,      KC_RSFT,    KC_NO,      KC_UP,      KC_NO    },
                {   KC_LCTL,    KC_LALT,    KC_LGUI,    KC_NO,   KC_NO,      KC_NO,   KC_SPC,  KC_NO,      KC_NO,      KC_NO,      KC_RGUI,    MO(_FN),    KC_RALT,    KC_RCTL,    KC_LEFT,    KC_DOWN,    KC_RIGHT }
              },
    [_NUM]   = { {  _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______  },
                {   _______,    KC_ACL0,    KC_ACL1,    KC_ACL2, _______,    _______, _______, _______,    _______,     _______,    KC_PAST,    KC_PMNS,    KC_PPLS,    KC_BSPC,    _______,    _______,    _______  },
                {   _______,    KC_BTN1,    KC_MS_U,    KC_BTN2, _______,    _______, _______, _______,    _______,      KC_P7,      KC_P8,      KC_P9,    KC_NUM,    KC_PSLS,    _______,     _______,   _______  },
                {   _______,    KC_MS_L,    KC_MS_D,    KC_MS_R, _______,    _______, _______, _______,    _______,      KC_P4,      KC_P5,      KC_P6,    _______,     KC_ENT,    _______,    _______,    _______  },
                {   _______,    _______,    KC_WH_L,    KC_WH_U, KC_WH_R,    _______, _______, _______,    _______,      KC_P1,      KC_P2,      KC_P3,    _______,    _______,    _______,    _______,    _______  },
                {   _______,    _______,    KC_WH_D,    _______, _______,    _______,   KC_P0, _______,    _______,    _______,    KC_PDOT,    MO(_FN),    _______,    _______,    _______,    _______,    _______  }
             },
    [_FN]    = { {    RESET,      KC_MSEL,    KC_VOLD,    KC_VOLU, KC_MUTE,    KC_MSTP, KC_MPRV, KC_MPLY,    KC_MNXT,    KC_MAIL,    KC_WHOM,    KC_CALC,    RGB_TOG,    _______,    NK_ON,      NK_OFF,    KC_SLEP  },
                {   _______,    _______,    _______,      _______, _______,    _______, _______, _______,    _______,    _______,    _______,    RGB_SPD,    RGB_SPI,    _______,    RGB_M_P,    RGB_M_B,    RGB_M_R  },
                {   _______,    _______,    TO(_BASE),    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    RGB_M_SW,    RGB_MOD,   RGB_RMOD  },
                {   _______,    _______,    _______,      _______, _______,    _______, _______, _______,    _______,    _______,    _______,    TO(_NUM),    _______,    _______,   _______,    _______,    _______  },
                {   _______,    _______,    _______,      _______, _______,    _______, _______, _______,    TO(_MAC),   _______,    _______,    _______,    _______,    _______,    _______,    RGB_VAI,    _______  },
                {   _______,    _______,    _______,      _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    RGB_HUD,    RGB_VAD,    RGB_HUI  }
             },
};

