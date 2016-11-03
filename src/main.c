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

#include <stdio.h>
#include <stdlib.h>

#include <gtk/gtk.h>

#include "win-query.h"

int main(int argc, char **argv)
{
        int ret = EXIT_SUCCESS;

        gtk_init(&argc, &argv);

        if (argc < 2) {
                fprintf(stderr, "Provide a window id\n");
                return EXIT_FAILURE;
        }
        const char *xwind = argv[1];
        gulong id = g_ascii_strtoull(xwind, NULL, 10);

        gchar *tmp = query_window_menu_object_path(id);
        if (tmp) {
                fprintf(stderr, "Got ID: %s\n", tmp);
                goto finish;
        }
        tmp = query_window_menu_object_path_legacy(id);
        if (tmp) {
                fprintf(stderr, "Got legacy ID: %s\n", tmp);
                goto finish;
        }

        ret = EXIT_FAILURE;
        fprintf(stderr, "No ID found for: %lu\n", id);
finish:

        if (tmp) {
                free(tmp);
        }
        return ret;
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
