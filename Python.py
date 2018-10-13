import cv2
import numpy as np

face_Cascade= cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

cap=cv2.VideoCapture(0)


while True:
    ret,img = cap.read()
    gray= cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    faces = face_Cascade.detectMultiScale(gray,scaleFactor=1.3,minNeighbors=5,minSize=(30,30))
    for(x,y,w,h) in faces:
        cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2)
        roi_gray = gray[y:y+h,x:x+w]
        roi_color = img[y:y+h,x:x+w]
        cv2.imshow('video',img)
    video_writer = cv2.VideoWriter("output.avi", cv2.VideoWriter_fourcc(*'XVID'), 20, (680, 480))

    k= cv2.waitKey(30) & 0xff
    if k== 27:
            break

while (cap.isOpened()):
    ret, frame = cap.read()
    if ret:
        video_writer.write(frame)
        cv2.imshow('Video Stream', frame)
    else:
        break
cap.release()
cv2.destroyAllWindows()
