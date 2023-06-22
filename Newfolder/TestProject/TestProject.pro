TEMPLATE = subdirs

SUBDIRS += \
    myproject \
    src

STYLE_DIR = $$PWD/styles
CONFIG += STYLE_DIR=$$STYLE_DIR
message("STYLE_DIR: $$STYLE_DIR")
myproject.depends = src
