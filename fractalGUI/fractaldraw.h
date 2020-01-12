#ifndef FRACTALDRAW_H
#define FRACTALDRAW_H

#include <QMainWindow>

/*
class fractal{
public:
    virtual void draw();
    fractal();
    virtual ~fractal();
};
*/

class fractalDraw //:public fractal
{
public:
    double  zR, zI, maxX, minX, maxY, minY;
    int sizeX, sizeY,max_iter, type, size;
    QImage image;
    fractalDraw(int type, int sizeX, int sizeY, double zR, double zI, int max_iter, double minX, double maxX, double minY, double maxY);
    ~fractalDraw();
    int nFindM(double cr, double ci, int max_iter, double zR, double zI, int n, double r);
    int FindM(double cr, double ci, int max_iter, double zR, double zI);
    double Map(int x, int W, double minR, double maxR);
    void draw() ;
    void nDraw(int N, double R);
private:

};



class MfractalDraw //: public fractal
{

public:
    double  zR, zI, maxX, minX, maxY, minY;
    int sizeX, sizeY,max_iter, type;
    QImage image;
    double map(int x, int W, double minR, double maxR);
    int findM(double cr, double ci, int max_iter);
    MfractalDraw(int  type, int max_iter, int sizeX, int sizeY, double maxX, double minX, double maxY, double minY);
    ~MfractalDraw();
    void draw() ;
private:

};


#endif // FRACTALDRAW_H
