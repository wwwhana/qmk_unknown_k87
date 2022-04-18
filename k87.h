#pragma once

#include "quantum.h"

#define LAYOUT_k87_ansi( \
    k000,       k002, k003, k004, k005, k006, k007, k008, k009, k010, k011, k012, k013, k014, k015, k016, \
    k100, k101, k102, k103, k104, k105, k106, k107, k108, k109, k110, k111, k112, k113, k114, k115, k116, \
    k200, k201, k202, k203, k204, k205, k206, k207, k208, k209, k210, k211, k212, k213, k214, k215, k216, \
    k300, k301, k302, k303, k304, k305, k306, k307, k308, k309, k310, k311,       k313,                   \
    k400,       k402, k403, k404, k405, k406, k407, k408, k409, k410, k411, k412,             k415,       \
    k500, k501, k502,                   k506,                   k510, k511, k512, k513, k514, k515, k516  \
) \
{ \
    { k000,  k002,  k003,  k004,  k005,  k006, k007,  k008,  k009,  k010,  k011,  k012,  k013,  KC_NO, k014,  k015,  k016  }, \
    { k100,  k101,  k102,  k103,  k104,  k105,  k106, k107,  k108,  k109,  k110,  k111,  k112,  k113,  k114,  k115,  k116  }, \
    { k200,  k201,  k202,  k203,  k204,  k205,  k206, k207,  k208,  k209,  k210,  k211,  k212,  k213,  k214,  k215,  k216  }, \
    { k300,  k301,  k302,  k303,  k304,  k305,  k306, k307,  k308,  k309,  k310,  k311,  KC_NO, k313,  KC_NO, KC_NO, KC_NO }, \
    { k400,  KC_NO, k402,  k403,  k404,  k405,  k406, k407,  k408,  k409,  k410,  k411,  KC_NO, k412,  KC_NO, k415,  KC_NO }, \
    { k500,  k501,  k502,  KC_NO, KC_NO, KC_NO, k506, KC_NO, KC_NO, KC_NO, k510,  k511,  k512,  k513,  k514,  k515,  k516  }  \
}
