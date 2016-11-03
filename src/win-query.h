/*
 * This file is part of budgie-global-menubar-applet
 *
 * Copyright © 2016 Ikey Doherty <ikey@solus-project.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#pragma once

#include <gio/gio.h>
#include <glib.h>

/**
 * Used to track dbus menus
 */
typedef struct WindowMenu {
        gulong xid;
        gchar *bus_path;
        gchar *bus_id;
        GMenuModel *bus_model;
        GDBusConnection *bus;
} WindowMenu;

/**
 * Return the dbus menu path for a given window
 */
gchar *query_window_menu_object_path(gulong xid);

/**
 * Return the legacy dbus menu path for a given window.
 */
gchar *query_window_menu_object_path_legacy(gulong xid);

/**
 * Create a new WindowMenu from the given xid.
 * This may fail and return NULL if the window does not export
 * a menu.
 */
WindowMenu *query_window_menu(gulong xid);

/**
 * Free an existing window menu
 */
void free_window_menu(WindowMenu *menu);

/**
 * Return a GMenuModel for the given bus and path
GMenuModel *query_window_menu(gulong xid);

/*
 * Editor modelines  -  https://www.wireshark.org/tools/modelines.html
 *
 * Local variables:
 * c-basic-offset: 8
 * tab-width: 8
 * indent-tabs-mode: nil
 * End:
 *
 * vi: set shiftwidth=8 tabstop=8 expandtab:
 * :indentSize=8:tabSize=8:noTabs=true:
 */
