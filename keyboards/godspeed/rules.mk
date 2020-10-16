# MCU name
MCU = atmega32u4

BOOTLOADER = halfkay

# Build Options
#   comment out to disable the options.
#

EXTRAKEY_ENABLE = yes		# Audio control and System control(+450)
NKRO_ENABLE = yes			# USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
COMBO_ENABLE = yes
TAP_DANCE_ENABLE = yes
