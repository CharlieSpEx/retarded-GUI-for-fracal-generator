#include "fractaldraw.h"
#include "math.h"


double fractalDraw::Map(int x, int W, double minR, double maxR){
    double range = maxR - minR;
    return x*(range/W)+minR;
}

int fractalDraw::FindM(double cr, double ci, int max_iter, double zR, double zI){
    int i =0;
    while(i<max_iter && cr*cr+ci*ci < 4.0){
        double temp = cr*cr -ci*ci +zR;
        ci =2*cr*ci +zI;
        cr = temp;
        i++;
    }
    return i;
}
int fractalDraw::nFindM(double cr, double ci, int max_iter, double zR, double zI, int n, double r){
    int i =0;
    while(i<max_iter && cr*cr+ci*ci < r*r){
        double temp = pow(cr*cr -ci*ci, n/2)*cos(n*atan2(ci,cr)) +zR;
        ci =pow(cr*cr+ci*ci, n/2)*sin(n*atan2(ci,cr)) +zI;
        cr = temp;
        i++;
    }
    return i;
}

fractalDraw::fractalDraw(int type, int sizeX, int sizeY, double zR, double zI, int max_iter, double minX, double maxX, double minY, double maxY){

    this->type = type;
    this->max_iter = max_iter;
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    this->zR = zR;
    this->zI = zI;
    this->minX = minX;
    this->maxX = maxX;
    this->minY = minY;
    this->maxY = maxY;
    image = QImage(sizeX, sizeY, QImage::Format_RGB32  );
}

void fractalDraw::draw(){
    for (int l= -sizeX/2; l<sizeX/2; l++){
        for (int c= -sizeY/2; c<sizeY/2; c++){

            double cr = Map(l, sizeX, minX, maxX);
            double ci = Map(c, sizeY, minY, maxY);

            int iter = FindM(cr,ci,max_iter, zR, zI);

            int r;
            int g;
            int b ;

            switch(type) {
                case 0:
                    r = (iter +cr*cr + ci*ci);
                    g = iter*iter%255;
                    b = (cr*cr+ci*ci)*(iter%255);
                break;
                case 1:
                    r = iter%255+cr*cr + ci*ci ;
                    g = iter*iter%255+cr*cr + ci*ci;
                    b = iter*iter*iter%255+cr*cr + ci*ci;
                break;
            case 2:
                    r = cr*ci*cr*ci+iter%255;
                    g = 0;//log(cr*iter);
                    b = 0;//map(ci* cr*3.14, sizeX, 0, 255) ;
                break;
            case 3:
                r = cos(iter*0.0145 + 12.345)*127.5 + 127.5;//(1+sin(0.012*log(iter) + 2.14))*127.5 + 125.5;
                g = sin(0.002*iter*iter*iter)*127.5 + 127.5;//(1-cos(0.042*iter + 1.234))*127.5;//((1/2)+atan2(0.032*iter + 1.124, 1/iter))*127.5 + 125.5;;
                b = 127.5*(1-sin((iter/13400) +5.654346));//(atan2(pow(2.7321, iter*0.012),1)+sin(0.045*iter))*255/1.6;//(1-cos(0.042*iter + 1.234))*127.5;
                break;
            case 4:
                r= sin(0.01234*iter + 0.23)*127.5 + 127.5;
                g =255-sin(iter*0.0077*cos(iter)+0.9)*127.5 +127.5;
                b =cos(0.045 * iter + 0.011)*127.5 + 127.5;
                break;
            case 5:
                r= sin(0.01234*iter + 0.0123)*(iter*2%127) + 27.5;
                g =sin(0.003234*iter + 0.423)*(iter%127) + 50;
                b =sin(0.05234*iter + 0.0723)*(iter*2%127) + 127.5;
                break;
            default:
                r = iter*iter%255;
                g = iter*iter%255;
                b = iter*iter*iter%255;
                break;
            }
            if(iter==max_iter){
                r = 0;
                g = 0;
                b = 0;
            }
            image.setPixel(sizeX/2+l, sizeY/2+c, qRgb(r,g,b));
        }
        }
}

fractalDraw::~fractalDraw(){

}
