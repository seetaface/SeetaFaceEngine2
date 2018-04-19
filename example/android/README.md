## Android documents

> The face recognition SDK call flow for Android

1 First initialize FaceDetector2, use "Detect" interface to detect face location in image

1.1 Initialize FaceDetector2
```java
FaceDetector2 faceDetector = new FaceDetector2(faceDetectorModel);
```

1.2 Use "Detect" interface to detect face location in image
```java
SeetaRect[] faceRects = faceDetector.Detect(image);//make sure SeetaImageData.data in BGR format
```

> Reference: how to get SeetaImageData

```java
public SeetaImageData ConvertToSeetaImageData(String imgPath) {
    Bitmap bmp = BitmapFactory.decodeFile(imgPath);

    Bitmap bmp_src = bmp.copy(Bitmap.Config.ARGB_8888, true); // true is RGBA
    SeetaImageData imageData = new SeetaImageData(bmp_src.getWidth(), bmp_src.getHeight(), 3);
    imageData.data = getPixelsBGR(bmp_src);

    return imageData;
}
public byte[] getPixelsBGR(Bitmap image) {
    // calculate how many bytes our image consists of
    int bytes = image.getByteCount();

    ByteBuffer buffer = ByteBuffer.allocate(bytes); // Create a new buffer
    image.copyPixelsToBuffer(buffer); // Move the byte data to the buffer

    byte[] temp = buffer.array(); // Get the underlying array containing the data.

    byte[] pixels = new byte[(temp.length/4) * 3]; // Allocate for BGR

    // Copy pixels into place
    for (int i = 0; i < temp.length/4; i++) {

        pixels[i * 3] = temp[i * 4 + 2];        //B
        pixels[i * 3 + 1] = temp[i * 4 + 1];    //G
        pixels[i * 3 + 2] = temp[i * 4 ];       //R

    }

    return pixels;
}
```
	
2 Initialize PointDetector2, use "Detect" interface to detect landmarks of target face

2.1 Initialize PointDetector2
```java
PointDetector2 pointDetector = new PointDetector2(pointDetectorModel);
```

2.2 use "Detect" interface to detect landmarks of target face
```java
SeetaPointF[] landmarks = pointDetector.Detect(image, seetaRects[0]);//if seetaRects not empty，seetaRects[0] is maximum face
```

3 Initialize FaceRecognizer2,carry out face register,face recognition or face compare

3.1 Initialize FaceRecognizer2
```java
FaceRecognizer2 faceRecognizer = new FaceRecognizer2(faceRecognizerModel);
```

3.2 Face register
```java
int registedFaceIndex = faceRecognizer.Register(image, landmarks);
```

3.3 Face recognition
```java
float[] similarity = new similarity[1];//save the most similar face similarity value
int targetIndex = faceRecognizer.Recognize(image, landmarks, similarity);//targetIndex is the index of the most similar face in database
```

3.4 Current faces' similarities with registered faces in database
```java
float[] crossSimilarities = faceRecognizer.RecognizeEx(image, landmarks);//crossSimilarities's length is the returned value of MaxRegisterIndex()
```

3.5 Clear registered face database
```java
faceRecognizer.Clear();
```

3.6 Compare two faces
```java
float similarity = faceRecognizer.Compare(image1, landmarks1, image2, landmarks2);
```