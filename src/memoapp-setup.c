#include <gtk/gtk.h>
#include <glib.h>
#include <glib/gstdio.h>
#include <gio/gio.h>

#include "memoapp-setup.h"


/**
 * Retrieves the name of memoapp's config dir, something like
 *
 *    ~/.config/memoapp
 *
 * Returns: gchar *
 */
gchar *
memoapp_config_dir_get ()
{
  const gchar *base_config_dir;

  base_config_dir = g_get_user_config_dir ();

  return g_strconcat (base_config_dir, "/", MEMOAPP_CONFIG_DIR_NAME, NULL);
}


/**
 * Checks whether memoapp's config dir exists.
 *
 * Returns: gboolean
 */
gboolean
memoapp_config_dir_exists ()
{
  GStatBuf stat_buf;
  const gchar *config_dir;

  config_dir = memoapp_config_dir_get ();

  return g_stat (config_dir, &stat_buf) == 0;
}


/**
 * Sets up memoapp's config dir.
 *
 * Creates the directory if necessary, and populates it with the required
 * configuration files.
 *
 * Returns: int
 */
int
memoapp_config_dir_setup ()
{
  gchar *config_dir;
  GError *err = NULL;

  config_dir = memoapp_config_dir_get ();

  if (! memoapp_config_dir_exists ())
  {
    g_print ("creating directory\n");
    g_file_make_directory (g_file_new_for_path (config_dir), NULL, &err);

    if (err != NULL) {
      g_print ("Error creating “%s” directory\n", config_dir);
      g_print ("%d\n", err->code);
      fprintf (stderr, "%s\n", err->message);
      return 1;
    }

    g_print ("Config directory “%s” created successfully!\n", config_dir);
    return 0;
  }
  else
  {
    g_print ("Config directory “%s” already exists. Great!\n", config_dir);
    return 0;
  }
}


gshort
project_location_dialog ()
{
  GtkWidget *dialog;
  GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER;
  gint res;

  dialog = gtk_file_chooser_dialog_new ("Select the Project Directory",
                                        NULL,
                                        action,
                                        "Cancel",
                                        GTK_RESPONSE_CANCEL,
                                        "Open",
                                        GTK_RESPONSE_ACCEPT,
                                        NULL);

  res = gtk_dialog_run (GTK_DIALOG (dialog));
  if (res == GTK_RESPONSE_ACCEPT)
    {
      char *dirname;
      GtkFileChooser *chooser = GTK_FILE_CHOOSER (dialog);
      dirname = gtk_file_chooser_get_filename (chooser);
      g_print ("dirname: %s\n", dirname);
      g_free (dirname);
      gtk_window_close (GTK_WINDOW (dialog));
      }


  return 0;

}
