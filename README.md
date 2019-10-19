# stl-slicer
A tool that exports slices from a stl file to bmp's.

# Usage
Once you've build the source code you can run program from the console or terminal.
stl-slicer <file.stl> <slice-amount f.e 1063> <resolution f.e 200>

For example: ./stl-slicer stlfile.stl 1063 200

This command will slice the stl file 1063 times on the Z axis and output those as multiple bmp's with a resolution of 200px.

# Contribution
The stl-slicer is far from done because the initial version(commit) was written in one day(and in a hurry). That's why the code can be a mess, inefficient and last but not least contain memory leaks.

The following things can be examples of what still can be done:
- Running the bmp export on different threads so that the slicing algorithm speed won't be bottlenecked by the bmp export.
- fill a cirlce with color (for example when we are slicing and we have a hole or circle in the bitmap we should fill it with color).
- Own bmp export code, we now use a library which doesn't exactly fit our needs.
- Fix memory leaks.
- make code more efficient and cleaner.
- other output formats support.
