#include <stdio.h>

class area{
    private:
    int length;
    int breadth;
    int height;

    public:
    area(int l,int b , int h)
    {
        length=l;
        breadth=b;
        height=h;
    }
    void square()
    {
        printf("Area of Square:%d sq units\n",length*length);
    }
    void cube()
    {
        printf("Area of Cube:%d sq units\n",6*length*length);
    }
    void rectangle()
    {
        printf("Area of Rectangle:%d sq units\n",length*breadth);
    }
    void cuboid()
    {
        printf("Area of Rectangle:%d sq units\n",2*((length*breadth)+(breadth*height)+(length*height)));
    }

};

int main(){
    int l,b,h;
    printf("Enter the length:");
    scanf("%d",&l);
    printf("Enter the breadth:");
    scanf("%d",&b);
    printf("Enter the height:");
    scanf("%d",&h);

    area obj(l,b,h);

    int ch;
    printf("Menu:\n1:Square\n2:Cube\n3:Rectangle\n4:Cuboid\n5:Exit");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    while(ch!=5)
    {
        switch(ch)
        {
            case 1:
                obj.square();
                break;
            case 2:
                obj.cube();
                break;
            case 3:
                obj.rectangle();
                break;
            case 4:
                obj.cuboid();
                break;
        }
        printf("Menu:\n1:Square\n2:Cube\n3:Rectangle\n4:Cuboid\n5:Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
    }
}
