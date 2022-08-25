## TFLite_CNN_2DOF_Object_Tracking_Arm
A 2DOF robotic arm for locking on any chosen object.
Powered by #mobileNet model and #TensorFlow #Lite running on a raspi3.


### Requirements

**Your SoC device must be compatible with TFLite.**
For more infor visit: https://github.com/tensorflow/examples/tree/master/lite/examples/object_detection/raspberry_pi

#### Arduino

An Arduino board must interface the SoC device, e.g. raspi, with the robotic hardware. Here they interface through serial to compensate with the object position.
Checkout the ino folder for the complete Arduino Code.

### Setup

The default object that the tracker is looking after is a "teddy bear". To modify to to any desigered object, lookup "teddy bear" in TFLite_detection_webcam.py:
```py
...
for i in range(len(scores)):
        object_name = labels[int(classes[i])] # Look up object name from "labels" array using class index
        if ((scores[i] > min_conf_threshold) and (scores[i] <= 1.0)) and object_name == 'teddy bear':
        #if ((scores[i] > min_conf_threshold) and (scores[i] <= 1.0)):
 ...
 ```
Then change the object name with anything else ** from "Sample_TFLite_model/labelmap.txt" ** , e.g. cellphone, keyboard, etc.
