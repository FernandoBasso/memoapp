#ifndef MEMOAPP_SETUP_H
#define MEMOAPP_SETUP_H

#include <glib.h>

#define MEMOAPP_CONFIG_DIR_NAME "memoapp"
#define MEMOAPP_PROJECTS_FILE "memoapp-projects.conf"

gchar * memoapp_config_dir_get (void);

gboolean memoapp_config_dir_exists (void);

int memoapp_config_dir_setup (void);

gboolean memoapp_projects_file_exists (gchar *filename);

gchar * memoapp_projects_file_get ();

#endif /* MEMOAPP_SETUP_H */

