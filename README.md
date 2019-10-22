# MemoApp

NOTE: [The official repository for this project is on GitLab](https://gitlab.com/fernandobasso/memoapp).

NOTE: For now, the devel branch is where the cool stuff takes place.


This is MemoApp, an application that attempts to be similar to Zim Wiki, except using Markdown as the underlying language.

Future ideas may involve supporting extra stuff not present in Markdown, perhaps something like Asciidoctor, and even far in the future, include features found in Anki for flashcard-related stuff.

Application has these main areas and features:

- Top Menu Bar
- Top Tool Bar
- Tree View (left)
- Main Editing Window (center)
- Headings and Index of main elements of current editing view (right)
- Very searchable and navigable
- Markdown behind the scenes


## Tasks

The list of tasks that need to be performed.

- [x] Display the three columns.
- [ ] (currently being worked on) Parse the markdown headings and display them like headings in the main editing window.
- [ ] Display the headings outline on the doc info view.


## Git Guidelines

Start commit subject messages with one of these:

- `major`: major, hard or important stuff.
- `minor`: for minor, trivial stuff.
- `poc`: prof of concept attempt.
- `fix`: fix something like spelling.
- `ref`: refactoring.


## Dev Setup

NOTE: Instead of using an IDE with a ready (and sometimes bloated) template, I decided to do things step-by-step, learning along the way and setting things up as needed, keeping things as minimal and simple as possible.

Make sure the Gtk (3) dev stuff is installed. On Arch Linux, the header files are always packaged with the program/lib they relate to. For example, if Gtk is installed, you are ready to develop and compile Gtk applications because that package contains the header files and installs them under `/usr/include/` subdirectories. On a Debian-based distro, one generally needs to install the _-dev_ packages, like `libgtk-3-dev` or something like that.


### Compiling and Running

Basically, we need to translate the UI resources to a `.c` file and then run compile everything:

```shell
$ make gresources
$ make all
$ ./memoapp
```

The `ui-resource.c` file only needs to be regenerated if an UI or XML resource file is modified.

### Vim

It looks like ALE and YCM were both doing linting. Disabled ALE for now and YCM is indeed doing some linting on its own. `.ycm_extra_conf.py` barely configured with Gtk stuff.



