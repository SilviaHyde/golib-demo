# How to compile

Compile with `g++`. Refer to `liblink_ffmpeg_gcc.bat` for details.

# FFmpeg development files

[FFmpeg official site](http://www.ffmpeg.org/download.html)

Dev files for Windows: (size 601 KB)
```
https://ffmpeg.zeranoe.com/builds/win64/dev/ffmpeg-4.2.2-win64-dev.zip
```

Libs for `g++` switches `-L` and `-l`:
```
ffmpeg-4.2.2-win64-dev\lib\avcodec.lib
ffmpeg-4.2.2-win64-dev\lib\avdevice.lib
ffmpeg-4.2.2-win64-dev\lib\avfilter.lib
ffmpeg-4.2.2-win64-dev\lib\avformat.lib
ffmpeg-4.2.2-win64-dev\lib\avutil.lib
ffmpeg-4.2.2-win64-dev\lib\postproc.lib
ffmpeg-4.2.2-win64-dev\lib\swresample.lib
ffmpeg-4.2.2-win64-dev\lib\swscale.lib
```

Path to headers for `g++` switch `-I`:
```
ffmpeg-4.2.2-win64-dev\include\
```

# FFmpeg runtime files

Shared version with separated DLLs is needed.

For Windows: (size 25 MB)
```
https://ffmpeg.zeranoe.com/builds/win64/shared/ffmpeg-4.2.2-win64-shared.zip
```

Our interface lib will depend on DLLs in
```
ffmpeg-4.2.2-win64-shared\bin\
```