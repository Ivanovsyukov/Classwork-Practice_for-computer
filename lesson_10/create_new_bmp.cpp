#include <iostream>
#include <fstream>

unsigned char* create_bmp(int weight, int height){
    std::ifstream temp("D:\\program\\Git\\Classwork-Practice_for-computer\\lesson_10\\template.bmp", std::ios_base::in | std::ios_base::binary);
    if (!temp.is_open()){
        std::cout << "temp is not read" << std::endl;
        return nullptr;
    }
    int bite_size=62+int((weight+31)/32)*4*height;
    unsigned char* bmp=new unsigned char[bite_size];
    char s;
    for (int i=0; i<bite_size; ++i){
        if (i<62){
            temp >> s;
            if (i==2){
                unsigned int size_temp=bite_size;
                bmp[i++]=((size_temp&0xFF));
                bmp[i++]=((size_temp&0xFF00)>>8);
                bmp[i++]=((size_temp&0xFF0000)>>16);
                bmp[i]=(size_temp>>24);
                temp.seekg(3, std::ios_base::cur);
            }
            else if (i==18){
                unsigned int weight_temp=weight;
                bmp[i++]=char((weight_temp&0xFF));
                bmp[i++]=char((weight_temp&0xFF00)>>8);
                bmp[i++]=char((weight_temp&0xFF0000)>>16);
                bmp[i]=char(weight_temp>>24);
                temp.seekg(3, std::ios_base::cur);
            } else if (i==22) {
                unsigned int height_temp=height;
                bmp[i++]=char((height_temp&0xFF));
                bmp[i++]=char((height_temp&0xFF00)>>8);
                bmp[i++]=char((height_temp&0xFF0000)>>16);
                bmp[i]=char(height_temp>>24);
                temp.seekg(3, std::ios_base::cur);
            } else {
                bmp[i]=s;
            }
        } else {
            bmp[i]=0;
        }
    }
    for(int i=0; i<bite_size; ++i){
        std::cout<<static_cast<int>(bmp[i])<<" ";
    }
    std::cout << std::endl << static_cast<unsigned int>(bite_size) << " " << bite_size << std::endl;
    temp.close();
    return bmp;
}

void write_bmp(char* name_bmp, unsigned char* bmp_ptr){
    std::ofstream temp1(name_bmp, std::ios_base::out | std::ios_base::binary);
    if (!temp1.is_open()){
        std::cout << "temp1 is not read" << std::endl;
        return;
    }
    unsigned int size=(int(bmp_ptr[5])<<24)|(int(bmp_ptr[4])<<16)|(int(bmp_ptr[3])<<8)|int(bmp_ptr[2]);
    //std::cout << size << std::endl;
    for(int i=0; i<size; ++i){
        temp1 << bmp_ptr[i];
    }
    temp1.close();
}

int main(int argc, char* argv[]){
    /*
    if (argc!=2){
        std::cout << "you work is bad" << std::endl;
        return 2;
    }
    */
    int w, h;
    std::cout << "write weight and height: ";
    std::cin >> w >> h;
    unsigned char *bmp_ptr=create_bmp(w, h);
    if (bmp_ptr==nullptr){
        return 1;
    }
    //write_bmp(argv[1], bmp_ptr);
    std::cout << int(bmp_ptr[2])<< std::endl;
    write_bmp("D:\\program\\Git\\Classwork-Practice_for-computer\\lesson_10\\pic_3.bmp", bmp_ptr);
    delete[] bmp_ptr;
    return 0;
}