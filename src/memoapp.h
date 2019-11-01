#ifndef __MEMOAPP_H
#define __MEMOAPP_H

#include <gtk/gtk.h>


#define MEMOAPP_TYPE (memoapp_get_type ())
G_DECLARE_FINAL_TYPE (MemoApp, memoapp, MEMO, APP, GtkApplication)


MemoApp     *memoapp_new         (void);


#endif /* __MEMOAPP_H */
