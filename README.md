# About
Blog Maker is a simple tool to convert your TXT files into a nice lightweight HTML blog. You are more than welcome to change the layout of your blog. The release is for Windows only, but you can compile `prog.cpp` yourself for other systems.

# Preview
View an example made with Blog Maker [here](https://wlhcode.github.io/blog-maker/example/).

# Content
There should be two folders `css`, `html`, one HTML file `index.html` and two EXE in the root directory of the release. 

## prog.exe
Write your blogs (limited to one each day) in the root directory of the folder, and drag your TXT file into this EXE in order to convert it to HTML format. Note that the first line of each TXT is the title of the blog, while the name of your TXT file is neglected. This EXE can also help make edits to your blog. Just drag the updated TXT to overwrite the old one.

## clear.exe
This tool is for Windows only. It can clear your blog, leaving you a fresh copy of this tool. Wouldn't say much about this.

## favicon.png
This is the favicon for your website. Feel free to edit it.

## css folder
The default style is named `main.css` in this folder. You may change it if you like.

## html folder
Please avoid making edits to this folder directly.

# Usage
## Windows
1. Download the [latest release](https://github.com/wlhcode/blog-maker/releases) and unzip the package.
2. Compose your blog in the root directory of the new folder using a plain TXT editor.
3. Save your TXT file and drag it to `prog.exe`. A new HTML file will be generated in the `html` folder.
4. To remove your blog, please run `clear.exe` and enter `y` in the command prompt.

## Mac OS
1. Download the source code of [here](https://github.com/wlhcode/blog-maker/releases) and unzip the package.
2. Compile `prog.exe` using Xcode or other compilers.
3. Compose your blog in the root directory of the new folder using a plain TXT editor.
4. Save your TXT file and drag it to `prog.exe`. A new HTML file will be generated in the `html` folder.
5. To remove your blog, copy the contents from `html/temp_index_SPARE.txt` to both the files `index.html` and `temp_index.txt`. Remove all HTML files in the directory `html/`.
