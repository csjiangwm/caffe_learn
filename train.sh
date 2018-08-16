#########################################################################
# File Name: train.sh
# Author: jwm
# Created Time: 2018年08月16日 星期四 13时03分15秒
#########################################################################
#!/bin/bash
~/caffe/build/tools/caffe train -solver ./cifar10_quick_solver.prototxt
