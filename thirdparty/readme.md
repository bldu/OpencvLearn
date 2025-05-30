Put thirdparty libs here.

## opencv
### Linux

Compile opencv source code and install in path, e.g. /path/to/opencv. ~~To resolve the dependences between the opencv shared libraries,~~ In order to run compiled executable with shared libraries correctly configured, do one of the following options:

- soft link opencv to ./thridparty/opencv.
```shell
ln -s /path/to/opencv ./thirdparty/opencv
```

- Copy installed opencv to ./thridparty/opencv. Specify the `LD_LIBRARY_PATH`
```shell
LD_LIBRARY_PATH=./thirdparty/opencv/lib:$LD_LIBRARY_PATH your_command
```

### Windows
set `OpenCV_DIR` to the path `/path/to/opencv/build` in CMakeLists.txt.

