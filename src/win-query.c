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

#include "win-query.h"

#include <gdk/gdkx.h>

/**
 * Current unity-gtk-greeter export path
 */
#define MENUBAR_OBJECT_PATH "_GTK_MENUBAR_OBJECT_PATH"

/**
 * Old pre-upstreaming export path
 */
#define LEGACY_MENUBAR_OBJECT_PATH "_UNITY_OBJECT_PATH"

static GdkAtom _menu_atom;
static GdkAtom _menu_atom_legacy;
static gboolean had_init = FALSE;

/**
 * Initialise the xatoms for the first time
 */
static void init_atoms(void)
{
        if (had_init) {
                return;
        }
        _menu_atom = gdk_atom_intern(MENUBAR_OBJECT_PATH, FALSE);
        _menu_atom_legacy = gdk_atom_intern(LEGACY_MENUBAR_OBJECT_PATH, FALSE);
        had_init = TRUE;
}

/**
 * Do the real work
 */
static gchar *query_xwindow_internal(gulong xid, GdkAtom *atom)
{
        init_atoms();
        return NULL;
}

gchar *query_window_menu_object_path(gulong xid)
{
        return query_xwindow_internal(xid, &_menu_atom);
}

gchar *query_window_menu_object_path_legacy(gulong xid)
{
        return query_xwindow_internal(xid, &_menu_atom_legacy);
}

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
