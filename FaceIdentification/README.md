## SeetaFace2 Identification

[![License](https://img.shields.io/badge/license-BSD-blue.svg)](../LICENSE)

### Description
SeetaFace2 Identification is designed with Deep Residual Network, which has shown impressive performance for image classification. With the input face size of 256x256, the network inference takes about 100ms for feature extraction per face on I7-CPU, which is a trade-off between accuracy and time cost. The released model is trained with 33 million face images of more than 320K subjects.

### How to run SeetaFace2 Identification (C++)

To detect faces, one should first instantiate an object of `seeta::FaceRecognizer2` and initialize it with path of the model file. Then one can call `Compare` to compare faces. See more details at under links.

### Notice

**SeetaFace2 Identification only support 1 instance in single application.**

**SeetaFace2 Identification only support 10 probes in memory.**

### Documents

* [Android](../example/android/README.md)
* [C++ on Windows/Linux](../example/C++/README.md)

### Downloads

* [Android/Windows/Linux](../attachment/README.md)

### License

SeetaFace2 Identification is released under the [BSD 2-Clause license](../LICENSE).
