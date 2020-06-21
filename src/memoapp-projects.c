/* memoapp-projects.c
 *
 * Responsible for displaying the introductory projects setup/chooser window.
 */


#include <gtk/gtk.h>

#include "memoapp-window.h"
#include "memoapp-setup.h"
#include "memoapp-projects.h"


enum
{
  COL_TITLE,
  COL_DESCR,
  LEN_COLS,
};

struct _MemoAppProjects
{
  GtkWindow parent;
  GtkButton *btn_ok;
  GtkButton *btn_cancel;
  GtkButton *btn_add_project;

  /*
   * The button to add a new project folder location and
   * the associated text entries.
   */
  GtkFileChooser *project_folder_chooser;
  GtkEntry *project_name;
  GtkEntry *project_folder;

  gboolean btn_ok_clicked;
  gboolean btn_cancel_clicked;
  // GtkListStore *store_projects;
  GtkWidget *treeview;
  GtkStack *stack_projects_setup;
  GtkWidget *page_projects_list;
  GtkWidget *page_project_create;
};

G_DEFINE_TYPE (MemoAppProjects, memoapp_projects, GTK_TYPE_WINDOW)

void
btn_add_project_cb (GtkButton *btn_add_project, MemoAppProjects *self)
{
  g_print("%s\n", "btn_add_projects_clicked");
  const gchar *name = gtk_stack_get_visible_child_name (self->stack_projects_setup);
  g_print ("%s\n", name);
  gtk_stack_set_visible_child (self->stack_projects_setup,
                               GTK_WIDGET (self->page_project_create));
}

/**
 * Builds a GtkListStore to populate the Project Setup window.
 */
static void
memoapp_projects_setup_store (MemoAppProjects *self)
{
  GtkListStore *store_projects;

  store_projects = gtk_list_store_new (LEN_COLS,
                                       G_TYPE_STRING,
                                       G_TYPE_STRING);
  GtkTreeIter iter;


  typedef struct
  {
    gchar *title;
    gchar *descr;
  }
  Projects;

  static Projects data[] =
  {
    { "Project 1", "Project 1 Description " },
    { "Project 2", "Project 2 Description" },
  };

  gsize i;

  for (i = 0; i < G_N_ELEMENTS (data); ++i)
  {
    // Acquire an iterator.
    gtk_list_store_append (store_projects, &iter);
    gtk_list_store_set (store_projects, &iter,
                        COL_TITLE, data[i].title,
                        COL_DESCR, data[i].descr,
                        -1);

    // self->treeview = gtk_tree_view_new_with_model (GTK_TREE_MODEL (store_projects));

  }

  GtkCellRenderer *renderer;
  GtkTreeViewColumn *col_name, *col_descr;

  renderer = gtk_cell_renderer_text_new ();
  col_name = gtk_tree_view_column_new_with_attributes ("Name",
                                                  renderer,
                                                  "text", COL_TITLE,
                                                  NULL);
  col_descr = gtk_tree_view_column_new_with_attributes ("Description",
                                                  renderer,
                                                  "text", COL_DESCR,
                                                  NULL);

  gtk_tree_view_append_column (GTK_TREE_VIEW (self->treeview), col_name);
  gtk_tree_view_append_column (GTK_TREE_VIEW (self->treeview), col_descr);

  gtk_tree_view_set_model (GTK_TREE_VIEW (self->treeview), GTK_TREE_MODEL (store_projects));
}

static void
btn_ok_cb (GtkButton *btn, MemoAppProjects *self)
{
  g_print ("Button OK Clicked!\n");
  self->btn_ok_clicked = TRUE;
  gtk_window_close (GTK_WINDOW (self));
}

static void
btn_cancel_cb (GtkButton *btn, MemoAppProjects *self)
{
  g_print ("Button Cancel Clicked!\n");
  self->btn_cancel_clicked = TRUE;
  gtk_window_close (GTK_WINDOW (self));
}

static void
on_close (GtkWindow *win)
{
  g_print ("✗ button clicked!\n");
  gtk_main_quit ();
}


/*
 * Callback to handle the user selecting a new project directory/folder location.
 */
static void
on_folder_selected (GtkFileChooser *chooser,
                    gpointer *user_data)
{
  gchar *folder_name;
  folder_name = gtk_file_chooser_get_filename (chooser);

  MemoAppProjects *win;
  win = MEMOAPP_PROJECTS (gtk_widget_get_toplevel (GTK_WIDGET (chooser)));

  gtk_entry_set_text (win->project_name, "Hello World");
  gtk_entry_set_text (win->project_folder, folder_name);

  g_print ("on_folder_selected (): %s\n", folder_name);
}


static void
memoapp_projects_init (MemoAppProjects *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
  g_print ("%s\n", "memoapp projects init");
  g_signal_connect (self->btn_ok, "clicked", G_CALLBACK (btn_ok_cb), self);
  g_signal_connect (self->btn_cancel, "clicked", G_CALLBACK (btn_cancel_cb), self);
  g_signal_connect (self->btn_add_project, "clicked", G_CALLBACK (btn_add_project_cb), self);

  /*
   * The ‘file-set’ signal also handles selecting folders.
   */
  g_signal_connect (self->project_folder_chooser,
                    "file-set",
                    G_CALLBACK (on_folder_selected),
                    NULL);
}


static void
memoapp_projects_class_init (MemoAppProjectsClass *class)
{
  g_print ("%s\n", "memoapp projects class init");

  gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (class),
                                               "/org/gtk/memoapp/ui/memoapp-projects.ui");

  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (class), MemoAppProjects, btn_ok);
  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (class), MemoAppProjects, btn_cancel);
  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (class), MemoAppProjects, btn_add_project);
  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (class), MemoAppProjects, treeview);
  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (class), MemoAppProjects, stack_projects_setup);
  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (class), MemoAppProjects, page_projects_list);
  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (class), MemoAppProjects, page_project_create);

  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (class), MemoAppProjects, project_folder_chooser);
  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (class), MemoAppProjects, project_name);
  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (class), MemoAppProjects, project_folder);
}


MemoAppProjects *
memoapp_projects_new (short *status)
{

  /*
   * Creates ~/.config/memoapp/ if it does not exist yet, i.e. in the
   * first run of the application.
   */
  memoapp_config_dir_setup ();

  MemoAppProjects *self = g_object_new (MEMOAPP_TYPE_PROJECTS, NULL);

  memoapp_projects_setup_store (self);

  gtk_window_present (GTK_WINDOW (self));

  /*
   * Quits the second event loop which takes care of the project setup window.
   */
  g_signal_connect (self, "delete-event", G_CALLBACK (gtk_main_quit), NULL);

  /*
   * A second event loop to handle the project setup window.
   */
  gtk_main ();

  fprintf(stdout, "ok: %d, cancel: %d\n", self->btn_ok_clicked, self->btn_cancel_clicked);
  *status = self->btn_ok_clicked ? 1 : 0;
  return self;
}

