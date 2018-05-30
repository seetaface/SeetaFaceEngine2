package com.seeta.sdk;


public class FaceRecognizer2
{
    static {
        System.loadLibrary("FaceRecognizerJni");
    }

	public long impl = 0;

	private native void construct(String model);
	public native void dispose();

    public FaceRecognizer2() {
        this("");
    }

	/**
	 * \brief construct an facerecognizer
	 * \param model model path
	 */
	public FaceRecognizer2(String model) {
		this.construct(model);
	}

	protected void finalize() throws Throwable {
        super.finalize();
		this.dispose();
    }

	/**
	 * \brief return similarity of two faces
	 * \param image1 [in] the original image of face1
	 * \param landmarks1 [in] the detected landmarks of face1
	 * \param image2 [in] the original image of face2
	 * \param landmarks2 [in] the detected landmarks of face2
	 * \return return similarity of face1 and face2
	 * \note the detected landmarks  must have number of PointDetector2::LandmarkNum
	 * \note return 0 if failed
	 */
	public native float Compare(SeetaImageData image1, SeetaPointF[] landmarks1, 
								SeetaImageData image2, SeetaPointF[] landmarks2);

	/**
	 * \brief register faces to database, return the index of registered face
	 * \param image [in] the original image of face
	 * \param landmarks [in] the detected landmarks of face
	 * \return index of registered face
	 * \note the detected landmarks  must have number of PointDetector2::LandmarkNum
	 * \note return -1 if faild.
	 */
	public native int Register(SeetaImageData image, SeetaPointF[] landmarks);

	/**
	 * \brief clear all registered face
	 */
	public native void Clear();

	/**
	 * \brief get the number of registerd faces
	 * \return the number of registerd faces
	 */
	public native int MaxRegisterIndex();

	/**
	 * \brief recognize the given face from database, return the most similar face's index
	 * \param image [in] the original image of face
	 * \param landmarks [in] the detected landmarks of face
	 * \param similarity [out] the most similarity , note similarity must be one length array of float
	 * \return the most similar face's index
	 * \note return -1 if faild.
	 * \sa Register
	 */
	public native int Recognize(SeetaImageData image, SeetaPointF[] landmarks, float[] similarity);

	/**
	 * \brief recognize the given face from database, return each similarity of database
	 * \param image [in] the original image of face
	 * \param landmarks [in] the detected landmarks of face
	 * \return an array of similarity, with length MaxRegisterIndex
	 * \note using index returned by Register to get exact face's similarity
	 * \sa Register
	 * \sa MaxRegisterIndex
	 */
	public native float[] RecognizeEx(SeetaImageData image, SeetaPointF[] landmarks);

}
