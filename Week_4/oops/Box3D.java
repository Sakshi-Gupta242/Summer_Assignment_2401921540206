public class Box3D extends Box {

    double height;

    public Box3D(double l,double b,double h) {

        super(l,b);

        height = h;
    }

    public double volume() {

        return length * breadth * height;
    }

    public static void main(String args[]) {

        Box3D b = new Box3D(10,5,4);

        System.out.println("Area = " + b.area());

        System.out.println("Volume = " + b.volume());
    }
}