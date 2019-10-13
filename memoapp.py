"""Main module."""


import sys

import gi
gi.require_version('Gtk', '3.0')
from gi.repository import GLib, Gio, Gtk


class Application(Gtk.Application):
    """The Stupendousu Gtk Application Class"""

    def __init__(self, *args, **kwargs):
        super().__init__(*args, application_id="org.opensource.mynotes",
                         flags=Gio.ApplicationFlags.HANDLES_COMMAND_LINE,
                         **kwargs)
        self.window = None
        self.builder = None

        self.add_main_option("test", ord("t"), GLib.OptionFlags.NONE,
                             GLib.OptionArg.NONE, "Command line test", None)

    def do_startup(self):
        Gtk.Application.do_startup(self)


    def do_activate(self):
        if not self.window:
            # self.window = AppWindow(application=self, title="My Notes")
            self.builder = Gtk.Builder()
            self.builder.add_from_file("./memoapp.ui")
            app_window = self.builder.get_object("app_window")
            app_window.set_application(self)
            app_window.show_all()
            self.window = app_window


        self.docs_tree()
        self.doc_edit()
        self.doc_info()
        self.window.present()

    def docs_tree(self):
        """Handles the managment of the left document tree view."""
        tb_docs_tree = self.builder.get_object("tb_docs_tree")
        tb_docs_tree.set_text("- Will be\n- Filled with\n- list of docs")

    def doc_edit(self):
        """Handles the main area where a document is viewed and edited."""
        tb_doc_edit = self.builder.get_object("tb_doc_edit")
        tb_doc_edit.set_text("λ Hello World! 爔 ✔  💩 "
                             "\n♫ ♩ ♬ ♭ ♪ ☺ ♥")

    def doc_info(self):
        """Handles the managment of the document info right view."""
        tb_doc_info = self.builder.get_object("tb_doc_info")
        tb_doc_info.set_text("* Will contain\n* Current Document\n* Information..."
                             "\n** Like Headings\n** and other stuf...")

    def do_command_line(self, command_line):
        """Handles command line arguments."""
        options = command_line.get_options_dict()
        # convert GVariantDict -> GVariant -> dict
        options = options.end().unpack()

        if "test" in options:
            print("Test argument recieved: %s" % options["test"])

        self.activate()
        return 0

    def on_about(self, action, param):
        """The About dialog."""
        about_dialog = Gtk.AboutDialog(transient_for=self.window, modal=True)
        about_dialog.present()

    def on_quit(self, action, param):
        """Quits the application."""
        self.quit()

if __name__ == "__main__":
    MEMO_APP = Application()
    MEMO_APP.run(sys.argv)

