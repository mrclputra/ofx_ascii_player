# ofx_ascii_player
ASCII Video player with real-time shader conversion
- Convert video to text ASCII art
- Grayscale based mapping
![before](/bin/data/images/demo1.png) 
![after](/bin/data/images/demo2.png)

utilizes OpenFrameWorks and ImGUI (WIP)
currently working on video selection gui, for now just place mp4 files in `bin/data/videos/` and call said file in the `ofApp.cpp` setup.

you can modify `charSize` to change ASCII resolution
you can modify grayscale thresholds in fragment shader

utilizes long integer to bitmap conversion to map and draw characters
original algorithm developed by movAX13h (2013), modified in fragment shader
