#!/bin/bash

./enable.sh

export GTK_MODULES=unity-gtk-module
export UBUNTU_MENUPROXY=on

if [[ ! -z "$1" ]]; then
    $*
else
    atril
fi

./disable.sh
