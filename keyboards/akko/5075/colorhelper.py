# start interactive mode with this file loaded: python3 -i keymaps/custom/colorhelper.py
# load this file into an existing session:      from keymaps.custom.colorhelper import *
import colorsys

# color ranges:
# colorsys uses 0-1 range for both rgb and hsv
# qmk uses 0-255 range for both rgb and hsv
#
# typical color picker ranges are
# rgb: 0-255
# hsv: h:0-360, s:0-100%, v:0-100%

def colorsys_to_qmk(three_value_tuple):
    return (three_value_tuple[0]*255,three_value_tuple[1]*255,three_value_tuple[2]*255)

def qmk_hsv(h,s,v):
    return (h * 255 / 360, s * 255 / 100, v * 255 / 100)

# no function for RBG because standard color picker 0-255 RGB can be used in QMK as is

def hsv_to_qmk_rgb(h,s,v):
    return colorsys_to_qmk(colorsys.hsv_to_rgb(h/360, s/100, v/100))

def rgb_to_qmk_hsv(r,g,b):
    regular_hsv = colorsys.rgb_to_hsv(r/255, g/255, b/255)
    return qmk_hsv(regular_hsv[0], regular_hsv[1], regular_hsv[2])

def qmk_hsv_to_qmk_rgb(h,s,v):
    return colorsys_to_qmk(colorsys.hsv_to_rgb(h/255, s/255, v/255))

def qmk_rgb_to_qmk_hsv(r,g,b):
    return colorsys_to_qmk(colorsys.rgb_to_hsv(r/255, g/255, b/255))
