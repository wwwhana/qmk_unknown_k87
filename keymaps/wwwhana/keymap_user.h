

typedef union {
  uint32_t raw;
  struct {
    bool mac_layer_enabled :1;
    bool num_layer_enabled :1;
  };
} user_config_t;

enum my_keycodes {
  // toggle WIN/MAC (DEFAULT WIN)
  T_NUM = SAFE_RANGE,
  T_TM,
  T_MLNG
};

enum {
    TD_RST,
    TD_FN
};

enum layer_names {
    _BASE,
    _MAC,
    _NUM,
    _FN,
};

void switchWinMacLayer(void);
