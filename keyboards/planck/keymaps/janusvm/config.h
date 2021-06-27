#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
        SONG(COLEMAK_SOUND),                          \
        SONG(DVORAK_SOUND)                            \
      }
    #define UNICODE_SONG_MAC  SONG(AUDIO_ON_SOUND)
    #define UNICODE_SONG_LNX  SONG(UNICODE_LINUX)
    #define UNICODE_SONG_BSD  SONG(TERMINAL_SOUND)
    #define UNICODE_SONG_WIN  SONG(UNICODE_WINDOWS)
    #define UNICODE_SONG_WINC SONG(UNICODE_WINDOWS)
#endif

#define TAPPING_TOGGLE 2
#define ONESHOT_TAP_TOGGLE 2
#define ONESHOT_TIMEOUT 1500

// Settings for home row mods
#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
