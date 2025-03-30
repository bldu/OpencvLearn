Put thirdparty libs here.

## opencv
Compile opencv source code and install in path, e.g. /path/to/opencv. ~~To resolve the dependences between the opencv shared libraries,~~ do one of the following things:

- soft link opencv to ./thridparty/opencv.
```shell
ln -s /path/to/opencv ./thirdparty/opencv
```

- Copy installed opencv to ./thridparty/opencv. Specify the `LD_LIBRARY_PATH`
```shell
LD_LIBRARY_PATH=./thirdparty/opencv/lib:$LD_LIBRARY_PATH your_command
```
