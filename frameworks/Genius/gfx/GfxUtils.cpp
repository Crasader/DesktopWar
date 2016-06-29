
#include "GfxUtils.h"

USING_NS_CC;

cocos2d::Sprite* GfxUtils::PrintScreen(cocos2d::Texture2D** pTexture)
{
	auto glview = Director::getInstance()->getOpenGLView();

	const cocos2d::Size& visibleSzie = glview->getFrameSize();
	int nWidth = (int)visibleSzie.width;
	int nHeight = (int)visibleSzie.height;
	int bytePerPixel = 4;

	GLubyte *pTempData = NULL;
	Image* pShotImage = new Image();
	do
	{
		pTempData = new GLubyte[nWidth * nHeight * bytePerPixel];

		HDC hDCScreen = GetDC(GetDesktopWindow());
		HBITMAP hBitmap = ::CreateCompatibleBitmap(hDCScreen, nWidth, nHeight);
		HDC hDCMem = CreateCompatibleDC(hDCScreen);
		HBITMAP hOldBitmap = (HBITMAP)::SelectObject(hDCMem, hBitmap);
		::BitBlt(hDCMem, 0, 0, nWidth, nHeight, hDCScreen, 0, 0, SRCCOPY);
		::SelectObject(hDCMem, hOldBitmap);

		BITMAP  bm;
		::GetObject(hBitmap, sizeof(BITMAP), &bm);// 获取位图信息
		DWORD   dwImageSize = bm.bmWidthBytes * bm.bmHeight;
		BITMAPINFOHEADER bih;// 设置位图信息头
		bih.biSize = sizeof(BITMAPINFOHEADER); // 位图信息头尺寸
		bih.biWidth = bm.bmWidth;     // 位图宽度
		bih.biHeight = bm.bmHeight;    // 位图高度
		bih.biBitCount = bm.bmBitsPixel; // 设置每像素所用字节数
		bih.biCompression = BI_RGB;
		bih.biPlanes = 1;
		bih.biSizeImage = dwImageSize;
		bih.biXPelsPerMeter = 0;
		bih.biYPelsPerMeter = 0;
		bih.biClrImportant = 0;
		bih.biClrUsed = 0;
		int ret = GetDIBits(hDCMem, hBitmap, 0, bih.biHeight, pTempData, (BITMAPINFO*)&bih, DIB_RGB_COLORS);
		
		/*glPixelStorei(GL_PACK_ALIGNMENT, 1);
		glReadPixels(0, 0, nSavedBufferWidth, nSavedBufferHeight, GL_RGBA, GL_UNSIGNED_BYTE, pTempData);*/

		pShotImage->initWithRawData(pTempData, nWidth * nHeight * bytePerPixel, nWidth, nHeight, 8);

		// 删除创建的资源
		::DeleteDC(hDCMem);
		::DeleteObject(hBitmap);
		::DeleteDC(hDCScreen);

	} while (0);
	//pShotImage->saveToFile("abc.png");
	CC_SAFE_DELETE_ARRAY(pTempData);

	(*pTexture)->initWithImage(pShotImage);
	CC_SAFE_DELETE(pShotImage);

	Sprite* pScreenShotSprite = Sprite::createWithTexture(*pTexture);
	pScreenShotSprite->setAnchorPoint(Vec2(0.5f, 0.5f));
	cocos2d::Size resolution = glview->getDesignResolutionSize();
	// 缩放至适合屏幕大小
	cocos2d::Size spriteSize = pScreenShotSprite->getContentSize();
	float scale = resolution.width / spriteSize.width;
	pScreenShotSprite->setScaleX(scale);
	pScreenShotSprite->setScaleY(-scale);
	//
	return pScreenShotSprite;
}