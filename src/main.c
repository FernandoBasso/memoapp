#include <gtk/gtk.h>

#include "memoapp.h"

int
main (int argc, char *argv[])
{
  return g_application_run (G_APPLICATION (memoapp_new ()), argc, argv);
}
