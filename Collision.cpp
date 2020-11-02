#include "Collision.h"
#include "GameMap.h"

void Collision::collision(bool flag, Person& p, sf::String Map[])
{

	for (int i = p.getRectTop() / 16; i < (p.getRectTop() + p.getRectHeight()) / 16; i++)
		for (int j = p.getRectLeft() / 16; j < (p.getRectLeft() + p.getRectWidth()) / 16; j++)
		{
			if ((Map[i][j] == '0') || (Map[i][j] == '0') || (Map[i][j] == '0') || (Map[i][j] == '0') || (Map[i][j] == '0')) //���� �������� ���, ��� ���� �������� ������, ������� �����
			{                                                                                                                              //"������" � ������ � ���������� ����� � ����� �����
				if (p.getY() > 0 && flag == 1)                                                                                             //��� ���������� � ����������
				{                                                                                                           //upd. ����� ���������� ����������, ���� ������ ������� � sf:String
					p.setRectTop(i * 16 - p.getRectHeight());
					p.getY() = 0;
					p.setOnGround(true);
				}
				if (p.getY() < 0 && flag == 1)
				{
					p.setRectTop(i * 16 + 16);
					p.getY() = 0;
				}
				if (p.getX() > 0 && flag == 0)
				{
					p.setRectLeft(j * 16 - p.getRectWidth());
				}
				if (p.getX() < 0 && flag == 0)
				{
					p.setRectLeft(j * 16 + 16);
				}
			}
		}
}