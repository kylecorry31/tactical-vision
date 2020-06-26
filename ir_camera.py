
import picamera
import io
from PIL import Image
import time
import numpy as np
from threading import Condition
import cv2

class StreamingOutput(object):
    def __init__(self):
        self.frame = None
        self.buffer = io.BytesIO()
        self.condition = Condition()

    def write(self, buf):
        if buf.startswith(b'\xff\xd8'):
            self.buffer.truncate()
            with self.condition:
                self.frame = self.buffer.getvalue()
                self.condition.notify_all()
            self.buffer.seek(0)
        return self.buffer.write(buf)

with picamera.PiCamera(resolution=(128, 128), framerate=60) as camera:
    camera.rotation = 180
    camera.hflip = True
    stream = StreamingOutput()
    last_time = time.time()
    camera.start_recording(stream, format='mjpeg', quality=100)
    try:
        while True:
            with stream.condition:
                stream.condition.wait()
                frame = stream.frame
                npframe = np.frombuffer(frame, dtype=np.uint8)
                if len(npframe):
                    pil_frame = cv2.imdecode(npframe, cv2.IMREAD_COLOR)
                    pb = pil_frame.flatten()
                    pb.tofile('infrared')
                    last_time = time.time()
    finally:
        pass

