ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif

TAP_DANCE_ENABLE = no
COMBO_ENABLE = yes

MOUSEKEY_ENABLE     = yes
TRI_LAYER_ENABLE    = yes
KEY_OVERRIDE_ENABLE = yes
