// Menu driven program using class to display areas of various shapes

#include<cstdio>
// class for calculating area
class Shape {
    private:
    float length,breadth,height;

    public:
    
    Shape (){
        length=0.0;
        breadth=0.0;
        height=0.0;
    }
    void get_length(){
        printf("Enter the length: \n");
        scanf("%f",&length);
    }
    void get_breadth(){
        printf("Enter the breadth: \n");
        scanf("%f",&breadth);
    }
    void get_height(){
        printf("Enter the height: \n");
        scanf("%f",&height);
    }

    void SquareArea(){
        get_length();
        printf("The area of the square is %f\n",length*length);
    }

    void CubeArea(){
        get_length();
        printf("The area of the cube is %f\n",length*length*6);
    };
    void RectangleArea(){
        get_length();
        get_breadth();
        printf("The area of the rectangle is %f\n",length*breadth);
    };

    void CuboidArea(){
        get_length();
        get_breadth();
        get_height();

        printf("The area of the cuboid is %f\n",2*(length*breadth+breadth*height+length*height));
    };




};
int main(){
    Shape shape1;
    int option;
    //The Menu 
    while(1){
        printf("\n Menu:\n");
        printf("1.Square\n");
        printf("2.Cube\n");
        printf("3.Rectangle\n");
        printf("4.Cuboid\n");
        printf("5.Exit\n");

        scanf("%d",&option);
        switch(option){
            case 1:
            shape1.SquareArea();
            break;

            case 2:
            shape1.CubeArea();
            break;

            case 3:
            shape1.RectangleArea();
            break;

            case 4:
            shape1.CuboidArea();
            break;

            case 5:
            printf("exiting the menu ");
            return 0;

            default:
            printf(" Invalid choice");
        
        }

    }
    return 0;
}