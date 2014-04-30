"""
A test script or pybgs.

Good performance: MixtureOfGaussianV2BGS
"""
from setup import *

import pybgs
import cv2

cam = cv2.VideoCapture(0)
i = cam.read()[1]
SHAPE = i.shape

global cur_bgs_name, cur_bgs_ind
bgs_names = pybgs.BGSUCharC3.get_bgs_names()
cur_bgs_ind = 0
cur_bgs_name = ""
 
def get_next_bgs():
    global cur_bgs_name, cur_bgs_ind
     
    cur_bgs_name = bgs_names[cur_bgs_ind]
    cur_bgs_ind = (cur_bgs_ind+1) % len(bgs_names) 
    
    return  pybgs.BGSUCharC3(SHAPE[0], SHAPE[1], cur_bgs_name)

bgs = get_next_bgs()

key = cv2.waitKey(1)
while key != ord('q'):
    # read image and parse bg subtraction
    i = cam.read()[1]
    o = bgs.process(i)
    
    # show reults
    cv2.imshow("Input", i)
    cv2.imshow("%s Mask" % cur_bgs_name, o[:, :, 0])

    key = cv2.waitKey(1)
    
    if key == ord(' '):
        cv2.destroyWindow("%s Mask" % cur_bgs_name)
        bgs = get_next_bgs()

cv2.destroyAllWindows()
