#########################################################################
# File Name: convert_lmdb.sh
# Author: jwm
# Created Time: 2018年08月16日 星期四 09时41分25秒
#########################################################################
#!/bin/bash

CAFFE_ROOT=~/caffe

echo "Create train lmdb"
$CAFFE_ROOT/build/tools/convert_imageset --shuffle \
	--resize_height=256 \
	--resize_width=256 \
	/home/jwm/Desktop/caffe/caffe_train/dataset/ \
	./train.txt \
	./train_lmdb
echo "done"
echo "Create test lmdb"
$CAFFE_ROOT/build/tools/convert_imageset --shuffle \
	--resize_height=256 \
	--resize_width=256 \
	/home/jwm/Desktop/caffe/caffe_train/dataset/ \
	./test.txt \
	./test_lmdb
echo "done"
