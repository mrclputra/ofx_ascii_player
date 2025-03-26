# ofx_ascii_player
ASCII Video player with real-time shader conversion  
- Convert video to text ASCII art  
- Grayscale based mapping  

<div align="center">
<img src="/bin/data/images/demo1.png" width="400"/>  
<img src="/bin/data/images/demo2.png" width="400"/>  
</div>

Utilizes OpenFrameWorks and ImGUI (WIP)  

Currently working on video selection GUI, for now just place mp4 files in `bin/data/videos/` and call said file in the `ofApp.cpp` setup.  

You can:
- Modify `charSize` to change ASCII resolution  
- Modify grayscale thresholds in fragment shader  

Utilizes long integer to bitmap conversion to map and draw characters  

Original algorithm developed by movAX13h (2013), modified in fragment shader