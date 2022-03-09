#include <glib.h>
#include <stdio.h>
#include <stdbool.h>

static gint size = 1;  /* 1MB */

static GOptionEntry entries[] = {
    { "size", 's', 0, G_OPTION_ARG_INT, &size, "Size of file in MB", "SIZE"},
    { NULL }
};

static void show_help(GOptionContext *opt_ctx)
{
    char *help_str = g_option_context_get_help(opt_ctx, false, NULL);
    fwrite(help_str, 1, strlen(help_str), stdout);
    g_free(help_str);
}

int main(int argc, char* argv[])
{
    GError *error = NULL;
    GOptionContext *opt_ctx = g_option_context_new("FILE");
    g_option_context_add_main_entries(opt_ctx, entries, NULL);

    if (!g_option_context_parse(opt_ctx, &argc, &argv, &error)) {
        g_print("option parsing failed: %s\n", error->message);
        exit(1);
    }

    if  (argc < 1 ) {
        show_help(opt_ctx);
        exit(1);
    }

    return 0;
}
