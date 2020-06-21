#include <glib/gi18n.h>

#include "memoapp.h"
#include "memoapp-window.h"

int
main (int argc, char *argv[])
{
	/* Set up gettext translations */
	// bindtextdomain (GETTEXT_PACKAGE, LOCALEDIR);
	// bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
	// textdomain (GETTEXT_PACKAGE);

  return g_application_run (G_APPLICATION (memoapp_new ()), argc, argv);
}
