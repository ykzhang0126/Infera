#!/bin/bash

cd 3rdparty/tvm-0.16.0
conda env create -f conda/build-environment.yaml
conda activate tvm

conda install numpy decorator attrs xgboost tornado psutil cloudpickle onnx mxnet typing-extensions scipy black
pip3 install tflite env onnxoptimizer gluoncv

cd build && cmake .. && make -j
cd inference_engine/src/cuda_capture && make libinttemp.so && cd ../../
cd inference_engine/src/src/scheduler && make scheduler_eval.so && cd ../../
