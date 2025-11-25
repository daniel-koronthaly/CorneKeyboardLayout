OLED_ENABLE = yes

# RGBLIGHT_ENABLE     = yes
RGB_MATRIX_ENABLE  = no
SPLIT_KEYBOARD = yes
OLED_ENABLE = yes
LTO_ENABLE = yes
RGBLIGHT_ENABLE = no
WPM_ENABLE = yes
MOUSEKEY_ENABLE = yes

OLED_DRIVER_ENABLE = yes
SPLIT_OLED_ENABLE = yes

# Enabling link-time optimization saves about 3 kilobytes.
# https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/
EXTRAFLAGS += -flto
