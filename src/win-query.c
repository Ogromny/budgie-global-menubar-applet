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

/**
 * The bus name to connect to
 */
#define UNIQUE_BUS_NAME "_GTK_UNIQUE_BUS_NAME"

static GdkAtom _menu_atom;
static GdkAtom _menu_atom_legacy;
static GdkAtom _utf8_atom;
static GdkAtom _gtk_bus_atom;
static gboolean had_init = FALSE;

/**
 * Initialise the xatoms for the first time
 */
static inline void init_atoms(void)
{
        if (had_init) {
                return;
        }
        _menu_atom = gdk_atom_intern(MENUBAR_OBJECT_PATH, FALSE);
        _menu_atom_legacy = gdk_atom_intern(LEGACY_MENUBAR_OBJECT_PATH, FALSE);
        _gtk_bus_atom = gdk_atom_intern(UNIQUE_BUS_NAME, FALSE);
        _utf8_atom = gdk_atom_intern("UTF8_STRING", FALSE);
        had_init = TRUE;
}

/**
 * Do the real work and query the window using the given atom.
 * Essentially we only care about a UTF8_STRING window property of one of
 * the given paths.
 */
static gchar *query_xwindow_internal(gulong xid, GdkAtom *atom)
{
        init_atoms();
        guchar *data = NULL;
        GdkDisplay *display = NULL;
        GdkWindow *foreign_window = NULL;
        GdkAtom actual_type;
        gint a_af = 0, a_al = 0;

        display = gdk_display_get_default();
        foreign_window = gdk_x11_window_foreign_new_for_display(display, xid);
        if (!foreign_window) {
                fprintf(stderr, "Cannot find window on display %lu\n", xid);
                return NULL;
        }

        gdk_property_get(foreign_window,
                         *atom,
                         _utf8_atom,
                         0,
                         G_MAXLONG,
                         0,
                         &actual_type,
                         &a_af,
                         &a_al,
                         &data);
        /* May well be NULL */
        return (gchar *)data;
}

gchar *query_window_menu_object_path(gulong xid)
{
        return query_xwindow_internal(xid, &_menu_atom);
}

gchar *query_window_menu_object_path_legacy(gulong xid)
{
        return query_xwindow_internal(xid, &_menu_atom_legacy);
}

gchar *query_window_gtk_bus_name(gulong xid)
{
        return query_xwindow_internal(xid, &_gtk_bus_atom);
}

/**
 * Don't actually do anything atm...
 */
WindowMenu *query_window_menu(gulong xid)
{
        WindowMenu *ret = NULL;

        ret = g_new0(WindowMenu, 1);
        ret->xid = xid;

        /* Attempt to gain the bus path first */
        ret->bus_path = query_window_menu_object_path(xid);
        if (!ret->bus_path) {
                ret->bus_path = query_window_menu_object_path_legacy(xid);
        }
        if (!ret->bus_path) {
                goto failed_query;
        }

        /* Get the bus id */
        ret->bus_id = query_window_gtk_bus_name(xid);
        if (!ret->bus_id) {
                goto failed_query;
        }

        /* TODO: Actually create the bus connection + menu model */
        return ret;

failed_query:
        g_clear_pointer(&ret, free_window_menu);
        return NULL;
}

void free_window_menu(WindowMenu *menu)
{
        if (!menu) {
                return;
        }
        g_clear_pointer(&menu->bus_path, g_free);
        g_clear_pointer(&menu->bus_id, g_free);
        g_clear_object(&menu->bus_model);
        g_free(menu);
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
