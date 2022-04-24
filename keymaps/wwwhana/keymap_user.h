#define TK_RST TD(TD_RST)
#define TK_COL TD(TD_COL)
#define TK_QUOT TD(TD_QUOT)
#define TK_LBR TD(TD_LBR)
#define TK_RBR TD(TD_RBR)
#define TK_LT TD(TD_LT)
#define TK_DT TD(TD_DT)
#define TK_T TD(TD_TIL)
#define TK_1 TD(TD_NUM1)
#define TK_2 TD(TD_NUM2)
#define TK_3 TD(TD_NUM3)
#define TK_4 TD(TD_NUM4)
#define TK_5 TD(TD_NUM5)
#define TK_6 TD(TD_NUM6)
#define TK_7 TD(TD_NUM7)
#define TK_8 TD(TD_NUM8)
#define TK_9 TD(TD_NUM9)
#define TK_0 TD(TD_NUM0)
#define TK_M TD(TD_MINUS)
#define TK_P TD(TD_PLUS)
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
  T_TM
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