#include <easyx.h>

class BUTTON {
	public:
		BUTTON(int a, int b, int len, int wid, const TCHAR str[]) {
			x = a;
			y = b;
			length = len;
			width = wid;
			text = LPCTSTR(str);
			RECTANGLE = { x, y, x + length - 1, y + width - 1 };
		}
		void GetButton() {
			setlinecolor(WHITE);
			setfillcolor(RGB(150, 150, 150));
			fillrectangle(x, y, x + length - 1, y + width - 1);
			setbkmode(TRANSPARENT);
			drawtext(text, &RECTANGLE, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			MOUSEMSG Temp;
			do {
				Temp = GetMouseMsg();
				if (Temp.mkLButton) {
					if (Temp.x >= x && Temp.x <= x + length - 1 && Temp.y >= y && Temp.y <= y + width - 1) {
						setlinecolor(BLACK);
						setfillcolor(RGB(98, 98, 98));
						fillrectangle(x, y, x + length - 1, y + width - 1);
						Beep(900, 50);
						return;
					}
				}
				//FlushMouseMsgBuffer();
				Sleep(15);
			} while (1);
		}
	private:
		int x;
		int	y;
		int length;
		int width;
		LPCTSTR text;
		RECT RECTANGLE;
};