#include QMK_KEYBOARD_H
#include "keymap_user.h"

// windows task Manager

user_config_t user_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_k87_ansi(
        KC_ESC,                 KC_F1,      KC_F2,   KC_F3,      KC_F4,   KC_F5,   KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_PSCR,    KC_SCRL,    KC_PAUSE,
        KC_GRV,     KC_1,       KC_2,       KC_3,    KC_4,       KC_5,    KC_6,    KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,    KC_INS,     KC_HOME,    KC_PGUP,
        KC_TAB,     KC_Q,       KC_W,       KC_E,    KC_R,       KC_T,    KC_Y,    KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,    KC_DEL,     KC_END,     KC_PGDN,
        KC_CAPS,    KC_A,       KC_S,       KC_D,    KC_F,       KC_G,    KC_H,    KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,                KC_ENT,
        KC_LSFT,                KC_Z,       KC_X,    KC_C,       KC_V,    KC_B,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,                KC_RSFT,                KC_UP,
        KC_LCTL,    KC_LGUI,    KC_LALT,                                  KC_SPC,                                      KC_RALT,    TD(TD_FN),  KC_APP,     KC_RCTL,    KC_LEFT,    KC_DOWN,    KC_RIGHT
    ),
    [_MAC] = LAYOUT_k87_ansi(
        _______,                _______,   _______,  _______,    _______,  _______,  _______,   _______,   _______,    _______,      _______,    _______,    _______,     KC_F13,     KC_F14,    KC_F15,
        _______,    _______,    _______,   _______,  _______,    _______,  _______,  _______,   _______,   _______,    _______,      _______,    _______,    _______,    _______,    _______,   _______,
        _______,    _______,    _______,   _______,  _______,    _______,  _______,  _______,   _______,   _______,    _______,      _______,    _______,    _______,    _______,    _______,   _______,
         T_MLNG,    _______,    _______,   _______,  _______,    _______,  _______,  _______,   _______,   _______,    _______,      _______,                _______,
        _______,                _______,   _______,  _______,    _______,  _______,  _______,   _______,  _______,     _______,      _______,                _______,                _______,
        _______,    KC_LOPT,    KC_LCMD,                                   _______,                                    KC_RCMD,      _______,    KC_ROPT,    KC_RCTL,    _______,    _______,    _______
    ),
    [_NUM] = LAYOUT_k87_ansi(
	    _______,                _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
	    _______,    KC_ACL0,    KC_ACL1,    KC_ACL2, _______,    _______, _______, _______,    _______,    KC_PDOT,    KC_PAST,    KC_PMNS,    KC_PPLS,    KC_BSPC,    _______,    _______,    _______,
	    KC_BTN3,    KC_BTN1,    KC_MS_U,    KC_BTN2, _______,    _______, _______, _______,    _______,      KC_P7,      KC_P8,      KC_P9,     KC_NUM,    KC_PSLS,    _______,    _______,    _______,
	    _______,    KC_MS_L,    KC_MS_D,    KC_MS_R, _______,    _______, _______, _______,    _______,      KC_P4,      KC_P5,      KC_P6,                KC_PENT,
	    _______,                _______,    _______, _______,    _______, _______, _______,    _______,      KC_P1,      KC_P2,      KC_P3,                _______,                _______,
	    _______,    _______,    _______,                                    KC_P0,                                     _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
    [_FN] = LAYOUT_k87_ansi(
	    TD(TD_RST),             KC_BRMD,      KC_BRMU, _______,    _______, _______, _______,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MUTE,    KC_VOLD,    KC_VOLU,    NK_ON,      NK_OFF,     RGB_TOG,
		_______,    _______,    _______,      _______, _______,    _______, _______, _______,    _______,    _______,    _______,    RGB_SPD,    RGB_SPI,    RGB_VAI,    RGB_M_P,    RGB_M_B,    RGB_M_R,
		_______,    _______,    _______,      _______, _______,       T_TM, _______, _______,    _______,    _______,    _______,    RGB_SAI,    RGB_SAD,    RGB_VAD,    RGB_M_SW,   RGB_MOD,    RGB_RMOD,
		KC_CAPS,    _______,    _______,      _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,                RGB_HUI,
		_______,                _______,      _______, _______,    _______, _______, _______,    _______,    _______,    _______,      T_NUM,                RGB_HUD,                KC_WH_U,
		_______,    _______,    _______,                                    _______,                                     KC_LNG1,    _______,     KC_APP,    KC_LNG2,    KC_WH_L,    KC_WH_D,    KC_WH_R
    ),
};

void switchWinMacLayer(void) {
    if(user_config.mac_layer_enabled) {
        layer_on(_MAC);
    } else {
        layer_off(_MAC);
    }
}

void keyboard_post_init_user(void) {
  user_config.raw = eeconfig_read_user();
  user_config.num_layer_enabled = false;
  switchWinMacLayer();
}

void eeconfig_init_user(void) {
  user_config.raw = 0;
  user_config.mac_layer_enabled = false;
  user_config.num_layer_enabled = false;
  eeconfig_update_user(user_config.raw);
  switchWinMacLayer();
}

void dance_bootloader_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        eeconfig_init();
        eeconfig_init_user();
    } else {
        reset_keyboard();
    }
}

void dance_fn_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        layer_on(_FN);
    }
}


void dance_fn_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        layer_off(_FN);
    } else {
        user_config.mac_layer_enabled = !user_config.mac_layer_enabled;
        eeconfig_update_user(user_config.raw);
        switchWinMacLayer();
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_RST] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, NULL, dance_bootloader_reset),
    [TD_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_fn_finished, dance_fn_reset),
};

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {
        case T_NUM:
        {
        if (record->event.pressed) {
            user_config.num_layer_enabled = !user_config.num_layer_enabled;
            eeconfig_update_user(user_config.raw);
            if(user_config.num_layer_enabled) {
                layer_on(_NUM);
            } else {
                layer_off(_NUM);
            }
            return false;
        }
        }
        case T_TM:
        {
        if (record->event.pressed) {
            if(user_config.mac_layer_enabled) {
                register_code(KC_LOPT);
                register_code(KC_LCMD);
                register_code(KC_ESC);
            } else {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_ESC);
            }
        } else {
          if(user_config.mac_layer_enabled) {
                unregister_code(KC_LOPT);
                unregister_code(KC_LCMD);
                unregister_code(KC_ESC);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
                unregister_code(KC_ESC);
            }
        }
            return false;
        }
        case T_MLNG:
              if (record->event.pressed) {
                register_code(KC_LOPT);
                register_code(KC_SPC);
        } else {
                unregister_code(KC_LOPT);
                unregister_code(KC_SPC);
        }
    }
    return true;
};
