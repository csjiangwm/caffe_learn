#########################################################################
# File Name: compute_mean_values.sh
# Author: jwm
# Created Time: 2018年08月16日 星期四 10时27分15秒
#########################################################################
#!/bin/bash
CAFFE_ROOT=~/caffe
$CAFFE_ROOT/build/tools/compute_image_mean ./train_lmdb ./mean.binaryproto
