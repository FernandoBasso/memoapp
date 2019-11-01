#include <gtk/gtk.h>

#include "memoapp.h"
#include "memoapp-window.h"

struct _MemoAppWindow
{
  GtkApplicationWindow parent;
};

G_DEFINE_TYPE (MemoAppWindow, memoapp_window, GTK_TYPE_APPLICATION_WINDOW)

static void
memoapp_window_init (MemoAppWindow *win)
{
  gtk_widget_init_template (GTK_WIDGET (win));
}

static void
memoapp_window_class_init (MemoAppWindowClass *class)
{
  gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (class),
                                               "/org/gtk/memoapp/ui/memoapp-window.ui");
}

MemoAppWindow *
memoapp_window_new (MemoApp *app)
{
  return g_object_new (MEMOAPP_WINDOW_TYPE, "application", app, NULL);
}

// void
// memoapp_window_open (MemoAppWindow *win,
//                      GFile         *file)
// {
//   fprintf(stdout, "%s\n", "memoapp_window_open()");
// }
