#ifndef __MEMOAPP_PROJECTS_H
#define __MEMOAPP_PROJECTS_H

#include <gtk/gtk.h>
#include "memoapp-window.h"

#define MEMOAPP_TYPE_PROJECTS (memoapp_projects_get_type ())
G_DECLARE_FINAL_TYPE (MemoAppProjects, memoapp_projects, MEMOAPP, PROJECTS, GtkWindow)

MemoAppProjects       *memoapp_projects_new       (short *status);

#endif /* __MEMOAPP_PROJECTS_H */

