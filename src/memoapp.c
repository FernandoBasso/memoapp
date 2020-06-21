#include <gtk/gtk.h>
#include "memoapp.h"
#include "memoapp-window.h"
#include "memoapp-projects.h"

struct _MemoApp
{
  GtkApplication parent;
};

G_DEFINE_TYPE (MemoApp, memoapp, GTK_TYPE_APPLICATION)

static void
memoapp_init (MemoApp *app)
{
  fprintf(stdout, "%s\n", "MemoApp Started");
}

/**
 * Callback function for the "quit" action.
 */
static void
quit_callback (GSimpleAction *simple,
               GVariant      *parameter,
               gpointer       user_data)
{
  GApplication *app = user_data;

  g_print ("You activated \"Quit\"\n");
  g_application_quit (G_APPLICATION (app));
}


static GActionEntry app_entries[] =
{
  { "quit", quit_callback, NULL, NULL, NULL, }
};


static void
memoapp_startup (GApplication *app)
{
  GtkBuilder *builder;
  GMenuModel *menubar;

  const gchar *quit_accels[2] = { "<Ctrl>Q", NULL };

  G_APPLICATION_CLASS (memoapp_parent_class)->startup (app);

  g_action_map_add_action_entries (G_ACTION_MAP (app),
                                   app_entries,
                                   G_N_ELEMENTS (app_entries),
                                   app);

  gtk_application_set_accels_for_action (GTK_APPLICATION (app),
                                         "app.quit",
                                         quit_accels);

  builder = gtk_builder_new_from_resource ("/org/gtk/memoapp/ui/memoapp-menubar.ui");
  menubar = G_MENU_MODEL (gtk_builder_get_object (builder, "menubar"));

  gtk_application_set_menubar (GTK_APPLICATION (app), G_MENU_MODEL (menubar));
  g_object_unref (builder);
}

static void
memoapp_activate (GApplication *app)
{
  short projects_status;

  MemoAppWindow *win;
  MemoAppProjects *projects;

  win = memoapp_window_new (MEMO_APP (app));

  projects = memoapp_projects_new (&projects_status);

  fprintf(stdout, "%s\n", "IT FUCKING WORKS!");

  g_print ("== %hd\n", projects_status);

  if (projects_status == 1) {
    gtk_window_present (GTK_WINDOW (win));
  }
  else {
    g_print("%s\n", "error selecting project");
    g_application_quit (G_APPLICATION (app));
  }
}


static void
memoapp_class_init (MemoAppClass *class)
{
  G_APPLICATION_CLASS (class)->startup = memoapp_startup;
  G_APPLICATION_CLASS (class)->activate = memoapp_activate;
}


MemoApp *
memoapp_new (void)
{
  return g_object_new (MEMOAPP_TYPE,
                       "application-id", "org.gtk.memoapp",
                       "flags", G_APPLICATION_HANDLES_OPEN,
                       NULL);
}

