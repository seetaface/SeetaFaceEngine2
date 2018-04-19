## C++ documents

> Compliant APIs for Windows and Linux C++ usage.

### 1. Face Detection

##### 1.1 Initialize FaceDetector2
```C++
#include <seeta/FaceDetector2.h>
```
```C++
seeta::FaceDetector2 FD("bindata/SeetaFaceDetector2.0.ats");
```
#### 1.2 How to load opencv images

```C++
#include <seeta/Struct_cv.h>
```
```C++
cv::Mat mat = cv::imread("1.jpg");
seeta::cv::ImageData image = mat;
```

#### 1.3 Detect faces and show to console
```C++
int num;    // save the number of detected faces
SeetaRect *face = FD.Detect(image, &num);

for (int i = 0; i < num; ++i, ++face)
{
    std::cout << "Face(" << i << "): " << "(" << face->x << ", " << face->y << ", " << face->width << ", " << face->height << ")" << std::endl;
}
```

### 2. Face Alignment

#### 2.1 Initialize PointDetector2
```C++
#include <seeta/PointDetector2.h>
```
```C++
seeta::PointDetector2 PD("bindata/SeetaPointDetector2.0.pts5.ats");
```

### 2.2 Detect landmarks and show to console
```C++
// assume that face is the returned value of `FD.Detect`
SeetaPointF *points = PD.Detect(image, *face);
if (points)
{
    std::cout << "Points: [" << std::endl;
    for (int j = 0; j < PD.LandmarkNum(); ++j)
    {
        std::cout << "(" << points[j].x << ", " << points[j].y << ")," << std::endl;
    }
    std::cout << "]" << std::endl;
}
```

### 3. Face Identification

#### 3.1 Initialize FaceRecognizer2
```C++
#include <seeta/FaceRecognizer.h>
```
```C++
seeta::FaceRecognizer2 FR("bindata/SeetaFaceRecognizer2.0.ats");
```

#### 3.2 1 vs 1 recognition

Compare similar between `1.jpg` and `2.jpg`.

```C++
cv::Mat mat1 = cv::imread("1.jpg");
seeta::cv::ImageData image1 = mat1;
SeetaRect *face1 = FD.Detect(image1);
SeetaPointF points1[5];
PD.DetectEx(image1, *face1, points1);

cv::Mat mat2 = cv::imread("2.jpg");
seeta::cv::ImageData image2 = mat2;
SeetaRect *face2 = FD.Detect(image2);
SeetaPointF points2[5];
PD.DetectEx(image2, *face2, points2);

float similar = FR.Compare(image1, points1, image2, points2);
// similar should be 0, if `Compare` failed.
```

#### 3.3 1 vs N recognition

##### a. Register faces.

Register faces using function like bellowing. The returned value is the index of face database. Reture -1 if failed.

```C++
int register_image(seeta::FaceDetector2 &FD, seeta::PointDetector2 &PD, seeta::FaceRecognizer2 &FR, const std::string &filename)
{
    cv::Mat mat = cv::imread(filename);
    if (mat.empty()) return -1;
    seeta::cv::ImageData image = mat;
    SeetaRect *face = FD.Detect(image);
    if (!face) return -1;
    SeetaPointF *points = PD.Detect(image, *face);
    if (!points) return -1;
    return FR.Register(image, points);  // Reture -1 if failed.
}
```

##### b. Recognize face and get the most similar face index
```C++
cv::Mat mat = cv::imread("1.jpg");
seeta::cv::ImageData image = mat;
SeetaRect *face = FD.Detect(image);
SeetaPointF *points = PD.Detect(image, *face);

float similar = 0;
int index = FR.Recognize(image, points, &similar);
```
`index` saves the index of face databese, which is same as the retured value by `Register`. `similar` saves the most similar.

##### b. Recognize face and get all faces' similars

``` C++
cv::Mat mat = cv::imread("1.jpg");
seeta::cv::ImageData image = mat;
SeetaRect *face = FD.Detect(image);
SeetaPointF *points = PD.Detect(image, *face);

float *similar = FR.RecognizeEx(image, points);
for (int i = 0; i < FR.MaxRegisterIndex(); ++i)
{
    std::cout << "1.jpg vs. db/" << i + 1 << ".jpg: " << similar[i] << std::endl;
}
```

#### 3.4 Clear face database
```C++
FR.Clear();
```



