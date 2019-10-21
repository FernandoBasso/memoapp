# pylint: disable=all

def Settings( **kwargs ):
  return {
      'flags': [
        '-x',
        'c',
        '-Wall',
        '-Wextra',
        '-Werror',
        '-pedantic',
        '-I/usr/include/gtk-3.0',
        '-I/usr/include/pango-1.0',
        '-I/usr/include/glib-2.0',
        '-I/usr/lib/glib-2.0/include',
        '-I/usr/lib/libffi-3.2.1/include',
        '-I/usr/include/harfbuzz',
        '-I/usr/include/fribidi',
        '-I/usr/include/freetype2',
        '-I/usr/include/libpng16',
        '-I/usr/include/cairo',
        '-I/usr/include/pixman-1',
        '-I/usr/include/gdk-pixbuf-2.0',
        '-I/usr/include/libmount',
        '-I/usr/include/blkid',
        '-I/usr/include/gio-unix-2.0',
        '-I/usr/include/atk-1.0',
        '-I/usr/include/at-spi2-atk/2.0',
        '-I/usr/include/at-spi-2.0',
        '-I/usr/include/dbus-1.0',
        '-I/usr/lib/dbus-1.0/include',
        '-pthread',
        ],
      }

# vim: set shiftwidth=2 expandtab softtabstop=2:

