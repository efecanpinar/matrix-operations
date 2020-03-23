#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;
int main()
{
	int boyut;
	int e = 0;
	int f = 0;
	int tersSutun;
	int temp;
	int tekSatir[25];
	int tekSayi;
	int count = 0;
	int i, j;
	int satir, sutun, arsatir[25], arsutun[25];
	int matris[25][25];

	cout << "Matrisin boyutunu giriniz: ";
	cin >> boyut;

	while (boyut > 25 || boyut < 5)//Matris boyutunun doğruluğunu kontrol ediyor.
	{
		cout << "Yanlis boyut girdiniz, 5 ile 25 arasinda olmalidir, tekrar dene...: ";
		cin >> boyut;
	}

	cout << setw(4);

	for (int a = 1; a <= boyut; a++)//Matris düzeni
	{
		cout << a << " ";
	}

	cout << endl;
	cout << setw(4);

	for (int b = 0; b <= boyut + 10; b++)//Matris düzeni
	{
		cout << "_";
	}

	cout << endl;

	for (int i = 0; i < boyut; i++)//Matris düzeni
	{
		cout << i + 1 << "|";

		for (int j = 0; j < boyut; j++)
		{

			matris[i][j] = rand() % 10;
			cout << " " << matris[i][j];
		}

		cout << endl;
	}
	cout << "1.Sutun Satir Degistir" << endl << "2.Tekleri Basa Al(Satir)" << endl << "3.Ters Cevir(Sutun)" << endl << "4.Toplamlari Yazdir" << endl;
	int secim;
	cin >> secim;
	while (secim < 1 || secim > 4)//Seçimin doğru aralıkta olup olmadığını kontrol ediyor.
	{
		cout << "Yanlis deger girdiniz, tekrar deneyiniz...: ";
		cin >> secim;
	}
	switch (secim)
	{
	case 1:
		cout << "satir sutun: ";
		cin >> satir;
		cin >> sutun;
		while (satir > boyut || sutun > boyut)//Girilen satır ve sütun değerlerinin doğruluğu kontrol ediliyor.
		{
			cout << "Yanlis deger girdiniz, satir sutun: ";
			cin >> satir;
			cin >> sutun;
		}
		for (i = 0; i < boyut; i++)//Satırı düzenliyor
		{
			arsatir[i] = matris[satir - 1][i];
		}
		for (i = 0; i < boyut; i++)
		{
			arsutun[i] = matris[i][sutun - 1];//Sütunu düzenliyor
		}
		for (i = 0; i < boyut; i++) //Sütun satır değerleri düzenleniyor
		{
			matris[satir - 1][i] = arsutun[i];
			matris[i][sutun - 1] = arsatir[i];
		}
		for (int i = 0; i < boyut; i++)	//Sütun satır değerleri düzenleniyor
		{
			for (int j = 0; j < boyut; j++) //Sütun satır değerleri düzenleniyor
			{
				matris[satir - 1][sutun - 1] = arsatir[satir - 1] + arsutun[sutun - 1];
				cout << matris[i][j] << " ";

			}
			cout << endl;
		}break;

	case 2:
		cout << "satir numarasi...: ";
		cin >> tekSayi;
		while (tekSayi > boyut)//Girilen satır değerinin doğruluğunu kontrol ediyor.
		{
			cout << "Yanlis deger girdiniz. Satir numarasi...: ";
			cin >> tekSayi;
		}
		for (i = 0; i < boyut; i++)//Satırı düzenliyor
		{
			tekSatir[i] = matris[tekSayi - 1][i];
		}
		while (e < boyut && f < boyut) //Boyut değerine kadar döngüye alıyor
		{
			if (tekSatir[f] % 2 != 0)//Tek sayıları biriktiriyor
			{
				f++;
			}
			else//Değerleri geçici değişkende biriktiriyor.
			{
				temp = tekSatir[e];
				tekSatir[e] = tekSatir[f];
				tekSatir[f] = temp;
			}
			e++;
		}
		for (i = 0; i < boyut; i++)//Satırı tek boyutlu diziye aktarıyor.
		{
			matris[tekSayi - 1][i] = tekSatir[i];
		}
		for (int i = 0; i < boyut; i++)
		{
			for (int j = 0; j < boyut; j++)
			{
				cout << matris[i][j] << " ";
			}
			cout << endl;
		}break;
	case 3:
		int tempArray[25];

		cout << "Bir sutun seciniz...: ";
		cin >> tersSutun;

		while (tersSutun > boyut || tersSutun < 1)//Sütun ve satır boyutlarının doğruluğunu kontrol ediyor
		{
			cout << "Hatali sutun degeri girdiniz. Tekrar giriniz." << endl;
			cin >> tersSutun;
		}

		for (int i = 0; i < boyut; i++)//Sütun değerini düzenliyor.
		{
			tempArray[i] = matris[i][tersSutun - 1];
		}

		for (int i = 0, j = boyut - 1; i < boyut; i++, j--)//Sütunu başka bir değişkene topluyor.
		{
			matris[i][tersSutun - 1] = tempArray[j];
		}

		for (int i = 0; i < boyut; i++)//Matrisi yazdırıyor.
		{
			for (int j = 0; j < boyut; j++)
			{
				cout << " " << matris[i][j];
			}
			cout << endl;
		}
		break;
	case 4:
		for (int i = 0; i < boyut; i++)//Matrisi yazıdıyor.
		{
			for (int j = 0; j < boyut; j++)//Matrisi yazıdıyor.
			{
				count += matris[i][j];
			}
		}
		count = count - matris[0][0];
		matris[0][0] = count;
		cout << matris[0][0] << " ";

		for (int i = 0; i < boyut; i++)//Matrisi yazıdıyor.
		{
			for (int j = 0; j < boyut; j++)//Matrisi topluyor.
			{
				if (!(i == 0 && j == 0)) {
					count = count - matris[i][j];
					matris[i][j] = count;
					cout << matris[i][j] << " ";
				}
			}cout << endl;
		}break;
	}
}