# Learn how to use caffe to train my own dataset

## 1. Prepare your dataset
```bash
python create_filelist.py
```
## 2. Generate lmdb
```bash
chmod +x convert_lmdb.sh
./convert_lmdb.sh
```
## 3. Compute mean values
```bash
chmod +x compute_mean_values.sh
./compute_mean_values.sh
```
## 4. Create the model and write prototxt
```Bash
sudo cp ~/caffe/examples/cifar10/cifar10_quick_train_test.prototxt .
sudo cp ~/caffe/examples/cifar10/cifar10_quick_solver.prototxt .
sudo vim solver.prototxt       # revise
sudo vim train_val.prototxt    # revise
```
## 5. Train and valid
```Bash
sudo ~/caffe/build/tools/caffe train -solver ./cifar10_quick_solver.prototxt 
```

## 6. Test
```Bash
mkdir build
cd build/
cmake ..
make -j8
./Image_Test_01 ../cifar10_test.prototxt ../yourcaffemodel ../dataset/test/300.jpg ../test.txt
```

