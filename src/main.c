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
        WindowMenu *window_menu = NULL;

        gtk_init(&argc, &argv);

        if (argc < 2) {
                fprintf(stderr, "Provide a window id\n");
                return EXIT_FAILURE;
        }
        const char *xwind = argv[1];
        gulong id = g_ascii_strtoull(xwind, NULL, 10);
        // id = 0x2c00008;

        window_menu = query_window_menu(id);
        if (!window_menu) {
                fprintf(stderr, "No ID found for: %lu\n", id);
                ret = EXIT_FAILURE;
                goto finish;
        }

        fprintf(stdout,
                "Window path: %s\nWindow bus: %s\n",
                window_menu->bus_path,
                window_menu->bus_id);
finish:
        g_clear_pointer(&window_menu, free_window_menu);
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
