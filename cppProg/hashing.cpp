#import <iostream>
#import <set>

using namespace std;



class ZipCode
{
public:
    int zipcode;

    ZipCode(int z){
        zipcode = z;
    }

    bool operator<(const ZipCode other) const{
        return this->zipcode < other.zipcode;
    }

};

int main()
{
    set<ZipCode> lookup;
    lookup.insert(ZipCode(98001));
    lookup.insert(ZipCode(98001));


    for(auto zp : lookup)
    {
        std::cout<<"zipcode:: "<<zp.zipcode<<endl;
    }

    return 0;
}
