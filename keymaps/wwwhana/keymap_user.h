#define TK_RST TD(TD_RST)
#define TK_FN TD(TD_FN)

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
    TD_COL,
    TD_QUOT,
    TD_LBR,
    TD_RBR,
    TD_LT,
    TD_DT,
    TD_TIL,
    TD_NUM1,
    TD_NUM2,
    TD_NUM3,
    TD_NUM4,
    TD_NUM5,
    TD_NUM6,
    TD_NUM7,
    TD_NUM8,
    TD_NUM9,
    TD_NUM0,
    TD_MINUS,
    TD_PLUS,
    TD_FN
  };

enum layer_names {
    _BASE,
    _MAC,
    _NUM,
    _FN,
};

void switchWinMacLayer(void);
