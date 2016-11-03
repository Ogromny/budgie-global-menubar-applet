Preloading module
-----------------

    GTK_MODULES=unity-gtk-module UBUNTU_MENUPROXY=on $someapp

xsettings portion
------------------

**Enable module**

    Gtk/ShellShowsMenubar <1>

**Disable module**

    Gtk/ShellShowsMenubar <0>


Plan
-----

Provide an env.d style file to automatically enable the `GTK_MODULES`
portion.

When the applet is loaded for the first time through the factory mechanism,
force the xsetting override for `Gtk/ShellShowsMenubar`. Upon unloading, we
must then unset it again.
