
import cv2
PATH = input("Enter a PATH")
image = cv2.imread(PATH)
width = image.shape[1]
height = image.shape[0]
a = [[0]*width]*height
LY = False
for i in range(0,width):
    if (LY != True):

