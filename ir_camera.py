
import picamera
import io
import time
import numpy as np
from threading import Condition

with picamera.PiCamera(resolution=(128, 128), framerate=60) as camera:
    camera.rotation = 180
    camera.video_denoise = False
    camera.hflip = True
    camera.color_effects = (128, 128)
    last_time = time.time()
    stream = io.BytesIO()
    for _ in camera.capture_continuous(stream, 'rgb', use_video_port=True):
        try:
            stream.seek(0)
            frame = stream.read()
            img = np.frombuffer(frame, dtype=np.uint8)
            img.tofile('infrared')
            stream.seek(0)
            stream.truncate()
        except:
            print('Could not process image')
