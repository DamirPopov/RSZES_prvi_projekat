#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <regex>
#include <fstream>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

#define MAX_PKT_SIZE (640*480*4)

using namespace std;

//comment to send pixels as commands via regular write function of char driver
//leave uncommented to write directly to memory (faster)

int Boja (char *boja, int boja_vr){
        if (boja.compare("RED")==0)
                boja_vr=0xF800;
        else if (boja.compare("GREEN")==0)
                boja_vr=0x07E0;
        else if (boja.compare("BLUE")==0)
                boja_vr=0x001F;
        else if (boja.compare("YELLOW")==0)
                boja_vr=0xFFE0;
        else if (boja.compare("BLACK")==0)
                boja_vr=0x0000;
        else if (boja.compare("WHITE")==0)
                boja_vr=0xFFFF;

        return boja_vr;
}

int main(int argc, char** argv)
{

        int boja_vr;
        std::string line;
        int brojac = 0;
        if(argc<2){
                std::cout << "Please enter config file path\n";
                return -1;
        }
        else
        {
                std::fstream infile;
                infile.open(argv [1]);
        }


        while(getline(infile,line)) {

        regex line_reg("(BCKG|LINE_H|LINE_V|RECT):\\s*");
        smatch m;
        cout<<m[1]<<endl;
        if(m[1].compare("BCKG")==0){
                regex bckg("(\\w+)\\s*$");
                smatch b;
                Boja(b[1], boja_vr);
                stanje=1;
        }

        if(m[1].compare("LINE_H")==0){
                regex line_h("(\\d+),\\s*(\\d+),\\s*(\\d+);\\s*(\\w+)\\s*$");
                smatch lh;
                x1=lh[1];
                x2=lh[2];
                y=lh[3];
                Boja(lh[4], boja_vr);
        }

        if(m[1].compare("LINE_V")==0){
                regex line_v("(\\d+),\\s*(\\d+),\\s*(\\d+);\\s*(\\w+)\\s*$");
                smatch lv;
                x=lv[1];
                y1=lv[2];
                y2=lv[3];
                Boja(lv[4], boja_vr);
        }

        if(m[1].compare("RECT")==0){
                regex rect("(\\d+),\\s*(\\d+),\\s*(\\d+),\\s*(\\d+);\\s*(\\w+)\\s*$");
                smatch r;
                x1=r[1];
                x2=r[2];
                y1=r[3];
                y2=r[4];
                Boja(r[5], boja_vr);
        }

       /* int x,y;
        int x1=100;
        int x2=200;
        int y1=10;
        int y2=30;
        int bckg = 0x0000;
        int x_r1= 400;
        int x_r2= 600;
        int y_r1= 200;
        int y_r2= 400;
        // Send via regualar driver interface

//background
        FILE* fp;
        for(y=0; y<480; y++)
        {
                for(x=0; x<640; x++)
                {
                        fp = fopen("/dev/vga_dma", "w");
                        if(fp == NULL)
                        {
                                printf("Cannot open /dev/vga for write\n");
                                return -1;
                        }
                        fprintf(fp,"%d,%d,%#04x\n",x,y,bckg);
                        fclose(fp);

                        if(fp == NULL)
                        {
                                printf("Cannot close /dev/vga\n");
                                return -1;
                        }
                }
        }

//horizontal line

        for(x=x1; x<x2; x++){

         fp = fopen("/dev/vga_dma", "w");
                        if(fp == NULL)
                        {
                                printf("Cannot open /dev/vga for write\n");
                                return -1;
                        }
                        fprintf(fp,"%d,%d,%#04x\n",x,y1,0xFFE0);
                        fclose(fp);

                        if(fp == NULL)
                        {
                                printf("Cannot close /dev/vga\n");
                                return -1;
                        }
}

//vertical line

        for(y=y1; y<y2; y++){

         fp = fopen("/dev/vga_dma", "w");
                        if(fp == NULL)
                        {
                                printf("Cannot open /dev/vga for write\n");
                                return -1;
                        }
                        fprintf(fp,"%d,%d,%#04x\n",x1,y,0xFFE0);
                        fclose(fp);

                        if(fp == NULL)
                        {
                                printf("Cannot close /dev/vga\n");
                                return -1;
                        }
}

//rectangle

        for(x=x_r1; x<x_r2; x++){
                for(y=y_r1; y<y_r2; y++){

                 fp = fopen("/dev/vga_dma", "w");
                        if(fp == NULL)
                        {
                                printf("Cannot open /dev/vga for write\n");
                                return -1;
                        }
                                fprintf(fp,"%d,%d,%#04x\n",x,y,0x07E0);
                                fclose(fp);

                        if(fp == NULL)
                        {
                                printf("Cannot close /dev/vga\n");
                                return -1;
                        }
        }
}

*/
}
        return 0;
}



