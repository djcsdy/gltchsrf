# gltchsrf

## Setup

This project includes a Vagrant virtual machine with all required build tools,
so you can get set up very quickly.

1.  Install [Vagrant][1].
2.  From the project directory:

        vagrant up


## Build

*   From the project directory:

        vagrant ssh -c 'cd /vagrant; make'

Build output goes into the `build` directory.


## License

*   The `tools` directory contains third-party tools, which have their own
    licenses.
*   `src/text.txt` contains text from _The Origin of Species_ by Charles
    Darwin. It is in the Public Domain.
*   Everything else is licensed as follows (the “MIT” license).

Copyright © 2012 Daniel J. Cassidy.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the “Software”), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.


[1]: http://vagrantup.com/
