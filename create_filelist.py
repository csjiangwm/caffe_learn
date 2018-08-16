#!/usr/bin/env python
# -*- coding: utf-8 -*-

'''
 *             ,%%%%%%%%, 
 *           ,%%/\%%%%/\%% 
 *          ,%%%\c "" J/%%% 
 * %.       %%%%/ o  o \%%% 
 * `%%.     %%%%    _  |%%% 
 *  `%%     `%%%%(__Y__)%%' 
 *  //       ;%%%%`\-/%%%'
 * ((       /  `%%%%%%%' 
 *  \\    .'          | 
 *   \\  /       \  | | 
 *    \\/         ) | | 
 *     \         /_ | |__ 
 *     (___________))))))) 攻城湿 
 * 
 *        ___           __ ____   ____
 *       | | \   ____  / /| |\ \ | |\ \
 *       | |\ \ / / | / / | |\ \ | |\ \ 
 *       | | \ V /| |/ /  | |\ \| | \ \ 
 *     _ | |  \_/ |_|_/   |_|\_\|_| \_\ 
 *    \\ | |
       \ | |
        \_| 
        
   Created Time: 08 15th, 2018
   Revised Time: -------------
   Function: Create train.txt and test.txt for caffe training and testing
'''

import os

cur_path = os.getcwd()

if os.path.exists('train.txt'):
    os.remove('train.txt')

train_dir = 'dataset/train'
nrof_imgs_per_class = 40
img_names = os.listdir(train_dir)
img_names.sort()
with open('train.txt','w') as f:
    for index,img_name in enumerate(img_names):
        f.write(os.path.join('train',img_name) + ' ' + str(index/nrof_imgs_per_class) + '\n')
        
if os.path.exists('test.txt'):
    os.remove('test.txt')      
test_dir = 'dataset/test'
nrof_imgs_per_class = 20
img_names = os.listdir(test_dir)
img_names.sort()
with open('test.txt','w') as f:
    for index,img_name in enumerate(img_names):
        f.write(os.path.join('test',img_name) + ' ' + str(index/nrof_imgs_per_class) + '\n')
