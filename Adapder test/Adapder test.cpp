// Adapder pattern


#include "stdafx.h"
#include <iostream>
using namespace std;

//��ѹת����
class VoltageConveter
{
public:
	VoltageConveter() { cout << " VoltageConveter constructor " << endl; }
	void bindInputVoltage(int voltage) {}
	void adjustVoltage(int rate) {}
private:
	int m_voltage;
};

//��ɫ��
class ColourLight
{
public:
	ColourLight() { cout << " ColourLight constructor " << endl; }
	void setColorType(int color) {}
private:
	int m_colorType;
};

//��������
class BrightAdapter : public ColourLight, public VoltageConveter
{
public:
	BrightAdapter() { cout << " BrightAdapter constructor " << endl; }
	void setLightness() {}
	int getLightness() {}
private:
	int m_lightness;
};

int main()
{
	BrightAdapter ba;
    return 0;
}

