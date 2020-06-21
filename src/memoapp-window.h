#pragma once

#include <gtk/gtk.h>

// G_BEGIN_DECLS

// #define MEMOAPP_TYPE_WINDOW (memoapp_window_get_type())

// G_DECLARE_FINAL_TYPE (MemoAppWindow, memoapp_window, MEMOAPP, WINDOW, GtkApplicationWindow)

// G_END_DECLS


#ifndef __MEMOAPP_WINDOW_H
#define __MEMOAPP_WINDOW_H

#include "memoapp.h"


#define MEMOAPP_TYPE_WINDOW (memoapp_window_get_type ())
G_DECLARE_FINAL_TYPE (MemoAppWindow, memoapp_window, MEMOAPP, WINDOW, GtkApplicationWindow)


MemoAppWindow       *memoapp_window_new       (MemoApp *app);
void                 memoapp_window_open      (MemoAppWindow *win,
                                               GFile         *file);


#endif /* __MEMOAPP_WINDOW_H */
