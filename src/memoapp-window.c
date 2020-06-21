#include "memoapp-window.h"

struct _MemoAppWindow
{
  GtkApplicationWindow  parent;
};

G_DEFINE_TYPE (MemoAppWindow, memoapp_window, GTK_TYPE_APPLICATION_WINDOW)

static void
memoapp_window_class_init (MemoAppWindowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/org/gtk/memoapp/ui/memoapp-window.ui");
}

static void
memoapp_window_init (MemoAppWindow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}

MemoAppWindow *
memoapp_window_new (MemoApp *app)
{
  return g_object_new (MEMOAPP_TYPE_WINDOW, "application", app, NULL);
}

