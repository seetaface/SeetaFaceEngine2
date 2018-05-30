package com.seeta.sdk;

public class PointDetector2
{
	static {
		System.loadLibrary("PointDetectorJni");
	}
	public long impl = 0;

	private native void construct(String model);
	public native void dispose();

	/**
	 * \brief construct an pointdetector
	 * \param model model path
	 */
	public PointDetector2(String model) {
		this.construct(model);
	}

	protected void finalize() throws Throwable {
        super.finalize();
		this.dispose();
    }

	/**
	 * \brief get number of landmarks can be detected
	 * \return number of landmarks can be detected
	 */
	public native int LandmarkNum();

	/**
	 * \brief detect points on face
	 * \param image [in] the orignal image
	 * \param face [in] detected face location
	 * \return an array of points, contains each point location, with length of LandmarkNum
	 * \sa LandmarkNum
	 */
	public native SeetaPointF[] Detect(SeetaImageData image, SeetaRect face);

}
