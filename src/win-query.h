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

#include <glib.h>

/**
 * Return the dbus menu path for a given window
 */
gchar *query_window_menu_object_path(gulong xid);

/**
 * Return the legacy dbus menu path for a given window.
 */
gchar *query_window_menu_object_path_legacy(gulong xid);

/**
 * Return the unique bus name for the given app
 */
gchar *query_window_gtk_bus_name(gulong xid);

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
