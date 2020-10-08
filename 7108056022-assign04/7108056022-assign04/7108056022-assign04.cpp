#include <iostream>
#include <opencv2/opencv.hpp>
#include <fstream>

using namespace std;
using namespace cv;

int main()
{
	Mat img,dst;
	img = imread("Pepper-4.2.07.bmp");
	dst.create(img.size(), img.type());
	namedWindow("input", 1);
	imshow("input", img);

	int height = img.rows;
	int width = img.cols;
	int x = 0, y = 0, h = 0,avg = 0;
	int xb = 0, xg = 0, xr = 0, yb = 0, yg = 0, yr = 0;
	int secret = 0;
	srand(2020);
	ofstream fmap,fbite;
	fmap.open("Pepper_locap.txt");
	fbite.open("Pepper_bitstream.txt");

	for (int i = 0, x = 1; i < height && x < height; i += 2, x += 2)
	{
		for (int j = 0; j < width; j++)
		{
			xb = img.at<Vec3b>(i, j)[0];
			yb = img.at<Vec3b>(x, j)[0];
			xg = img.at<Vec3b>(i, j)[1];
			yg = img.at<Vec3b>(x, j)[1];
			xr = img.at<Vec3b>(i, j)[2];
			yr = img.at<Vec3b>(x, j)[2];
			if (xb >= yb)
			{
				h = xb - yb;
				avg = (xb + yb) / 2;
				secret = rand() % (1 - 0 + 1) + 0;
				int newh = 2 * h + secret;
				int min = 2 * (255 - avg);
				int b = 2 * avg + 1;
				int sition = 0;
				if (min > b)
				{
					min = b;
				}
				if (newh <= min)
				{
					sition = 1;
				}
				else
				{
					newh = 2 * (h / 2) + secret;
					if (newh <= min)
					{
						sition = 2;
					}
					else
					{
						newh = 0;
						sition = 3;
					}
				}
				int add = 0, less = 0;
				int map = 0;
				int bite = 0;
				if (sition == 1)
				{
					if (newh % 2 == 0)
					{
						add = newh / 2;
						less = add;
					}
					else
					{
						add = newh / 2 + 1;
						less = newh / 2;
					}
					xb = avg + add;
					yb = avg - less;
					dst.at<Vec3b>(i, j)[0] = xb;
					dst.at<Vec3b>(x, j)[0] = yb;
					map = 1;
					fmap << map;
				}
				if (sition == 2)
				{
					if (newh % 2 == 0)
					{
						add = newh / 2;
						less = add;
					}
					else
					{
						add = newh / 2 + 1;
						less = newh / 2;
					}
					xb = avg + add;
					yb = avg - less;
					dst.at<Vec3b>(i, j)[0] = xb;
					dst.at<Vec3b>(x, j)[0] = yb;
					map = 0;
					fmap << map;
					if (h % 2 == 0)
					{
						bite = 0;
						fbite << bite;
					}
					else
					{
						bite = 1;
						fbite << bite;
					}
				}
				if (sition == 3)
				{
					map = 0;
					fmap << map;
					dst.at<Vec3b>(i, j)[0] = xb;
					dst.at<Vec3b>(x, j)[0] = yb;
				}
			}
			else
			{
				h = yb - xb;
				avg = (xb + yb) / 2;
				secret = rand() % (1 - 0 + 1) + 0;
				int newh = 2 * h + secret;
				int min = 2 * (255 - avg);
				int b = 2 * avg + 1;
				int sition = 0;
				if (min > b)
				{
					min = b;
				}
				if (newh <= min)
				{
					sition = 1;
				}
				else
				{
					newh = 2 * (h / 2) + secret;
					if (newh <= min)
					{
						sition = 2;
					}
					else
					{
						newh = 0;
						sition = 3;
					}
				}
				int add = 0, less = 0;
				int map = 0;
				int bite = 0;
				if (sition == 1)
				{
					if (newh % 2 == 0)
					{
						add = newh / 2;
						less = add;
					}
					else
					{
						add = newh / 2 + 1;
						less = newh / 2;
					}
					yb = avg + add;
					xb = avg - less;
					dst.at<Vec3b>(i, j)[0] = xb;
					dst.at<Vec3b>(x, j)[0] = yb;
					map = 1;
					fmap << map;
				}
				if (sition == 2)
				{
					if (newh % 2 == 0)
					{
						add = newh / 2;
						less = add;
					}
					else
					{
						add = newh / 2 + 1;
						less = newh / 2;
					}
					yb = avg + add;
					xb = avg - less;
					dst.at<Vec3b>(i, j)[0] = xb;
					dst.at<Vec3b>(x, j)[0] = yb;
					map = 0;
					fmap << map;
					if (h % 2 == 0)
					{
						bite = 0;
						fbite << bite;
					}
					else
					{
						bite = 1;
						fbite << bite;
					}
				}
				if (sition == 3)
				{
					map = 0;
					fmap << map;
					dst.at<Vec3b>(i, j)[0] = xb;
					dst.at<Vec3b>(x, j)[0] = yb;
				}
			}
			if (xg >= yg)
			{
				h = xg - yg;
				avg = (xg + yg) / 2;
				secret = rand() % (1 - 0 + 1) + 0;
				int newh = 2 * h + secret;
				int min = 2 * (255 - avg);
				int b = 2 * avg + 1;
				int sition = 0;
				if (min > b)
				{
					min = b;
				}
				if (newh <= min)
				{
					sition = 1;
				}
				else
				{
					newh = 2 * (h / 2) + secret;
					if (newh <= min)
					{
						sition = 2;
					}
					else
					{
						newh = 0;
						sition = 3;
					}
				}
				int add = 0, less = 0;
				int map = 0;
				int bite = 0;
				if (sition == 1)
				{
					if (newh % 2 == 0)
					{
						add = newh / 2;
						less = add;
					}
					else
					{
						add = newh / 2 + 1;
						less = newh / 2;
					}
					xg = avg + add;
					yg = avg - less;
					dst.at<Vec3b>(i, j)[1] = xg;
					dst.at<Vec3b>(x, j)[1] = yg;
					map = 1;
					fmap << map;
				}
				if (sition == 2)
				{
					if (newh % 2 == 0)
					{
						add = newh / 2;
						less = add;
					}
					else
					{
						add = newh / 2 + 1;
						less = newh / 2;
					}
					xg = avg + add;
					yg = avg - less;
					dst.at<Vec3b>(i, j)[1] = xg;
					dst.at<Vec3b>(x, j)[1] = yg;
					map = 0;
					fmap << map;
					if (h % 2 == 0)
					{
						bite = 0;
						fbite << bite;
					}
					else
					{
						bite = 1;
						fbite << bite;
					}
				}
				if (sition == 3)
				{
					map = 0;
					fmap << map;
					dst.at<Vec3b>(i, j)[1] = xg;
					dst.at<Vec3b>(x, j)[1] = yg;
				}
			}
			else
			{
				h = yg - xg;
				avg = (xg + yg) / 2;
				secret = rand() % (1 - 0 + 1) + 0;
				int newh = 2 * h + secret;
				int min = 2 * (255 - avg);
				int b = 2 * avg + 1;
				int sition = 0;
				if (min > b)
				{
					min = b;
				}
				if (newh <= min)
				{
					sition = 1;
				}
				else
				{
					newh = 2 * (h / 2) + secret;
					if (newh <= min)
					{
						sition = 2;
					}
					else
					{
						newh = 0;
						sition = 3;
					}
				}
				int add = 0, less = 0;
				int map = 0;
				int bite = 0;
				if (sition == 1)
				{
					if (newh % 2 == 0)
					{
						add = newh / 2;
						less = add;
					}
					else
					{
						add = newh / 2 + 1;
						less = newh / 2;
					}
					yg = avg + add;
					xg = avg - less;
					dst.at<Vec3b>(i, j)[1] = xg;
					dst.at<Vec3b>(x, j)[1] = yg;
					map = 1;
					fmap << map;
				}
				if (sition == 2)
				{
					if (newh % 2 == 0)
					{
						add = newh / 2;
						less = add;
					}
					else
					{
						add = newh / 2 + 1;
						less = newh / 2;
					}
					yg = avg + add;
					xg = avg - less;
					dst.at<Vec3b>(i, j)[1] = xg;
					dst.at<Vec3b>(x, j)[1] = yg;
					map = 0;
					fmap << map;
					if (h % 2 == 0)
					{
						bite = 0;
						fbite << bite;
					}
					else
					{
						bite = 1;
						fbite << bite;
					}
				}
				if (sition == 3)
				{
					map = 0;
					fmap << map;
					dst.at<Vec3b>(i, j)[1] = xg;
					dst.at<Vec3b>(x, j)[1] = yg;
				}
			}
			if (xr >= yr)
			{
				h = xr - yr;
				avg = (xr + yr) / 2;
				secret = rand() % (1 - 0 + 1) + 0;
				int newh = 2 * h + secret;
				int min = 2 * (255 - avg);
				int b = 2 * avg + 1;
				int sition = 0;
				if (min > b)
				{
					min = b;
				}
				if (newh <= min)
				{
					sition = 1;
				}
				else
				{
					newh = 2 * (h / 2) + secret;
					if (newh <= min)
					{
						sition = 2;
					}
					else
					{
						newh = 0;
						sition = 3;
					}
				}
				int add = 0, less = 0;
				int map = 0;
				int bite = 0;
				if (sition == 1)
				{
					if (newh % 2 == 0)
					{
						add = newh / 2;
						less = add;
					}
					else
					{
						add = newh / 2 + 1;
						less = newh / 2;
					}
					xr = avg + add;
					yr = avg - less;
					dst.at<Vec3b>(i, j)[2] = xr;
					dst.at<Vec3b>(x, j)[2] = yr;
					map = 1;
					fmap << map;
				}
				if (sition == 2)
				{
					if (newh % 2 == 0)
					{
						add = newh / 2;
						less = add;
					}
					else
					{
						add = newh / 2 + 1;
						less = newh / 2;
					}
					xr = avg + add;
					yr = avg - less;
					dst.at<Vec3b>(i, j)[2] = xr;
					dst.at<Vec3b>(x, j)[2] = yr;
					map = 0;
					fmap << map;
					if (h % 2 == 0)
					{
						bite = 0;
						fbite << bite;
					}
					else
					{
						bite = 1;
						fbite << bite;
					}
				}
				if (sition == 3)
				{
					map = 0;
					fmap << map;
					dst.at<Vec3b>(i, j)[2] = xr;
					dst.at<Vec3b>(x, j)[2] = yr;
				}
			}
			else
			{
				h = yr - xr;
				avg = (xr + yr) / 2;
				secret = rand() % (1 - 0 + 1) + 0;
				int newh = 2 * h + secret;
				int min = 2 * (255 - avg);
				int b = 2 * avg + 1;
				int sition = 0;
				if (min > b)
				{
					min = b;
				}
				if (newh <= min)
				{
					sition = 1;
				}
				else
				{
					newh = 2 * (h / 2) + secret;
					if (newh <= min)
					{
						sition = 2;
					}
					else
					{
						newh = 0;
						sition = 3;
					}
				}
				int add = 0, less = 0;
				int map = 0;
				int bite = 0;
				if (sition == 1)
				{
					if (newh % 2 == 0)
					{
						add = newh / 2;
						less = add;
					}
					else
					{
						add = newh / 2 + 1;
						less = newh / 2;
					}
					yr = avg + add;
					xr = avg - less;
					dst.at<Vec3b>(i, j)[2] = xr;
					dst.at<Vec3b>(x, j)[2] = yr;
					map = 1;
					fmap << map;
				}
				if (sition == 2)
				{
					if (newh % 2 == 0)
					{
						add = newh / 2;
						less = add;
					}
					else
					{
						add = newh / 2 + 1;
						less = newh / 2;
					}
					yr = avg + add;
					xr = avg - less;
					dst.at<Vec3b>(i, j)[2] = xr;
					dst.at<Vec3b>(x, j)[2] = yr;
					map = 0;
					fmap << map;
					if (h % 2 == 0)
					{
						bite = 0;
						fbite << bite;
					}
					else
					{
						bite = 1;
						fbite << bite;
					}
				}
				if (sition == 3)
				{
					map = 0;
					fmap << map;
					dst.at<Vec3b>(i, j)[2] = xr;
					dst.at<Vec3b>(x, j)[2] = yr;
				}
			}
		}
	}
	ofstream fout, foutt;
	fout.open("Pepper_hist.csv");
	fout << "Pepper" << endl;
	fout << width << "*" << height << "," << "," << "oldRed" << "," << "oldGreen" << "," << "oldBlue" << "," << "newRed" << "," << "newGreen" << "," << "newBlue" << endl;
	fout << "resolution" << "," << "value" << "," << "count" << "," << "count" << "," << "count" << "," << "count" << "," << "count" << "," << "count" << endl;
	foutt.open("Pepper_state.csv");
	foutt << "Pepper" << endl;
	foutt << "PSNR" << "," << "MSE" << endl;
	int countoldB[256] = { 0 };
	int countoldG[256] = { 0 };
	int countoldR[256] = { 0 };
	int countnewB[256] = { 0 };
	int countnewG[256] = { 0 };
	int countnewR[256] = { 0 };
	double MSE = 0, PSNR = 0;
	double size = height * width;
	int total = 0;
	int sum = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int oldB = img.at<Vec3b>(i, j)[0];
			int oldG = img.at<Vec3b>(i, j)[1];
			int oldR = img.at<Vec3b>(i, j)[2];
			int newB = dst.at<Vec3b>(i, j)[0];
			int newG = dst.at<Vec3b>(i, j)[1];
			int newR = dst.at<Vec3b>(i, j)[2];
			countoldB[oldB]++;
			countoldG[oldG]++;
			countoldR[oldR]++;
			countnewB[newB]++;
			countnewG[newG]++;
			countnewR[newR]++;
			sum = pow((oldB - newB),2) + pow((oldG - newG),2) + pow((oldR - newG),2);
			total += sum;
		}
	}
	MSE = total / (size*3) ;
	PSNR = 10 * log10(pow(255, 2) / MSE);
	foutt << PSNR << "," << MSE << endl;
	for (int i = 0; i < 256; i++)
	{
		fout << width * height << "," << i << "," << countoldR[i] << "," << countoldG[i] << "," << countoldB[i] << "," << countnewR[i] << "," << countnewG[i] << "," << countnewB[i] << endl;
	}

	namedWindow("output", 1);
	imshow("output", dst);
	imwrite("Pepper-stego.bmp", dst);
	fmap.close();
	fbite.close();
	fout.close();
	foutt.close();
	waitKey(0);
}