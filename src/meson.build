memoapp_sources = [
  'main.c',
  'memoapp.c',
  'memoapp-window.c',
  'memoapp-setup.c',
  'memoapp-projects.c',
]

memoapp_deps = [
  dependency('gio-2.0', version: '>= 2.50'),
  dependency('gtk+-3.0', version: '>= 3.22'),
]

gnome = import('gnome')

memoapp_sources += gnome.compile_resources('memoapp-resources',
  'memoapp.gresource.xml',
  c_name: 'memoapp'
)

#
# Meson warning_level more or less, maps to these gcc flags:
#
#   warning_level=1 ⇒ -Walll
#   warning_level=2 ⇒ -Wextra
#   warning_level=3 ⇒ -pedantic
#
# Several Gtk, Glib, etc projects explicitly _do not_ use flags like
# -pedantic or -Wextra, each for their own reasons. We have some
# reasons to disable some warnings too.
#
# Some useful links:
# ------------------
#
#   https://github.com/mesonbuild/meson/issues/2609
#
#   https://mesonbuild.com/howtox.html
#
#   https://mesonbuild.com/Adding-arguments.html
#
warn_c_flags = [
  #
  # Because there are several functions that require (positional) prameters,
  # and some are not useed inside the function, thus producing warnings. Let's
  # disable them.
  #
  '-Wno-unused-parameter',

  #
  # Especifically for stuff like this:
  #
  #   static GActionEntry app_entries[] =
  #   {
  #     { "quit", quit_callback, NULL, NULL, NULL, }
  #   };
  #
  '-Wno-missing-field-initializers',
]

executable('memoapp', memoapp_sources,
  dependencies: memoapp_deps,
  install: true,
  c_args: warn_c_flags,
)
