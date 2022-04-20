#define KC_TM LCTL(LSFT(KC_ESC))

typedef union {
  uint32_t raw;
  struct {
    bool mac_layer_enabled :1;
    bool num_layer_enabled :1;
  };
} user_config_t;

enum my_keycodes {
  // toggle WIN/MAC (DEFAULT WIN)
  T_WM = SAFE_RANGE,
  T_NUM,
};

enum {
    TD_RST,
    TD_COL,
    TD_QUOT
};

enum layer_names {
    _BASE,
    _MAC,
    _NUM,
    _FN,
};

void switchWinMacLayer(void);