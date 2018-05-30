package com.seeta.sdk;


public class FaceDetector2
{
	static {
		System.loadLibrary("FaceDetectorJni");
	}

	public long impl = 0;

	private native void construct(String model);
	public native void dispose();

	/**
	 * \brief construct an facedetector
	 * \param model model path
	 */
	public FaceDetector2(String model) {
		this.construct(model);
	}


	protected void finalize() throws Throwable {
        super.finalize();
		this.dispose();
    }

	/**
	 * \brief detect faces
	 * \param image [in]
	 * \return an array of rectangle, contains each faces location
	 * \note return 0 length array if no face detected
	 * \note faces were sorted by width * length
	 */
	public native SeetaRect[] Detect(SeetaImageData img);
	
}
